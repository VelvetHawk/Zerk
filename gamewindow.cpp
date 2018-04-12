#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <QStackedWidget>
#include <QDebug>
#include <talkdialog.h>

GameWindow::GameWindow(QStackedWidget *parent) : QWidget(parent),
	ui(new Ui::GameWindow), game(nullptr), window(parent)
{
	ui->setupUi(this);

	// connect(ui->Quit, SIGNAL(clicked()), parentWidget(), SLOT(show()));
	qDebug() << "GameWindow constructor called";
	qDebug() << ((game == nullptr)? "Game is a nullptr" : "Game is not nullptr");
}

GameWindow::~GameWindow()
{
	delete ui;
	qDebug() << "UI deleted";
	delete game;
	qDebug() << "Scene deleted";

	qDebug() << "GameWindow deleted";
}


void GameWindow::start()
{
	reset_scene();
	game->start();
	display_objects();

	// PROLOGUE
	ui->contentList->addItem(
		"While visiting your grandparents in the countryside over the summer," \
		" you and your grandfather decided to go for a fishing trip on an old" \
		" lake you visted when you were young.\n\nHowever, having accidentally" \
		" forgotten to bring bait, your grandfather went into the woods to " \
		" get some. As evening starts to approach and the sun starts dipping," \
		" you both decide it may be time to finish up. You release the fish back" \
		" into the lake and start packing up.\n\n" \
		" Suddenly, you here a shout from your grandfather by the car. Turns out that" \
		" he has lost his keys! He kindly asks if you could go take a look and find them." \
		" He says that he found a lot of the bait in a small grove. That'll be your best bet" \
		" on where to start looking.\n" \
	);

	ui->contentList->addItem(game->location_string());
	ui->contentList->addItem("What would you like to do?\n");
	update_location_details();
	update_inventory();
}

void GameWindow::set_scene(Scene *scene)
{
	this->game = scene;
}

Scene* GameWindow::get_scene()
{
	return this->game;
}

void GameWindow::clean_ui()
{
	/* Add temp variable to remove
	 * and use delete on
	 */


	qDebug() << "Cleaning UI";
	clean_objects();
	clean_inventory();
	// Console window
	for (int i = ui->contentList->count(); i >= 0; i--)
		delete ui->contentList->item(i);
	ui->contentList->clear();
	qDebug() << "UI cleaned";
}

void GameWindow::clean_objects()
{
	qDebug() << "Cleaning Objects";
	for (int i = ui->ObjectList->topLevelItemCount(); i >= 0; i--)
		delete ui->ObjectList->topLevelItem(i);
	ui->ObjectList->clear();
	qDebug() << "Objects cleaned";
}

void GameWindow::clean_inventory()
{
	qDebug() << "Cleaning inventory";
	for (int i =  ui->Inventory->rowCount(); i >= 0; i--)
		for (int j = ui->Inventory->columnCount(); j > 0; j--)
			delete ui->Inventory->item(i, j);
	ui->Inventory->clear();
	qDebug() << "Inventory cleaned";
}

void GameWindow::reset_scene()
{
	qDebug() << "Resetting scene";
	if (game != nullptr)
	{
		qDebug() << "Calling delete";
		delete game; // Remove old scene
	}
	game = new Scene(); // Reload scene from file
	qDebug() << "Finished resetting scene";
}

void GameWindow::on_North_clicked()
{
	move("Go North", 'N');
}


void GameWindow::on_South_clicked()
{
	move("Go South", 'S');
}


void GameWindow::on_East_clicked()
{
	move("Go East", 'E');
}


void GameWindow::on_West_clicked()
{
	move("Go West", 'W');
}

void GameWindow::move(QString instruction, char direction)
{
	// Print message
	ui->contentList->addItem("> " + instruction);
	// Movement
	QString message = game->go(direction);
	if (!message.isEmpty())
		ui->contentList->addItem(message + "\n");
	else
	{
		// Location info
		ui->contentList->addItem(game->location_string());
		ui->contentList->addItem("What would you like to do?\n");
		// Objects and Items
		display_objects();
		// Change location text/description in box
		update_location_details();
	}
	ui->contentList->scrollToBottom();
}

void GameWindow::display_objects()
{
	// Delete previous objects and clear list
	clean_objects();

	QTreeWidgetItem *temp;
	// Objects
	const QMap<QString, Object *> objects = game->get_current_location()->get_objects();
	for (QMap<QString, Object *>::const_iterator object = objects.begin(); object != objects.end(); object++)
	{
		temp = new QTreeWidgetItem();
		temp->setText(0, object.key());
		ui->ObjectList->addTopLevelItem(temp);
	}
	// Items
	const QMap<QString, Item *> items = game->get_current_location()->get_items();
	for (QMap<QString, Item *>::const_iterator item = items.begin(); item != items.end(); item++)
	{
		if (!item.value()->is_hidden())
		{
			temp = new QTreeWidgetItem();
			temp->setText(0, item.key());
			ui->ObjectList->addTopLevelItem(temp);
		}
	}
}

void GameWindow::update_location_details()
{
	ui->LocationTitle->setText(game->get_current_location()->get_name());
	ui->LocationDescription->setText(game->get_current_location()->get_description());
}

/**
 * This is done like this because if an item is removed/dropped from the inventory,
 * this is to keep consistency and shift all of the items back by one (as anything
 * added to the inventory is appended onto the end)
 */
