#include "object.h"

/**
 * @brief Base constructor
 */
Object::Object()
	: items(new Item[SIZE])
{

}

/**
 * @brief
 */
QString Object::get_name() const
{
	return this->name;
}

/**
 * @brief
 */
void Object::set_name(const QString name)
{
	this->name = name;
}

/**
 * @brief
 */
QString Object::get_description() const
{
	return this->description;
}

/**
 * @brief
 */
void Object::set_description(const QString description)
{
	this->description = description;
}

/**
 * @brief Returns a pointer to an Item array will all of the items contained in the object
 * @return Item pointer to array
 */
Item* Object::get_items() const
{
	return items;
}

/**
 * @brief Adds an Item object to the items array
 * @param item - Pointer to the Item object you wish to add
 */
void Object::add_item(const Item *item)
{
	if (item_index < SIZE) // Check bounds
	{
		items[item_index] = *item;
		item_index++;
	}
}

/**
 * @brief Removes an Item object from the items array
 * @param item - Pointer to the Item object you wish to remove
 */
void Object::remove_item(const Item *item)
{
	for (int i = 0; i < item_index; i++)
	{
		//if (i)
		// Compare memory addresses
	}
}

/**
 * @brief Overload of the + operator to shordhand add items to the item array
 * @param item - Pointer to the Item object you wish to add
 * @return Pointer to the Object
 */
Object* Object::operator+(const Item* item)
{

}
