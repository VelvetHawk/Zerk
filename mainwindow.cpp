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
	ui->contentList->addItem(game->get_current_location());
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
	ui->contentList->addItem("> " + instruction + "\n");
	// Movement
	QString message = game->go(direction);
	if (!message.isEmpty())
		ui->contentList->addItem(message + "\n");
	// Location info
	ui->contentList->addItem(game->get_current_location());
	ui->contentList->addItem("What would you like to do?\n");
	ui->contentList->scrollToBottom();
}
