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

	while (std::isalnum(ch) || ch == '.')
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
		case '.':
			return ParseReal(leftover);
		default:
			return ParseOctal(leftover);
		}
	}
	else
	{
		return ParseInteger(number.substr(i));
	}
}

TokenType NumberParser::ParseInteger(std::string const& number)
{
	for (std::size_t i = 0; i < number.length(); ++i)
	{
		auto& ch = number.at(i);
		if (!std::isdigit(ch))
		{
			if (ch == '.')
			{
				return ParseReal(number.substr(i + 1));
			}

			return TokenType::ERROR;
		}
	}

	return TokenType::INTEGER_NUMBER;
}

TokenType NumberParser::ParseReal(std::string const& number)
{
	for (auto&& ch : number)
	{
		if (!std::isdigit(ch))
		{
			return TokenType::ERROR;
		}
	}

	return TokenType::REAL_NUMBER;
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
	for (std::size_t i = 0; i < number.length(); ++i)
	{
		auto& ch = number.at(i);

		if (!IsOctalDigit(ch))
		{
			if (ch == '.')
			{
				return ParseReal(number.substr(i + 1));
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
