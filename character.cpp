#include "character.h"

Character::Character() :
	identifiers {"greeting"}
{

}

Character::~Character()
{

}

string Character::get_name()
{
	return name;
}

void Character::set_name(string name)
{
	this->name = name;
}

string Character::get_description()
{
	return description;
}

void Character::set_description(string description)
{
	this->description = description;
}

Item* Character::get_items()
{

}

bool Character::has_item(Item& item)
{

}

void Character::remove_item(Item& item)
{

}

/*
 * Potentially unnecessary function
 */
std::string Character::get_dialogue(string identifier)
{
	for (int i = 0; i < LINES_MAX; i++)
	{
		if (identifiers[i].compare(identifier) == 0) // Both strings match
			return dialogue[i];
	}
	return "Identifier " + identifier + " doesn't exist.";
}

void Character::set_dialogue(string identifier, string value)
{
	for (int i = 0; i < LINES_MAX; i++)
		if (identifiers[i].compare(identifier) == 0) // Both strings match
			dialogue[i] = value;
}

/*
 * TODO: This may need to be removed later, rename index to identifiers
 */
string Character::operator[](string identifier)
{
	for (int i = 0; i < LINES_MAX; i++)
	{
		if (identifiers[i].compare(identifier) == 0) // Both strings match
			return dialogue[i];
	}
	return "Identifier " + identifier + " doesn't exist.";
}

