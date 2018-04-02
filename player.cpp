#include "player.h"

Player::Player()
{

}

Player::~Player()
{

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

Item* Player::get_items() const
{

}

bool Player::has_item(const Item &item) const
{

}

void Player::remove_item(const Item &item)
{

}

QString Player::to_string() const
{

}

