#include "TokensPrinter.h"

void TokensPrinter::Print(std::ostream& output, std::vector<Token> const& tokens)
{
	for (auto&& token : tokens)
	{
		if (token.type == TokenType::ERROR)
		{
			output << "Error: unknown lexeme (" << token.lexeme << ")";
		}
		else
		{
			output << TokenTypeToString(token.type) << "(" << token.lexeme << ")";
		}

		output << " " << token.lineNumber << ":" << token.columnNumber << "\n";
	}
}

std::string TokensPrinter::TokenTypeToString(TokenType type)
{
	return {};
}
