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
		string get_name() override;
		void set_name(string name) override;
		string get_description() override;
		void set_description(string description) override;
		Item* get_items() override;
		bool has_item(Item& item) override;
		void remove_item(Item& item) override;


	private:
		Item* inventory[];
};

#endif // PLAYER_H
