#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow window;
	window.resize(900, 600);
	window.setWindowTitle("Zerk: An Original Tale");
	window.show();

	return a.exec();
}
