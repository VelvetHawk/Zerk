#ifndef CHARACTER_H
#define CHARACTER_H

#include "person.h"
#include <QMap>

class Character : public Person
{
	public:
		// Constructors/destructors
		Character();
		~Character();
		// Functions
		QString get_name() const override;
		void set_name(const QString name) override;
		QString get_description() const override;
		void set_description(const QString description) override;
		Item* get_items() const override;
		bool has_item(const Item &item) const override;
		void remove_item(const Item &item) override;
		QString get_dialogue(const QString identifier) const;
		void set_dialogue(const QString identifier, const QString value);
		QString to_string() const override;
		QString operator[](const QString index) const;

	private:
		QMap<QString, QString> dialogue;
};

#endif // CHARACTER_H
