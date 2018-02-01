#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include <string>
#include <QtTest/QtTest>
#include "item.h"

using std::string;

class Test_Item: public QObject
{
	public:
		Test_Item();

	private:
		Item item_to_test;
		void test_name();
};

#endif // TEST_ITEM_H
