#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "item.h"
#include "person.h"

using std::string;

class Player : public Person
{
	public:
		Player();
		~Player();
		Item* get_inventory();
		void add_item(Item* item);
		void remove_item(Item* item);

	private:
		Item* inventory[];
};

#endif // PLAYER_H
