#include "object.h"

/**
 * @brief Base constructor
 */
Object::Object()
{

}

/**
 * @brief Returns a pointer to an Item array will all of the items contained in the object
 * @return Item pointer to array
 */
Item* Object::get_items()
{
	return items;
}

/**
 * @brief Adds an Item object to the items array
 * @param item - Pointer to the Item object you wish to add
 */
void Object::add_item(const Item& item)
{

}

/**
 * @brief Removes an Item object from the items array
 * @param item - Pointer to the Item object you wish to remove
 */
void Object::remove_item(const Item& item)
{

}

/**
 * @brief Overload of the + operator to shordhand add items to the item array
 * @param item - Pointer to the Item object you wish to add
 * @return Pointer to the Object
 */
Object* Object::operator+(const Item& item)
{

}
