#include <string>
#include <iostream>

#include "StrOutLib.h"

int main()
{
	StrOutLib strOut;
	strOut.write("Console is the default output device");

	// For file output a filename must be set and the output device must be set to FILE
	strOut.setFileName("test1.txt");
	strOut.setOutputDevice(StrOutLib::FILE);
	strOut.write("Writing to a file.");

	// We can also use the convenient constructor that takes a filename to set it to file output
	StrOutLib fileOut("test2.txt");
	fileOut.write("Writing to another file.");

	std::cin.get();

	return 0;
}