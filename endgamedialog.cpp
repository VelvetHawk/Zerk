#include "endgamedialog.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::EndGameDialog)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("Congratulations!");
	setModal(true);
}

EndGameDialog::~EndGameDialog()
{
	delete ui;
}

void EndGameDialog::on_Done_clicked()
{
	this->close();
}
