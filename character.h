#ifndef CHARACTER_H
#define CHARACTER_H

#include "person.h"

class Character : public Person
{
	public:
		Character();
		~Character();
		string get_name() override;
		void set_name(string name) override;
		string get_description() override;
		void set_description(string description) override;
		Item* get_items() override;
		bool has_item(Item& item) override;
		void remove_item(Item& item) override;
		string get_dialogue(string identifier);
		void set_dialogue(string identifier, string value);
		string operator[](string index);

	private:
		static const int LINES_MAX = 1;
		string identifiers[LINES_MAX]; // For dialogue
		string dialogue[LINES_MAX];
};

#endif // CHARACTER_H
