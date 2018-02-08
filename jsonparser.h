#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>

using std::string;

class JsonParser
{
	public:
		JsonParser();

	private:
		string file_name;
		void load();
};

#endif // JSONPARSER_H
