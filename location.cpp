#include "location.h"

/**
 * @brief
 */
Location::Location()
{

}

/**
 * @brief
 */
Location::Location(const QString name)
{
	this->name = name;
}

/**
 * @brief
 */
Location::~Location()
{

}

/**
 * @brief
 */
QString Location::get_name() const
{
	return this->name;
}

/**
 * @brief
 */
void Location::set_name(const QString name)
{
	this->name = name;
}

/**
 * @brief
 */
QString Location::get_description() const
{
	return this->description;
}

/**
 * @brief
 */
void Location::set_description(const QString description)
{
	this->description = description;
}

/**
 * @brief
 */
void Location::set_direction_text(const char direction, const QString text)
{
	directions.insert(direction, text);
}

/**
 * @brief
 */
QString Location::get_direction_text(const char direction) const
{
	return directions[direction];
}

/**
 * @brief
 */
Location* Location::get_adjacency(const char direction) const
{
	return adjacencies.value(direction);
}

/**
 * @brief
 */
bool Location::has_adjacency(const char direction) const
{
	return adjacencies.contains(direction);
}

/**
 * @brief
 */
void Location::set_adjacency(const char direction, Location *location)
{
	adjacencies.insert(direction, location);
}

/**
 * @brief
 */
Object* Location::get_object(const QString name) const
{
	return objects[name];
}

/**
 * @brief
 */
void Location::add_object(Object* object)
{
	objects.insert(object->get_name(), object);
}

/**
 * @brief
 */
const QMap<QString, Object*>& Location::get_objects() const
{
	return objects;
}

/**
 * @brief
 */
void Location::remove_object(const QString name)
{
	objects.remove(name);
}

/**
 * @brief
 */
void Location::add_item(Item* item)
{
	items.insert(item->get_name(), item);
}

/**
 * @brief
 */
void Location::remove_item(const QString name)
{
	items.remove(name);
}

/**
 * @brief
 */
Item* Location::get_item(const QString name) const
{
	return items[name];
}

const QMap<QString, Item*>& Location::get_items() const
{
	return items;
}

