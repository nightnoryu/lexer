#pragma once

#include <fstream>
#include <stdexcept>
#include <string>

struct Args
{
	std::string inputFilename;
};

Args ParseArgs(int argc, char** argv);
std::ifstream OpenFile(std::string const& filename);
