#include "mainwindow.h"
#include <QApplication>

#include "parser.h"
#include "menu.h"
#include <QMap>

int main(int argc, char *argv[])
{
//	// Init data maps
//	QMap<QString, Character> characters;
//	QMap<QString, Item> items;
//	QMap<QString, Object> objects;
//	QMap<QString, Location> locations;

//	// Init player
//	Player *player = new Player();

//	// Load data from files
//	Parser::load("../Zerk/characters.xml", characters);
//	Parser::load("../Zerk/items.xml", items);
//	Parser::load("../Zerk/objects.xml", objects);
//	Parser::load("../Zerk/locations.xml", locations);

//	// Print data (debug only)
//	/*
//	std::cout << "Characters:" << std::endl;
//	for (unsigned i = 0; i < characters.size(); i++)
//		std::cout << i << "). " << characters[i].get_name().toStdString()
//			<< " (" << characters[i].get_description().toStdString() << ")" << std::endl;

//	std::cout << "Items:" << std::endl;
//	for (unsigned i = 0; i < items.size(); i++)
//		std::cout << i << "). " << items[i].get_name().toStdString()
//			<< " (" << items[i].get_description().toStdString() << ")" << std::endl;

//	std::cout << "Objects:" << std::endl;
//	for (unsigned i = 0; i < objects.size(); i++)
//		std::cout << i << "). " << objects[i].get_name().toStdString()
//			<< " (" << objects[i].get_description().toStdString() << ")" << std::endl;

//	std::cout << "Locations:" << std::endl;
//	for (unsigned i = 0; i < locations.size(); i++)
//		std::cout << i << "). " << locations[i].get_name().toStdString()
//			<< " (" << locations[i].get_description().toStdString() << ")" << std::endl;
//	*/

//	/*
//	 * Change a pointer arguments to reference arguments
//	 * and dereference all pointer values passed to
//	 * create const reference arguments in all functions
//	 * where data won't be changed
//	 */

	QApplication a(argc, argv);
//	// Windows
//	// MainWindow game_window;

//	// Start game
//	Scene *game = new Scene(objects, items, characters, player, locations);

//	game_window.set_scene(game);
//	game_window.start();
//	game_window.show();

	Menu menu;
	menu.show();

	return a.exec();
}
