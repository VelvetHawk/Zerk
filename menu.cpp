#include "menu.h"
#include "ui_menu.h"
#include "parser.h"

#include <iostream>

Menu::Menu(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Menu)
{
	ui->setupUi(this);
}

Menu::~Menu()
{
	delete ui;
}

void Menu::on_Play_clicked()
{
	// Init data maps
	QMap<QString, Character> characters;
	QMap<QString, Item> items;
	QMap<QString, Object> objects;
	QMap<QString, Location> locations;

	// Init player
	Player *player = new Player();

	// Load data from files
	Parser::load("../Zerk/characters.xml", characters);
	Parser::load("../Zerk/items.xml", items);
	Parser::load("../Zerk/objects.xml", objects);
	Parser::load("../Zerk/locations.xml", locations);

	// Print data (debug only)
	/*
	std::cout << "Characters:" << std::endl;
	for (unsigned i = 0; i < characters.size(); i++)
		std::cout << i << "). " << characters[i].get_name().toStdString()
			<< " (" << characters[i].get_description().toStdString() << ")" << std::endl;

	std::cout << "Items:" << std::endl;
	for (unsigned i = 0; i < items.size(); i++)
		std::cout << i << "). " << items[i].get_name().toStdString()
			<< " (" << items[i].get_description().toStdString() << ")" << std::endl;

	std::cout << "Objects:" << std::endl;
	for (unsigned i = 0; i < objects.size(); i++)
		std::cout << i << "). " << objects[i].get_name().toStdString()
			<< " (" << objects[i].get_description().toStdString() << ")" << std::endl;

	std::cout << "Locations:" << std::endl;
	for (unsigned i = 0; i < locations.size(); i++)
		std::cout << i << "). " << locations[i].get_name().toStdString()
			<< " (" << locations[i].get_description().toStdString() << ")" << std::endl;
	*/

	/*
	 * Change a pointer arguments to reference arguments
	 * and dereference all pointer values passed to
	 * create const reference arguments in all functions
	 * where data won't be changed
	 */

	// Start game
	Scene *game = new Scene(objects, items, characters, player, locations);

	this->hide();
	game_window = new MainWindow(this); // set Menu as parent of game
	//connect(ui->Play, SIGNAL(clicked()), game_window, SLOT(show()));

	game_window->set_scene(game);
	game_window->start();
	game_window->show();
	std::cout << "Play Clicked" << std::endl;
}
