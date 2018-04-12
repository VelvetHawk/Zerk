#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QString>
#include <QStackedWidget>

#include "scene.h"

namespace Ui
{
	class GameWindow;
}

class GameWindow : public QWidget
{
	Q_OBJECT

	public:
		// Constructors/destructors
		explicit GameWindow(QStackedWidget *parent = 0);
		~GameWindow();
		// Functions
		void start();
		void set_scene(Scene *scene);
		Scene* get_scene();

	private:
		// Variables
		Ui::GameWindow *ui;
		Scene *game;
		QStackedWidget *window;
		bool game_run_before;
		// Functions
		void clean_ui();
		void clean_objects();
		void clean_inventory();
		void reset_scene();
		void move(QString instruction, char direction);
		void display_objects();
		void update_location_details();
		void update_inventory();

	private slots:
		void on_North_clicked();
		void on_South_clicked();
		void on_West_clicked();
		void on_East_clicked();
		void on_Take_clicked();
		void on_Examine_clicked();
		void on_Drop_clicked();
		void on_Quit_clicked();
		void on_Talk_clicked();
		void on_InventoryExamine_clicked();
};

#endif // GAMEWINDOW_H
