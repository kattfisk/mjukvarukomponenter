#include "Student.h"

Student::Student(std::string name, std::string address) :
	mName(name), mAddress(address)
{
}

std::string Student::getName() const
{
	return mName;
}

void Student::setName(std::string name)
{
	mName = name;
}

std::string Student::getAddress() const
{
	return mAddress;
}

void Student::setAddress(std::string address)
{
	mAddress = address;
}