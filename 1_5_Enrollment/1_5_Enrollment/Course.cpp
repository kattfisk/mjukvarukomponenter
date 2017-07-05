#include "Course.h"

Course::Course(std::string id, std::string name) :
	mId(id), mName(name)
{
}

std::string Course::getId() const
{
	return mId;
}

void Course::setId(std::string id)
{
	mId = id;
}

std::string Course::getName() const
{
	return mName;
}

void Course::setName(std::string name)
{
	mName = name;
}