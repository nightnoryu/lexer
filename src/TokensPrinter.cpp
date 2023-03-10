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
			output << "Error: invalid lexeme at";
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
	case TokenType::COMMA:
		return "COMMA";
	case TokenType::SEMICOLON:
		return "SEMICOLON";
	case TokenType::COLON:
		return "COLON";
	case TokenType::DOT:
		return "DOT";
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
	case TokenType::LOGICAL_AND:
		return "LOGICAL_AND";
	case TokenType::LOGICAL_OR:
		return "LOGICAL_OR";
	case TokenType::LOGICAL_NOT:
		return "LOGICAL_NOT";
	case TokenType::IF:
		return "IF";
	case TokenType::ELSE:
		return "ELSE";
	case TokenType::OPENING_PARENTHESIS:
		return "OPENING_PARENTHESIS";
	case TokenType::CLOSING_PARENTHESIS:
		return "CLOSING_PARENTHESIS";
	case TokenType::OPENING_BRACE:
		return "OPENING_BRACE";
	case TokenType::CLOSING_BRACE:
		return "CLOSING_BRACE";
	case TokenType::EQUAL:
		return "EQUAL";
	case TokenType::NOT_EQUAL:
		return "NOT_EQUAL";
	case TokenType::LESS:
		return "LESS";
	case TokenType::GREATER:
		return "GREATER";
	case TokenType::LESS_OR_EQUAL:
		return "LESS_OR_EQUAL";
	case TokenType::GREATER_OR_EQUAL:
		return "GREATER_OR_EQUAL";
	case TokenType::INT:
		return "INT";
	case TokenType::DOUBLE:
		return "DOUBLE";
	case TokenType::BOOL:
		return "BOOL";
	case TokenType::STRING:
		return "STRING";
	case TokenType::CONST:
		return "CONST";
	case TokenType::TRUE:
		return "TRUE";
	case TokenType::FALSE:
		return "FALSE";
	case TokenType::WHILE:
		return "WHILE";
	case TokenType::FOR:
		return "FOR";
	case TokenType::BREAK:
		return "BREAK";
	case TokenType::CONTINUE:
		return "CONTINUE";
	case TokenType::READ:
		return "READ";
	case TokenType::PRINT:
		return "PRINT";
	case TokenType::CLASS:
		return "CLASS";
	case TokenType::PUBLIC:
		return "PUBLIC";
	case TokenType::PROTECTED:
		return "PROTECTED";
	case TokenType::PRIVATE:
		return "PRIVATE";
	default:
		return "";
	}
}
