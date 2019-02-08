#include "gamewindow.h"
#include <QApplication>

#include "parser.h"
#include "menu.h"
#include <QMap>
#include <QStackedWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QStackedWidget windows;

	windows.setWindowTitle("Zerk: An Original Tale");

	// Views
	GameWindow gameWindow(&windows);
	Menu menuWindow(&windows);

	windows.addWidget(&menuWindow);
	windows.addWidget(&gameWindow);

	windows.setFixedSize(gameWindow.geometry().width(), gameWindow.geometry().height()); // Prevent resize

	// Show menu
	windows.setCurrentIndex(0);
	windows.show();

	return a.exec();
}
