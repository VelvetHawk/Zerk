#include "parser.h"
#include <QDebug>

// Parser constant initialisation
const string Parser::REGEX_TEMPLATE = "([A-Za-z0-9_.,'()? \n]*)";
const string Parser::NAME_TEMPLATE = "<name>" + Parser::REGEX_TEMPLATE + "</name>[^<]*";
const string Parser::DESCRIPTION_TEMPLATE = "<description>" + Parser::REGEX_TEMPLATE + "</description>[^<]*";

/*
 *
 */
void Parser::load(std::ifstream &file, QMap<QString, Character> &characters)
{
	// Pattern
	regex character(
		NAME_TEMPLATE
		+ DESCRIPTION_TEMPLATE
		+ "<lines>[^<]*"
			"<greeting>" + REGEX_TEMPLATE + "</greeting>[^<]*" \
			"<firstOption>" + REGEX_TEMPLATE + "</firstOption>[^<]*" \
			"<secondOption>" + REGEX_TEMPLATE + "</secondOption>[^<]*" \
			"<thirdOption>" + REGEX_TEMPLATE + "</thirdOption>[^<]*" \
			"<firstResponse>" + REGEX_TEMPLATE + "</firstResponse>[^<]*" \
			"<secondResponse>" + REGEX_TEMPLATE + "</secondResponse>[^<]*" \
			"<thirdResponse>" + REGEX_TEMPLATE + "</thirdResponse>[^<]*" \
			"<goodbye>" + REGEX_TEMPLATE +"</goodbye>[^<]*" \
		"</lines>"
	);

	// Data
	string line;
	std::smatch matches;
	QString	name;

	// ...No QString delimiters allowed...?
	for (unsigned pos = 0; getline(file, line, '@'); pos++)
	{
		regex_search(line, matches, character);
		name = format(matches[1]);
		characters.insert(name, Character()); // Name used as alias

		characters[name].set_name(name);
		characters[name].set_description(format(matches[2]));
		characters[name].set_dialogue("greeting", format(matches[3]));
		characters[name].set_dialogue("firstOption", format(matches[4]));
		characters[name].set_dialogue("secondOption", format(matches[5]));
		characters[name].set_dialogue("thirdOption", format(matches[6]));
		characters[name].set_dialogue("firstResponse", format(matches[7]));
		characters[name].set_dialogue("secondResponse", format(matches[8]));
		characters[name].set_dialogue("thirdResponse", format(matches[9]));
		characters[name].set_dialogue("goodbye", format(matches[10]));
	}
}

/*
 *
 */
void Parser::load(std::ifstream &file, QMap<QString, Location> &locations)
{
	// Pattern
	regex character(
		NAME_TEMPLATE  \
		+ DESCRIPTION_TEMPLATE \
		+ "<directions>[^<]*" \
			"<north>" + REGEX_TEMPLATE + "</north>[^<]*" \
			"<east>" + REGEX_TEMPLATE + "</east>[^<]*" \
			"<south>" + REGEX_TEMPLATE + "</south>[^<]*" \
			"<west>" + REGEX_TEMPLATE + "</west>[^<]*" \
		"</directions>"
	);

	// Data
	string line;
	std::smatch matches;
	QString	name;

	// ...No QString delimiters allowed...?
	for (unsigned pos = 0; getline(file, line, '@'); pos++)
	{
		regex_search(line, matches, character);
		name = format(matches[1]);
		locations.insert(name, Location());

		locations[name].set_name(name);
		locations[name].set_description(format(matches[2]));
		locations[name].set_direction_text('N', format(matches[3]));
		locations[name].set_direction_text('E', format(matches[4]));
		locations[name].set_direction_text('S', format(matches[5]));
		locations[name].set_direction_text('W', format(matches[6]));
	}
}

/*
 *
 */
void Parser::load(std::ifstream &file, QMap<QString, Item> &items)
{
	// Pattern
	regex item(
		NAME_TEMPLATE  \
		+ DESCRIPTION_TEMPLATE \
		+ "<attributes>[^<]*"
			"<pickupable>" + REGEX_TEMPLATE + "</pickupable>[^<]*" \
			"<hidden>" + REGEX_TEMPLATE + "</hidden>[^<]*" \
		"</attributes>"
	);

	// Data
	string line;
	std::smatch matches;
	QString	name;

	// ...No QString delimiters allowed...?
	for (unsigned pos = 0; getline(file, line, '@'); pos++)
	{
		regex_search(line, matches, item);
		name = format(matches[1]);
		items.insert(name, Item());

		items[name].set_name(name);
		items[name].set_description(format(matches[2]));
		if (matches[3] == "false")	items[name].set_pickupable(false);
		else						items[name].set_pickupable(true);
		if (matches[4] == "false")	items[name].set_hidden(false);
		else						items[name].set_hidden(true);
	}
}

/*
 *
 */
void Parser::load(std::ifstream &file, QMap<QString, Object> &objects)
{
	// Pattern
	regex object(
		NAME_TEMPLATE  \
		+ DESCRIPTION_TEMPLATE \
	);

	// Data
	string line;
	std::smatch matches;
	QString	name;

	// ...No QString delimiters allowed...?
	for (unsigned pos = 0; getline(file, line, '@'); pos++)
	{
		regex_search(line, matches, object);
		name = format(matches[1]);
		objects.insert(name, Object());

		objects[name].set_name(name);
		objects[name].set_description(format(matches[2]));
	}
}

/**
 * @brief Formats a std::string, removing excess whitespace
 * @return A formatted QString object
 */
QString Parser::format(const string format_string)
{
	return QString::fromStdString(format_string).trimmed().simplified();
}

/*
 *
 */
void Parser::print_working_directory() const
{
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	std::cout << string(buf) + '\\' << std::endl;
}
