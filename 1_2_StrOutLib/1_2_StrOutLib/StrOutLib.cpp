#include "StrOutLib.h"

#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

struct StrOutLib::StrOutLibImpl
{
	std::string mBuffer;
	std::string mFilename;
	StrOutLib::OutputDevice mOutDev;
	std::ofstream mFstream;

	StrOutLibImpl(StrOutLib::OutputDevice outputDevice = StrOutLib::CONSOLE, std::string filename = "")
		: mBuffer(), mFilename(filename), mOutDev(outputDevice), mFstream()
	{
	}

	void write()
	{
		if(mOutDev == StrOutLib::CONSOLE)
		{
			std::cout << mBuffer;
			mBuffer.clear();
		}
		else if(mOutDev == StrOutLib::FILE)
		{
			assert(!mFilename.empty());
			// In lieu of throwing an exception we just don't write anything if a filename is missing
			if(!mFilename.empty())
			{
				mFstream.open(mFilename);
				mFstream << mBuffer;
				mFstream.close();
			}
		}
	}
};

StrOutLib::StrOutLib()
	: mPImpl(new StrOutLibImpl())
{
}

StrOutLib::StrOutLib(StrOutLib::OutputDevice device, std::string filename)
	: mPImpl(new StrOutLibImpl(device, filename))
{
}

StrOutLib::StrOutLib(std::string filename)
	: mPImpl(new StrOutLibImpl(StrOutLib::FILE, filename))
{
}

StrOutLib::~StrOutLib()
{
	delete mPImpl;
	mPImpl = 0;
}

void StrOutLib::setFileName(const std::string filename)
{
	mPImpl->mFilename = filename;
}

void StrOutLib::write(const std::string data)
{
	mPImpl->mBuffer += data;
	mPImpl->write();
}

void StrOutLib::setOutputDevice(StrOutLib::OutputDevice device)
{
	mPImpl->mOutDev = device;
}