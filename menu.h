#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QStackedWidget>

namespace Ui {
	class Menu;
}

class Menu : public QWidget
{
	Q_OBJECT
	public:
		explicit Menu(QStackedWidget *parent = 0);
		~Menu();

	private slots:
		void on_Play_clicked();

		void on_Quit_clicked();

	private:
		Ui::Menu *ui;
		QStackedWidget *window;
};

#endif // MENU_H
