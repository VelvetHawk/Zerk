#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item
{
	public:
		Item();
		Item(string name, string description);
		string get_name();
		void set_name(string name);
		string get_description();
		void set_description(string description);

	private:
		string name;
		string description;
};

#endif // ITEM_H
