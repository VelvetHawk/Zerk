#ifndef TEST_CHARACTER_H
#define TEST_CHARACTER_H

#include <QString>
#include <QtTest/QtTest>
#include "item.h"

using std::QString;

class Test_Character : public QObject
{
		Q_OBJECT
	public:
		explicit Test_Character(QObject *parent = nullptr);

	signals:

	public slots:
};

#endif // TEST_CHARACTER_H
