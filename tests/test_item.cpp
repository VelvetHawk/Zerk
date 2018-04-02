#include "test_item.h"
#include <iostream>

/**
 * @brief Test the Item::set_name() function
 */
void Test_Item::test_name()
{
	Item item;
	QString name = "Spoon";
	item.set_name(name);
	QCOMPARE(item.get_name(), name);
}

/**
 * @brief Test the Item::set_description() function
 */
void Test_Item::test_description()
{
	Item item;
	QString description = "This is a much longer QString. This contains the description of the object.";
	item.set_description(description);
	QCOMPARE(item.get_description(), description);
}

/**
 * @brief Test the Item::Item() function
 */
void Test_Item::test_item()
{
//	// Base constructor
	Item item;
	QCOMPARE(item.get_name(), "No name set.");
	QCOMPARE(item.get_description(), "No description set.");

//	// Second constructor
	QString name = "name";
	QString description = "description";
	Item second_item(name, description);
	QCOMPARE(second_item.get_name(), name);
	QCOMPARE(second_item.get_description(), description);
}

QTEST_MAIN(Test_Item)
