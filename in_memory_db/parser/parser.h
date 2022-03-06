#ifndef PARSER_H
#define PARSER_H

#include "../string/string.h"

#include <vector>

class Parser
{
public:
	void parse_command(const String&);
	std::vector<String> get_tokens() const { return tokens; }
	void clear() { tokens.clear(); }
	bool is_valid(const std::vector<String>&);

private:
	bool is_white_space(const char&) const;
	
	std::vector<String> tokens;
};

#endif //PARSER_H
