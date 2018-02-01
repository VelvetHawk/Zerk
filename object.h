#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "item.h"

using std::string;

class Object
{
	public:
		Object();
		~Object();
		Item* get_items();
		void add_item(Item* item);
		void remove_item(Item* item);
		// Look into overloading operator for two different types
		Object operator+(Item& item);

	private:
		string name;
		string description;
		Item* items[];
};

#endif // OBJECT_H
