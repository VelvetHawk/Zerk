#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QMap>
#include "item.h"

class Object
{
	public:
		// Constructors/destructors
		Object();
		~Object();
		// Functions
		QString get_name() const;
		void set_name(const QString name);
		QString get_description() const;
		void set_description(const QString description);
		QMap<QString, Item *>* get_items() const;
		void add_item(Item *item);
		void remove_item(const Item *item);
		bool is_examined() const;
		bool set_examined(bool examined);
		QString to_string() const;
		Object* operator+(const Item *item);

	private:
		QString name;
		QString description;
		bool has_inventory();
		QMap<QString, Item *> *items;
		bool examined;
};

#endif // OBJECT_H
