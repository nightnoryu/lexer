#include "src/Args.h"
#include "src/Lexer.h"
#include "src/TokensPrinter.h"

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);
		auto input = OpenFile(args.inputFilename);

		auto const tokens = Lexer::Parse(input);
		TokensPrinter::Print(std::cout, tokens);
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
