#include "parser.h"

#include <iostream>

bool Parser::is_white_space(const char& symbol) const
{
	return (symbol == '\n' or symbol == ' ' or symbol == 9 or symbol == 11 or symbol == '\0') ? true : false;
}

void Parser::parse_command(const String& line)
{
	String singleToken;

	for (int i = 0; i < line.strlen(); ++i) {
		if (!is_white_space(line[i])) {
			singleToken += line[i];
		} else if (!singleToken.is_empty()) {
			tokens.push_back(singleToken);
			singleToken.clear();
		} else {
			tokens.push_back(singleToken);
			singleToken.clear();
		}
	}
}

bool Parser::is_valid(const std::vector<String>& com)
{
	if (com[0] == "lpushb" || com[0] == "lpushf" || com[0] == "spush" || com[0] == "set" || com[0] == "hget") {
		if (com.size() != 3) {
			return false;
		}
	} else if (com[0] == "lpopb" || com[0] == "lpopf" || com[0] == "ldel" || com[0] == "get" || com[0] == "del" || com[0] == "lget" ||
			com[0] == "sget" || com[0] == "sdel" || com[0] == "qpop" || com[0] == "qdel" || com[0] == "qtop" || com[0] == "hdel") {
		if (com.size() != 2) {
			return false;
		}
	} else if (com[0] == "hpush" || com[0] == "qpush") {
		if (com.size() != 4) {
			return false;
		}
	}
	
	return true;
}
