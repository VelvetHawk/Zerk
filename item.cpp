#include "item.h"

/**
 * @brief Base constructor
 */
Item::Item() :
	name("No name set."), description("No description set.")
{

}

/**
 * @brief Constructor to define item with custom name and description
 * @param name - The name you wish to give the item
 * @param description - The description you wish to give the item
 */
Item::Item(string name, string description) :
	name(name), description(description)
{

}

/**
 * @brief Returns the name of the Item object
 */
string Item::get_name()
{
	return name;
}

/**
 * @brief Sets a new name for the Item object
 * @param name - The new name you wish to give the item
 */
void Item::set_name(string name)
{
	this->name = name;
}

/**
 * @brief Returns the description of the Item object
 */
string Item::get_description()
{
	return description;
}

/**
 * @brief Sets a new description for the Item object
 * @param description - The new description you wish to give the item
 */
void Item::set_description(string description)
{
	this->description = description;
}
