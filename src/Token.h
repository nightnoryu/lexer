#pragma once

#include <string>

enum class TokenType
{
	START,
	BLANK,
	COMMENT,

	ASSIGNMENT,
	IDENTIFIER,
	STRING_LITERAL,

	INTEGER_NUMBER,
	REAL_NUMBER,
	BINARY_NUMBER,
	OCTAL_NUMBER,
	HEXADECIMAL_NUMBER,

	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,

	IF,
	ELSE,

	EQUAL,
	LESS,
	GREATER,
	LESS_OR_EQUAL,
	GREATER_OR_EQUAL,

	ERROR,
};

struct Token
{
	TokenType type;
	std::string lexeme;
	std::size_t lineNumber;
	std::size_t columnNumber;
};
