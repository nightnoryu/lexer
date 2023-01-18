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
		{ "int", TokenType::INT },
		{ "double", TokenType::DOUBLE },
		{ "bool", TokenType::BOOL },
		{ "string", TokenType::STRING },
		{ "const", TokenType::CONST },
		{ "true", TokenType::TRUE },
		{ "false", TokenType::FALSE },
		{ "if", TokenType::IF },
		{ "else", TokenType::ELSE },
		{ "while", TokenType::WHILE },
		{ "for", TokenType::FOR },
		{ "break", TokenType::BREAK },
		{ "continue", TokenType::CONTINUE },
		{ "read", TokenType::READ },
		{ "print", TokenType::PRINT },
		{ "print", TokenType::CLASS },
		{ "public", TokenType::PUBLIC },
		{ "protected", TokenType::PROTECTED },
		{ "private", TokenType::PRIVATE },
	};

	static std::string ParseStringLiteral(std::string const& line, std::size_t& i);

	static bool IsIdentifierStart(char value);
	static bool IsIdentifierSymbol(char value);
	static std::tuple<TokenType, std::string> ParseIdentifier(std::string const& line, std::size_t& i);
};
