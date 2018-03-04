#include "test_item.h"
#include <iostream>

/**
 * @brief Test the Item::set_name() function
 */
void Test_Item::test_name()
{
	Item item;
	string name = "Spoon";
	item.set_name(name);
	QCOMPARE(item.get_name(), name);
}

/**
 * @brief Test the Item::set_description() function
 */
void Test_Item::test_description()
{
	Item item;
	string description = "This is a much longer string. This contains the description of the object.";
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
	string name = "name";
	string description = "description";
	Item second_item(name, description);
	QCOMPARE(second_item.get_name(), name);
	QCOMPARE(second_item.get_description(), description);
}

QTEST_MAIN(Test_Item)
