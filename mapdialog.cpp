#include "mapdialog.h"
#include "ui_mapdialog.h"

MapDialog::MapDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MapDialog)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setModal(true);
	setWindowTitle("Map");
}

MapDialog::~MapDialog()
{
	delete ui;
}

void MapDialog::on_Done_clicked()
{
	this->close();
}
