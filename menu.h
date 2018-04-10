#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
	class Menu;
}

class Menu : public QMainWindow
{
	Q_OBJECT
	public:
		explicit Menu(QWidget *parent = 0);
		~Menu();

	private slots:
		void on_Play_clicked();

	private:
		Ui::Menu *ui;
		MainWindow *game_window;
};

#endif // MENU_H
