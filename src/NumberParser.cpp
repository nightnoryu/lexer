#include "NumberParser.h"
#include <sstream>

bool NumberParser::IsNumberStart(char value)
{
	return std::isdigit(value);
}

std::tuple<TokenType, std::string> NumberParser::Parse(std::string const& line, std::size_t& i)
{
	auto const number = ReadNumber(line, i);
	return { ParseNumber(number), number };
}

std::string NumberParser::ReadNumber(std::string const& line, size_t& i)
{
	std::string result;
	auto ch = line.at(i);

	while (IsHexDigit(ch) || ch == 'b' || ch == 'x' || ch == '.')
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

TokenType NumberParser::ParseNumber(std::string const& number)
{
	if (number.length() == 1)
	{
		return TokenType::INTEGER_NUMBER;
	}

	std::size_t i = 0;
	auto first = number.at(i++);

	if (first == '0')
	{
		auto second = number.at(i++);
		auto const leftover = number.substr(i);

		switch (second)
		{
		case 'x':
			return ParseHex(leftover);
		case 'b':
			return ParseBinary(leftover);
		default:
			return ParseOctal(leftover);
		}
	}
	else
	{
		// TODO: doubles
		return TokenType::INTEGER_NUMBER;
	}
}
TokenType NumberParser::ParseHex(std::string const& number)
{
	if (number.length() == 0)
	{
		return TokenType::ERROR;
	}

	for (auto&& ch : number)
	{
		if (!IsHexDigit(ch))
		{
			return TokenType::ERROR;
		}
	}

	return TokenType::HEXADECIMAL_NUMBER;
}

TokenType NumberParser::ParseBinary(std::string const& number)
{
	if (number.length() == 0)
	{
		return TokenType::ERROR;
	}

	for (auto&& ch : number)
	{
		if (!IsBinaryDigit(ch))
		{
			return TokenType::ERROR;
		}
	}

	return TokenType::BINARY_NUMBER;
}

TokenType NumberParser::ParseOctal(std::string const& number)
{
	for (auto&& ch : number)
	{
		if (!IsOctalDigit(ch))
		{
			if (ch == '.')
			{
				// TODO: parse as double
			}

			return TokenType::ERROR;
		}
	}

	return TokenType::OCTAL_NUMBER;
}

bool NumberParser::IsHexDigit(char ch)
{
	return std::isdigit(ch) || ('A' <= ch && ch <= 'F');
}

bool NumberParser::IsBinaryDigit(char ch)
{
	return ch == '0' || ch == '1';
}

bool NumberParser::IsOctalDigit(char ch)
{
	return '0' <= ch && ch <= '7';
}
