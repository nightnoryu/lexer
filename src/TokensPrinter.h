#pragma once

#include "Token.h"
#include <iostream>
#include <vector>

class TokensPrinter
{
public:
	static void Print(std::ostream& output, std::vector<Token> const& tokens);
};
