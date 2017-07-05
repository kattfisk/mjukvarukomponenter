#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
	Student(std::string name, std::string address);
	std::string getName() const;
	void setName(std::string name);
	std::string getAddress() const;
	void setAddress(std::string address);

private:
	std::string mName;
	std::string mAddress;
};

#endif // STUDENT_H