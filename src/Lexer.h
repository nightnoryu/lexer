#pragma once

#include "Token.h"
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

class Lexer
{
public:
	static std::vector<Token> Parse(std::istream& input);

private:
	static inline const std::unordered_map<std::string, TokenType> RESERVED_WORDS = {
		{ "if", TokenType::IF },
		{ "else", TokenType::ELSE },
	};

	static std::string ParseStringLiteral(std::string const& line, std::size_t& i);

	static bool IsNumberStart(char value);
	static std::tuple<TokenType, std::string> ParseNumber(std::string const& line, std::size_t& i);

	static bool IsIdentifierStart(char value);
	static bool IsIdentifierSymbol(char value);
	static std::tuple<TokenType, std::string> ParseIdentifier(std::string const& line, std::size_t& i);
};
