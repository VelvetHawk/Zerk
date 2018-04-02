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
		Item* get_items() const override;
		bool has_item(const Item &item) const override;
		void remove_item(const Item &item) override;
		QString to_string() const override;

	private:
		Item* inventory[];
};

#endif // PLAYER_H
