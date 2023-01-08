#pragma once

#include "Token.h"
#include <iostream>
#include <vector>

class Lexer
{
public:
	static std::vector<Token> Parse(std::istream& input);

private:
	static std::string ParseStringLiteral(std::string const& line, std::size_t& i);
	static Token ParseNumber(std::string const& line, std::size_t& i);
	static Token ParseIdentifier(std::string const& line, std::size_t& i);
};
