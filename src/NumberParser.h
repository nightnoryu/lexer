#pragma once

#include "Token.h"
#include <tuple>

class NumberParser
{
public:
	static bool IsNumberStart(char value);

	static std::tuple<TokenType, std::string> Parse(std::string const& line, std::size_t& i);

private:
	static std::string ReadNumber(std::string const& line, std::size_t& i);
	static TokenType ParseNumber(std::string const& number);

	static TokenType ParseInteger(std::string const& number);
	static TokenType ParseReal(std::string const& number);

	static TokenType ParseHex(std::string const& number);
	static TokenType ParseBinary(std::string const& number);
	static TokenType ParseOctal(std::string const& number);

	static bool IsHexDigit(char ch);
	static bool IsBinaryDigit(char ch);
	static bool IsOctalDigit(char ch);
};
