#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <scene.h>

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		// Constructors/destructors
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		// Functions
		void start();
		void set_scene(Scene *scene);
		Scene* get_scene();

	private slots:
		void on_North_clicked();
		void on_South_clicked();
		void on_West_clicked();
		void on_East_clicked();
		void on_Take_clicked();
		void on_Examine_clicked();

	private:
		Ui::MainWindow *ui;
		Scene *game;
		void move(QString instruction, char direction);
		void display_objects();
};

#endif // MAINWINDOW_H
