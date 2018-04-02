#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QMap>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <windows.h> // For working dir

#include "character.h"
#include "location.h"
#include "item.h"
#include "object.h"

using std::regex;
using std::string; // For file I/O

class Parser
{
	public:
		// Constructors/destructors
		Parser() = delete;
		~Parser() = delete;
		// Functions
		void print_working_directory() const;
		/*
		 * Stupid that this cannot be moved to external .cpp file for implementation
		 */
		template<typename T> static void load(const string file_name, QMap<QString, T> &p_vector)
		{
			std::ifstream file;
			file.open(file_name);

			if (file.is_open())
			{
				Parser::load(file, p_vector);
				file.close();
			}
			else
				std::cout << "Unable to locate or open file " + file_name << std::endl;
		}

    private:
		// Constants
		static const string NAME_TEMPLATE;
		static const string DESCRIPTION_TEMPLATE;
		static const string REGEX_TEMPLATE;
		// Functions
		static void load(std::ifstream &file, QMap<QString, Character> &character);
		static void load(std::ifstream &file, QMap<QString, Location> &location);
		static void load(std::ifstream &file, QMap<QString, Item> &item);
		static void load(std::ifstream &file, QMap<QString, Object> &object);
		static QString format(const string unformatted_string);
};

#endif // JSONPARSER_H
