#include "talkdialog.h"
#include "ui_talkdialog.h"

TalkDialog::TalkDialog(const QMap<QString, Character *> &characters, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TalkDialog),
	people_at_location(characters)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("Talk");
	setModal(true);
	// Set up characters
	for (auto i = people_at_location.begin(); i != people_at_location.end(); i++)
		ui->characterSelector->addItem(i.value()->get_name());
}

TalkDialog::~TalkDialog()
{
	delete ui;
	qDebug() << "Deleting chat dialogue box";
}

void TalkDialog::update_dialogue_options(QString character_name)
{
	// Greeting
	ui->dialogueList->addItem("> You: \"Hello " + character_name + "\"");
	ui->dialogueList->addItem(character_name + ": \""
		+ (*people_at_location[character_name])["greeting"] + "\"\n");
	ui->dialogueList->scrollToBottom();
	// Change responses
	ui->firstOption->setText((*people_at_location[character_name])["firstOption"]);
	ui->secondOption->setText((*people_at_location[character_name])["secondOption"]);
	ui->thirdOption->setText((*people_at_location[character_name])["thirdOption"]);
}

void TalkDialog::on_Speak_clicked()
{
	QString character = ui->characterSelector->currentText();
	switch(ui->dialogueSelector->value())
	{
		case 0:
			ui->dialogueList->addItem("> You: \""
				+ (*people_at_location[character])["firstOption"] + "\"");
			ui->dialogueList->addItem(character + ": \""
				+ (*people_at_location[character])["firstResponse"] + "\"\n");
			qDebug() << "Option 0";
			break;
		case 1:
			ui->dialogueList->addItem("> You: \""
				+ (*people_at_location[character])["secondOption"] + "\"");
			ui->dialogueList->addItem(character + ": \""
				+ (*people_at_location[character])["secondResponse"] + "\"\n");
			qDebug() << "Option 1";
			break;
		case 2:
			ui->dialogueList->addItem("> You: \""
				+ (*people_at_location[character])["thirdOption"] + "\"");
			ui->dialogueList->addItem(character + ": \""
				+ (*people_at_location[character])["thirdResponse"] + "\"\n");
			qDebug() << "Option 2";
			break;
	}
	ui->dialogueList->scrollToBottom();
}

void TalkDialog::on_characterSelector_currentIndexChanged(const QString &arg1)
{
	update_dialogue_options(arg1);
	qDebug() << "Changed to: " << arg1;
}

void TalkDialog::on_Done_clicked()
{
	this->close();
	qDebug() << "Dialogue window closed";
}
