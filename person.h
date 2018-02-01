#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "item.h"

using std::string;

class Person
{
	public:
		Person();
		~Person();
		string get_name();
		void set_name(string name);
		string get_description();
		void set_description();
		Item* get_items();
		bool has_item(Item* item);

	private:
		string name;
		string description;
		Item items[];
};

#endif // PERSON_H
