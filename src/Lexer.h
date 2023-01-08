#pragma once

#include "Token.h"
#include <vector>

class Lexer
{
public:
	static std::vector<Token> Parse(std::istream& input);
};
