#include "src/Lexer.h"
#include "src/TokensPrinter.h"
#include <fstream>

std::string GetInputFilename(int argc, char** argv);
std::ifstream OpenFile(std::string const& filename);

int main(int argc, char** argv)
{
	try
	{
		auto const inputFilename = GetInputFilename(argc, argv);
		auto input = OpenFile(inputFilename);

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

std::string GetInputFilename(int argc, char** argv)
{
	if (argc != 2)
	{
		throw std::invalid_argument("invalid input arguments");
	}

	return argv[1];
}

std::ifstream OpenFile(std::string const& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		throw std::runtime_error("failed to open input file");
	}

	return file;
}
