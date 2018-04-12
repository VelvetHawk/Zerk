#ifndef TALKDIALOG_H
#define TALKDIALOG_H

#include <QDialog>
#include <QMap>
#include <QDebug>
#include "character.h"

namespace Ui
{
	class TalkDialog;
}

class TalkDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit TalkDialog(const QMap<QString, Character *> &, QWidget *parent = 0);
		~TalkDialog();

	private:
		Ui::TalkDialog *ui;
		const QMap<QString, Character *> &people_at_location;
		void update_dialogue_options(QString character_name);

	private slots:
		void on_Speak_clicked();
		void on_characterSelector_currentIndexChanged(const QString &arg1);
		void on_Done_clicked();
};

#endif // TALKDIALOG_H
