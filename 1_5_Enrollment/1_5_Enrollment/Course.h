#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
	Course(std::string id, std::string name);
	std::string getId() const;
	void setId(std::string id);
	std::string getName() const;
	void setName(std::string name);

private:
	std::string mId;
	std::string mName;
};

#endif // COURSE_H