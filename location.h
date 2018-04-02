#ifndef LOCATION_H
#define LOCATION_H

#include <QString>
#include <QMap>
#include "item.h"
#include "object.h"
#include "character.h"

class Location
{
	public:
		// Constructors/destructors
		Location();
		Location(const QString name);
		~Location();
		// Functions
		QString get_name() const;
		void set_name(const QString name);
		QString get_description() const;
		void set_description(const QString description);
		void set_direction_text(const char direction, const QString text);
		QString get_direction_text(const char direction) const;
		void set_adjacency(const char direction, Location *location);
		Location* get_adjacency(const char direction) const;
		bool has_adjacency(const char direction) const;
		Object* get_object(const QString name) const;
		Object* get_objects() const;
		void add_object(const Object *object);
		void remove_object(const Object *object);
		void add_item(const Item *item);
		void remove_item(const QString name);
		Item* get_items() const;
		QString to_string() const;

	private:
		// Location info
		QString name;
		QString description;
		// Direction text
		QMap<char, QString> directions; // Text for each direction
		QMap<char, Location *> adjacencies; // Neighbouring locations
		// Things at location
		Object *objects[];
		Item *items[]; // Dropped items
		Character *people[];
};

#endif // LOCATION_H
