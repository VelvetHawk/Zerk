#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h> // For working dir

#include "character.h"
#include "location.h"
#include "item.h"
#include "object.h"

using std::vector;
using std::string;
using std::regex;

class Parser
{
	public:
		Parser() = delete;
		~Parser() = delete;
        void print_working_directory();
		/*
		 * Stupid that this cannot be moved to external .cpp file for implementation
		 */
		template<typename T> static void load(int amount, string file_name, T* p_array)
		{
			std::ifstream file;
			file.open(file_name);

			if (file.is_open())
			{
				Parser::load(file, p_array);
				std::cout << "Finished loading characters " << std::endl;
				file.close();
			}
			else
				std::cout << "Unable to locate or open file " + file_name << std::endl;
		}

    private:
		static void load(std::ifstream& file, Character* character);
		static void load(std::ifstream& file, Location* location);
		static void load(std::ifstream& file, Item* item);
		static void load(std::ifstream& file, Object* object);
};

#endif // JSONPARSER_H
