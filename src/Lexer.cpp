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
			auto currentChar = line.at(i);
			auto nextChar = i < line.length() - 1
				? line.at(i + 1)
				: currentChar;

			Token token;
			token.lineNumber = lineNumber;
			token.columnNumber = i + 1;

			switch (currentChar)
			{
			case ' ':
				token.type = TokenType::BLANK;
				break;
			case '#':
				token.type = TokenType::COMMENT;
				token.lexeme = "#";
				break;
			case ';':
				token.type = TokenType::SEPARATOR;
				token.lexeme = ";";
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

			case '(':
				token.type = TokenType::OPENING_PARENTHESIS;
				token.lexeme = "(";
				break;
			case ')':
				token.type = TokenType::CLOSING_PARENTHESIS;
				token.lexeme = ")";
				break;

			case '{':
				token.type = TokenType::OPENING_BRACE;
				token.lexeme = "{";
				break;
			case '}':
				token.type = TokenType::CLOSING_BRACE;
				token.lexeme = "}";
				break;

			case '=':
				if (nextChar == '=')
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
			case '!':
				if (nextChar == '=')
				{
					token.type = TokenType::NOT_EQUAL;
					token.lexeme = "!=";
					++i;
				}
				else
				{
					token.type = TokenType::ERROR;
				}
				break;

			case '<':
				if (nextChar == '=')
				{
					token.type = TokenType::LESS_OR_EQUAL;
					token.lexeme = "<=";
					++i;
				}
				else
				{
					token.type = TokenType::LESS;
					token.lexeme = "<";
				}
				break;
			case '>':
				if (nextChar == '=')
				{
					token.type = TokenType::GREATER_OR_EQUAL;
					token.lexeme = ">=";
					++i;
				}
				else
				{
					token.type = TokenType::GREATER;
					token.lexeme = ">";
				}
				break;

			default:
				if (IsIdentifierStart(currentChar))
				{
					token.lexeme = ParseIdentifier(line, i);
					token.type = DetermineIdentifierType(token.lexeme);
					break;
				}

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

	return result;
}

bool Lexer::IsIdentifierStart(char value)
{
	return value == '_' || std::isalpha(value);
}

bool Lexer::IsIdentifierSymbol(char value)
{
	return value == '_' || std::isalnum(value);
}

std::string Lexer::ParseIdentifier(std::string const& line, size_t& i)
{
	std::string result;
	result += line.at(i);
	auto ch = line.at(++i);

	while (IsIdentifierSymbol(ch))
	{
		result += ch;
		++i;
		if (i == line.length())
		{
			break;
		}

		ch = line.at(i);
	}

	if (i != line.length())
	{
		--i;
	}

	return result;
}

TokenType Lexer::DetermineIdentifierType(std::string const& lexeme)
{
	auto const type = RESERVED_WORDS.find(lexeme);
	if (type == RESERVED_WORDS.end())
	{
		return TokenType::IDENTIFIER;
	}

	return type->second;
}
