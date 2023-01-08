#include "Args.h"

Args ParseArgs(int argc, char** argv)
{
	if (argc != 2)
	{
		throw std::invalid_argument("invalid input arguments");
	}

	return {
		.inputFilename = argv[1]
	};
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
