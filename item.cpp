#include "item.h"
#include <QDebug>

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
Item::Item(const QString name, const QString description) :
	name(name), description(description)
{

}

/**
 * @brief Returns the name of the Item object
 */
QString Item::get_name() const
{
	return name;
}

/**
 * @brief Sets a new name for the Item object
 * @param name - The new name you wish to give the item
 */
void Item::set_name(const QString name)
{
	this->name = name;
}

/**
 * @brief Returns the description of the Item object
 */
QString Item::get_description() const
{
	return description;
}

/**
 * @brief Sets a new description for the Item object
 * @param description - The new description you wish to give the item
 */
void Item::set_description(const QString description)
{
	this->description = description;
}

/**
 * @brief
 * @return
 */
bool Item::is_pickupable() const
{
	return this->pickupable;
}

/**
 * @brief
 * @return
 */
void Item::set_pickupable(const bool pickupable)
{
	this->pickupable = pickupable;
}

/**
 * @brief
 * @return
 */
bool Item::is_hidden() const
{
	return this->hidden;
}

/**
 * @brief
 * @return
 */
void Item::set_hidden(const bool hidden)
{
	this->hidden = hidden;
}
