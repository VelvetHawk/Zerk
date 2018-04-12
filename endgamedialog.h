#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>

namespace Ui
{
	class EndGameDialog;
}

class EndGameDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit EndGameDialog(QWidget *parent = 0);
		~EndGameDialog();

	private slots:
		void on_Done_clicked();

	private:
		Ui::EndGameDialog *ui;
};

#endif // ENDGAMEDIALOG_H
