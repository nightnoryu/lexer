#include "Lexer.h"

std::vector<Token> Lexer::Parse(std::istream& input)
{
	std::vector<Token> result;

	std::string line;
	std::size_t lineNumber = 1;

	while (std::getline(input, line))
	{
		std::size_t i = 0;
		while (i < line.length())
		{
			auto columnNumber = i + 1;

			auto currentValue = line.at(i);
			auto previousValue = i > 0 ? line.at(i - 1) : currentValue;
			auto nextValue = i < line.length() - 1 ? line.at(i + 1) : currentValue;

			Token token;
			token.lineNumber = lineNumber;
			token.columnNumber = i + 1;

			switch (currentValue)
			{
			case '+':
				token.type = TokenType::ADDITION;
				token.lexeme = "+";
				++i;
				break;
			case '-':
				token.type = TokenType::SUBTRACTION,
				token.lexeme = "-",
				++i;
				break;
			case '*':
				token.type = TokenType::MULTIPLICATION,
				token.lexeme = "*",
				++i;
				break;
			case '/':
				token.type = TokenType::DIVISION,
				token.lexeme = "+",
				++i;
				break;
			default:
				token.type = TokenType::ERROR;
				++i;
				break;
			}

			result.emplace_back(std::move(token));
		}

		++lineNumber;
	}

	return result;
}