void GameWindow::update_inventory()
{
	// Delete previous items and clear list
	clean_inventory();

	int row = 0;
	int column = 0;
	const int COLUMN_WIDTH = 4;
	// Empty GUI inventory
	ui->Inventory->clear();
	// 4 columns per row in inventory
	ui->Inventory->setColumnCount(COLUMN_WIDTH);
	// Re-add items
	const QMap<QString, Item *> inventory = game->player->get_items();
	for (QMap<QString, Item *>::const_iterator item = inventory.begin(); item != inventory.end(); item++)
	{
		ui->Inventory->setItem(row, column, new QTableWidgetItem(item.value()->get_name()));
		if (column == COLUMN_WIDTH-1) // Inventory column width of 4
		{
			column = 0; // Move to start of next row
			ui->Inventory->insertRow(row); // Add row
			row++; // Increment to new row
		}
		else
			column++;
	}
}

void GameWindow::on_Take_clicked()
{
	/*
	 * If they try to take an object, have them fail a D19 STR check
	 * where they require 20 to succeed
	 */
	QString name;
	if (!ui->ObjectList->selectedItems().isEmpty())
	{
		name = ui->ObjectList->selectedItems().first()->text(0);
		ui->contentList->addItem("> Take \'" + name + "\'");
		// Check if item selected is an object
		if (game->get_current_location()->get_objects().contains(name))
		{
			int rand = qrand() % 19;
			ui->contentList->addItem("Rolling STR check to take \"" + name + "\"...");
			ui->contentList->addItem("STR check failed: " + QString::number(rand)  + ". 20 needed to pass.\n");
		}
		else // Remove item from location, add to inventory
		{
			game->player->add_item(&(*game->scene_items)[name]); // Add item to player's inventory
			qDeleteAll(ui->ObjectList->selectedItems()); // Remove item from list
			game->get_current_location()->remove_item(name); // Remove item from location
			ui->contentList->addItem(name + " added to inventory.\n"); // Print to console
			/*
			 * ADD FUNCTIONALITY TO DISPLAY IN INVENTORY
			 */
			update_inventory(); // Re-draw inventory on GUI
		}
	}
	else
	{
		ui->contentList->addItem("> Take 'Deep Breath'");
		if (!game->player->has_item("Deep Breath"))
		{
			game->player->add_item(&(*game->scene_items)["Deep Breath"]);
			update_inventory();
			ui->contentList->addItem("You inhale. Deep Breath has been added to inventory\n");
		}
		else
			ui->contentList->addItem("You exhale and take a new deep breath. Deep Breath" \
				" has been added to inventory.\n");
	}
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}

void GameWindow::on_Examine_clicked()
{
	/*
	 * Items within an object (if any) should only be revealed
	 * once an object has been examined
	 */
	QString name;
	if (!ui->ObjectList->selectedItems().isEmpty()) // Check if player has selected anything
	{
		name = ui->ObjectList->selectedItems().first()->text(0);
		ui->contentList->addItem("> Examine \"" + name + "\"");
		// Check if object or item
		if (game->get_current_location()->get_objects().contains(name))
			ui->contentList->addItem(game->get_current_location()->get_object(name)->get_description() + "\n");
		else
			ui->contentList->addItem(game->get_current_location()->get_item(name)->get_description() + "\n");
	}
	else // Cannot catch as exception, because assertion fails if empty
	{
		ui->contentList->addItem("> Examine 'Existence'");
		ui->contentList->addItem("As you ponder about existence, the cosmos, eternity and the meaning of life, you realise" \
			" in a great moment of enlightenment that you haven't actually picked anything physical to examine!\n");
	}
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}

void GameWindow::on_Drop_clicked()
{
	QString name;
	if (!ui->Inventory->selectedItems().isEmpty())
	{
		name = ui->Inventory->selectedItems().first()->text(); // Item name
		// Easter eggs
		ui->contentList->addItem("> Drop '" + name + "'");
		if (name == "Deep Breath")
			ui->contentList->addItem("You exhale. Deep Breath has been removed from your inventory.\n");
		else if (name == "Layer of Dirt")
			ui->contentList->addItem("You dust yourself off. Layer of Dirt has been removed from your inventory.\n");
		else
		{
			// Add item to location list
			game->get_current_location()->add_item(&(*game->scene_items)[name]);
			// Update ObjectList
			QTreeWidgetItem *temp = new QTreeWidgetItem();
			temp->setText(0, name);
			ui->ObjectList->addTopLevelItem(temp);
			// Message
			ui->contentList->addItem(name + " has been removed from your inventory.\n");
		}
		// Remove item from player's inventory
		game->player->remove_item(name); // Remove item from player's inventory
		// Update inventory
		update_inventory();
	}
	else // Empty inventory
	{
		ui->contentList->addItem("> Drop ' '\nYou have gone prone. But, on realising how stupid you"
			" look, you decide to get back up again. Layer of Dirt has been added to your inventory.\n");
		game->player->add_item(&(*game->scene_items)["Layer of Dirt"]);
		update_inventory();
	}
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}

void GameWindow::on_Quit_clicked()
{
	qDebug() << "Quit Clicked";
	// Cleanup
	clean_ui();
	window->setCurrentIndex(0);
}

void GameWindow::on_Talk_clicked()
{
	TalkDialog *dialogue = new TalkDialog(game->get_current_location()->get_characters());
	dialogue->setFixedSize(dialogue->geometry().width(), dialogue->geometry().height()); // Prevent resize
	dialogue->show();
}

void GameWindow::on_InventoryExamine_clicked()
{
	QString name;
	if (!ui->Inventory->selectedItems().isEmpty()) // Check if player has selected anything
	{
		name = ui->Inventory->selectedItems().first()->text();
		ui->contentList->addItem("> Examine \"" + name + "\" (Inventory)");
		// Can't have objects in inventory, so should be item
		ui->contentList->addItem(game->player->get_items()[name]->get_description() + "\n");
	}
	else
		ui->contentList->addItem("> Examine ' ' (Inventory)\nYour grandfather's words echo in your mind..." \
			" There's a time and place for everything, but not now.\n");
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}