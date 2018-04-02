#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include "item.h"

class Object
{
	public:
		// Static variables
		const static int SIZE = 10; // Shared across all Objects
		// Constructors/destructors
		Object();
		// Functions
		QString get_name() const;
		void set_name(const QString name);
		QString get_description() const;
		void set_description(const QString description);
		Item* get_items() const;
		void add_item(const Item *item);
		void remove_item(const Item *item);
		QString to_string() const;
		Object* operator+(const Item *item);

	private:
		int item_index;
		QString name;
		QString description;
		bool has_inventory();
		Item *items;
};

#endif // OBJECT_H
