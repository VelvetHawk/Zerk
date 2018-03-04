#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "item.h"

using std::string;

class Object
{
	public:
		const static int SIZE = 10; // Shared across all Objects
		Object();
		Item* get_items();
		void add_item(const Item& item);
		void remove_item(const Item& item);
		// Look into overloading operator for two different types
		Object* operator+(const Item& item);

	private:
		int item_index;
		string name;
		string description;
		bool has_inventory();
		Item items[SIZE]; // Maximum 10 items in an object
};

#endif // OBJECT_H
