#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include "person.h"

class Player : public Person
{
	public:
		// Constructors/destructors
		Player();
		~Player();
		// Functions
		QString get_name() const override;
		void set_name(const QString name) override;
		QString get_description() const override;
		void set_description(const QString description) override;
		void add_item(Item *item) override;
		Item* get_item(const QString name) override;
		const QMap<QString, Item *>& get_items() const override;
		bool has_item(const QString name) const override;
		void remove_item(const QString name) override;
		QString to_string() const override;

	private:
		QMap<QString, Item *> *inventory;
};

#endif // PLAYER_H
