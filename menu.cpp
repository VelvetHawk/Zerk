#include "menu.h"
#include "ui_menu.h"
#include "parser.h"
#include "gamewindow.h"

#include <QDebug>

Menu::Menu(QStackedWidget *parent) : QWidget(parent),
	ui(new Ui::Menu), window(parent)
{
	ui->setupUi(this);
}

Menu::~Menu()
{
	delete ui;
}

void Menu::on_Play_clicked()
{
	window->setCurrentIndex(1);
	qobject_cast<GameWindow *>(window->widget(1))->start();
}

void Menu::on_Quit_clicked()
{
	//delete this;
	QApplication::quit(); // Quit application
}
