#include "mainwindow.h"
#include <QApplication>

#include "parser.h"

#define TOTAL_CHARACTERS 3
#define TOTAL_ITEMS 1
#define TOTAL_OBJECTS 3
#define TOTAL_LOCATIONS 3

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
//	MainWindow window;
//	window.resize(900, 600);
//	window.setWindowTitle("Zerk: An Original Tale");
//	window.show();

//	return a.exec();

	// Init data arrays
	Character* characters = new Character[TOTAL_CHARACTERS];
	Item* items = new Item[TOTAL_ITEMS];
	Object* objects = new Object[TOTAL_OBJECTS];
	Location* locations = new Location[TOTAL_LOCATIONS];

	// Load data from files
	Parser::load(TOTAL_CHARACTERS, "../Zerk/characters.xml", characters);
	Parser::load(TOTAL_ITEMS, "../Zerk/items.xml", items);
	Parser::load(TOTAL_ITEMS, "../Zerk/objects.xml", objects);
	Parser::load(TOTAL_ITEMS, "../Zerk/locations.xml", locations);

	return 0;
}
