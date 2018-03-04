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
		virtual string get_name() = 0;
		virtual void set_name(string name) = 0;
		virtual string get_description() = 0;
		virtual void set_description(string description) = 0;
		virtual Item* get_items() = 0;
		virtual bool has_item(Item& item) = 0;
		virtual void remove_item(Item& item) = 0;

	protected:
		string name;
		string description;
		Item items[];
};

#endif // PERSON_H
