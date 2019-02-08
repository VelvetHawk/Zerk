#include "player.h"
#include <QDebug>

Player::Player()
	: inventory(new QMap<QString, Item *>)
{

}

Player::~Player()
{
	delete inventory;
}

QString Player::get_name() const
{
	return this->name;
}

void Player::set_name(const QString name)
{
	this->name = name;
}

QString Player::get_description() const
{
	return this->description;
}

void Player::set_description(const QString description)
{
	this->description = description;
}

void Player::add_item(Item *item)
{
	inventory->insert(item->get_name(), item);
}

Item*Player::get_item(const QString name)
{
	return (*inventory)[name];
}

const QMap<QString, Item*>& Player::get_items() const
{
	return *inventory;
}

bool Player::has_item(const QString name) const
{
	return inventory->contains(name);
}

void Player::remove_item(const QString name)
{
	inventory->remove(name);
}

QString Player::to_string() const
{
	return name + ". " + description;
}

