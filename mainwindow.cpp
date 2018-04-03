#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
	delete game;
}

void MainWindow::start()
{
	game->start();
	display_objects();
	ui->contentList->addItem(game->location_string());
	ui->contentList->addItem("What would you like to do?\n");
}

void MainWindow::set_scene(Scene *scene)
{
	this->game = scene;
}

Scene* MainWindow::get_scene()
{
	return this->game;
}

void MainWindow::on_North_clicked()
{
	move("Go North", 'N');
}


void MainWindow::on_South_clicked()
{
	move("Go South", 'S');
}


void MainWindow::on_East_clicked()
{
	move("Go East", 'E');
}


void MainWindow::on_West_clicked()
{
	move("Go West", 'W');
}

void MainWindow::move(QString instruction, char direction)
{
	// Print message
	ui->contentList->addItem("> " + instruction);
	// Movement
	QString message = game->go(direction);
	if (!message.isEmpty())
		ui->contentList->addItem(message + "\n");
	// Location info
	ui->contentList->addItem(game->location_string());
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
	// Objects and Items
	display_objects();
}

void MainWindow::display_objects()
{
	ui->ObjectList->clear();
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

void MainWindow::on_Take_clicked()
{
	/*
	 * If they try to take an object, have them fail a D19 STR check
	 * where they require 20 to succeed
	 */
	QString name;
	if (!ui->ObjectList->selectedItems().isEmpty())
	{
		name = ui->ObjectList->selectedItems().first()->text(0);
		// Check if item selected is an object
		if (game->get_current_location()->get_objects().contains(name))
		{
			ui->contentList->addItem("> Take \'" + name + "\'...");
			int rand = qrand() % 19;
			ui->contentList->addItem("Rolling STR check to take \"" + name + "\"...");
			ui->contentList->addItem("STR check failed: " + QString::number(rand)  + ". 20 needed to pass.\n");
		}
		else // Remove item from location, add to inventory
		{
			// Add item to player's inventory
			game->player->add_item(&game->scene_items[name]);
			// Remove item from list
			qDeleteAll(ui->ObjectList->selectedItems());
			// Remove item from location
			game->get_current_location()->remove_item(name);
			/*
			 * ADD FUNCTIONALITY TO DISPLAY IN INVENTORY
			 */
		}
	}
	else
	{
		ui->contentList->addItem("> Take 'Thin Air'");
		ui->contentList->addItem("You reach out and desparately scramble to take whatever it is" \
			" that you were trying to take, but ultimately end up failing because you have not" \
			" selected a physical item.\n");
	}
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}

void MainWindow::on_Examine_clicked()
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
