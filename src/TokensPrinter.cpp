#include "TokensPrinter.h"

void TokensPrinter::Print(std::ostream& output, std::vector<Token> const& tokens)
{
	for (auto&& token : tokens)
	{
		output << token.str << ": " << token.lineNumber << ":" << token.columnNumber << "\n";
	}
}
