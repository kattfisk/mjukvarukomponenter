#ifndef STROUTLIB_H
#define STROUTLIB_H

#include <string>

class StrOutLib
{
public:
	enum OutputDevice { CONSOLE, FILE };
	StrOutLib();
	explicit StrOutLib(StrOutLib::OutputDevice device, std::string filename = "");
	explicit StrOutLib(std::string filename);
	~StrOutLib();
	void setFileName(std::string filename);
	void write(std::string data);
	void setOutputDevice(StrOutLib::OutputDevice device);

private:
	StrOutLib(const StrOutLib&) {}
	// Copying this class does not really make sense
	StrOutLib& operator=(StrOutLib) {}

	struct StrOutLibImpl;
	StrOutLibImpl *mPImpl;
};

#endif // STROUTLIB_H