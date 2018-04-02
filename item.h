#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
	public:
		// Constructors/destructors
		Item();
		Item(const QString name, const QString description);
		// Functions
		QString get_name() const;
		void set_name(const QString name);
		QString get_description() const;
		void set_description(const QString description);
		bool is_pickupable() const;
		void set_pickupable(const bool pickupable);
		bool is_hidden() const;
		void set_hidden(const bool hidden);
		QString to_string() const;

	private:
		QString name;
		QString description;
		bool pickupable;
		bool hidden;
};

#endif // ITEM_H
