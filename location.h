#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "item.h"
#include "object.h"
#include "character.h"

using std::string;

class Location
{
	public:
		Location();
		Location(string name);
		~Location();
		string get_name();
		void set_name(string name);
		string get_description();
		void set_description();
		Object* get_object(string name);
		Object* get_objects();
		void add_object(Object* object);
		void remove_object(Object* object);
		Item* get_dropped_item(string name);
		Item* get_dropped_items();
		void add_item(Item* item);
		void remove_item(string name);

	private:
		string name;
		string description;
		Object* objects[];
		Item* droppedItems[];
		Character* people[];
};

#endif // LOCATION_H
