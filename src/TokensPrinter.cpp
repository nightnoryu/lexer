#include "TokensPrinter.h"

void TokensPrinter::Print(std::ostream& output, std::vector<Token> const& tokens)
{
	for (auto&& token : tokens)
	{
		if (token.type == TokenType::BLANK)
		{
			continue;
		}

		if (token.type == TokenType::ERROR)
		{
			output << "Error: unknown lexeme (" << token.lexeme << ")";
		}
		else
		{
			output << TokenTypeToString(token.type) << " (" << token.lexeme << ")";
		}

		output << " " << token.lineNumber << ":" << token.columnNumber << "\n";
	}
}

std::string TokensPrinter::TokenTypeToString(TokenType type)
{
	switch (type)
	{
	case TokenType::COMMENT:
		return "COMMENT";
	case TokenType::SEPARATOR:
		return "SEPARATOR";
	case TokenType::ASSIGNMENT:
		return "ASSIGNMENT";
	case TokenType::IDENTIFIER:
		return "IDENTIFIER";
	case TokenType::STRING_LITERAL:
		return "STRING_LITERAL";
	case TokenType::INTEGER_NUMBER:
		return "INTEGER_NUMBER";
	case TokenType::REAL_NUMBER:
		return "REAL_NUMBER";
	case TokenType::BINARY_NUMBER:
		return "BINARY_NUMBER";
	case TokenType::OCTAL_NUMBER:
		return "OCTAL_NUMBER";
	case TokenType::HEXADECIMAL_NUMBER:
		return "HEXADECIMAL_NUMBER";
	case TokenType::ADDITION:
		return "ADDITION";
	case TokenType::SUBTRACTION:
		return "SUBTRACTION";
	case TokenType::MULTIPLICATION:
		return "MULTIPLICATION";
	case TokenType::DIVISION:
		return "DIVISION";
	case TokenType::IF:
		return "IF";
	case TokenType::ELSE:
		return "ELSE";
	case TokenType::EQUAL:
		return "EQUAL";
	case TokenType::LESS:
		return "LESS";
	case TokenType::GREATER:
		return "GREATER";
	case TokenType::LESS_OR_EQUAL:
		return "LESS_OR_EQUAL";
	case TokenType::GREATER_OR_EQUAL:
		return "GREATER_OR_EQUAL";
	default:
		return "";
	}
}
