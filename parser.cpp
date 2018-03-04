#include "parser.h"

/*
 *
 */
void Parser::load(std::ifstream& file, Character* characters)
{
	// Pattern
	regex character(
		"<name>([A-Za-z0-9_.,' ]+)</name>[^<]*"  \
		"<description>([A-Za-z0-9_.,' ]*)</description>[^<]*" \
		"<lines>[^<]*"
			"<greeting>([A-Za-z0-9_.,' ]+)</greeting>[^<]*" \
			"<goodbye>([A-Za-z0-9_.,' ]+)</goodbye>[^<]*" \
		"</lines>"
	);

	// Data
	string line;
	std::smatch matches;

	// ...No string delimiters allowed...?
	for (unsigned pos = 0; getline(file, line, '@'); pos++)
	{
		regex_search(line, matches, character);

		characters[pos].set_name(matches[1]);
		characters[pos].set_description(matches[2]);
		characters[pos].set_dialogue("greeting", matches[3]);
		characters[pos].set_dialogue("goodbye", matches[4]);
	}
}

/*
 *
 */
void Parser::load(std::ifstream& file, Location* locations)
{

}

/*
 *
 */
void Parser::load(std::ifstream& file, Item* items)
{

}

/*
 *
 */
void Parser::load(std::ifstream& file, Object* objects)
{

}

/*
 *
 */
void Parser::print_working_directory()
{
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	std::cout << std::string(buf) + '\\' << std::endl;
}
