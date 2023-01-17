#define CATCH_CONFIG_MAIN

#include "../src/Lexer.h"
#include "../src/TokensPrinter.h"
#include "catch.hpp"
#include <sstream>

TEST_CASE("end2end cases")
{
	std::string const testFile = GENERATE("valid", "numbers");

	std::ifstream input("files/" + testFile + ".txt");
	std::stringstream output;

	std::ifstream expectedOutputFile("files/output/" + testFile + ".txt");
	std::stringstream expectedOutput;
	expectedOutput << expectedOutputFile.rdbuf();

	WHEN("parsing a file")
	{
		auto const tokens = Lexer::Parse(input);
		TokensPrinter::Print(output, tokens);

		THEN("result matches")
		{
			REQUIRE(output.str() == expectedOutput.str());
		}
	}
}
