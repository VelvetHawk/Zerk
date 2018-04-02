#include "character.h"

Character::Character()
{

}

Character::~Character()
{

}

QString Character::get_name() const
{
	return name;
}

void Character::set_name(const QString name)
{
	this->name = name;
}

QString Character::get_description() const
{
	return description;
}

void Character::set_description(const QString description)
{
	this->description = description;
}

Item* Character::get_items() const
{

}

bool Character::has_item(const Item &item) const
{

}

void Character::remove_item(const Item &item)
{

}

void Character::set_dialogue(const QString identifier, const QString value)
{
	dialogue.insert(identifier, value);
}

QString Character::to_string() const
{

}

/*
 *
 */
QString Character::operator[](const QString identifier) const
{
	return dialogue.value(identifier);
}

