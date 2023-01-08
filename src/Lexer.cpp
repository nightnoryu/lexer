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
			case ' ':
				token.type = TokenType::BLANK;
				break;
			case '#':
				token.type = TokenType::COMMENT;
				token.lexeme = "#";
				break;

			case '\'':
				token.type = TokenType::STRING_LITERAL;
				token.lexeme = ParseStringLiteral(line, i);
				break;

			case '+':
				token.type = TokenType::ADDITION;
				token.lexeme = "+";
				break;
			case '-':
				token.type = TokenType::SUBTRACTION;
				token.lexeme = "-";
				break;
			case '*':
				token.type = TokenType::MULTIPLICATION;
				token.lexeme = "*";
				break;
			case '/':
				token.type = TokenType::DIVISION;
				token.lexeme = "+";
				break;

			case '=':
				if (nextValue == '=')
				{
					token.type = TokenType::EQUAL;
					token.lexeme = "==";
					++i;
				}
				else
				{
					token.type = TokenType::ASSIGNMENT;
					token.lexeme = "=";
				}
				break;

			default:
				token.type = TokenType::ERROR;
				break;
			}

			if (token.type == TokenType::COMMENT)
			{
				i = line.length();
			}

			++i;
			result.emplace_back(std::move(token));
		}

		++lineNumber;
	}

	return result;
}

std::string Lexer::ParseStringLiteral(std::string const& line, std::size_t& i)
{
	std::string result = "'";
	auto ch = line.at(++i);

	while (ch != '\'')
	{
		result += ch;

		++i;
		if (i == line.length())
		{
			break;
		}

		ch = line.at(i);
	}

	result += '\'';
	++i;

	return result;
}
