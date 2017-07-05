#include "Student.h"
#include "Course.h"
#include "Enrollments.h"

#include <set>
#include <iostream>

void printEnrollments(const Enrollments &enrollments)
{
	std::set<Course*> courses = enrollments.getAllCourses();
	for(Course* course : courses)
	{
		std::cout << "----- " << course->getId() << ": " << course->getName() << " -----\n";
		std::set<Student*> students = enrollments.getStudents(course);
		for(Student* student : students)
		{
			std::cout << student->getName() << "\n";
		}
		std::cout << "\n";
	}
}

int main()
{
	Student *adam = new Student("Adam Naslund", "Kurortsvagen 2");
	Student *erik = new Student("Erik Andersson", "Norra trangallén 6");
	Student *anders = new Student("Anders Eriksson", "Norra trangallén 6");
	Student *peter = new Student("Peter Andersson", "Kurortsvagen 4");

	Course *mjukkomp = new Course("DA327G", "Mjukvarukomponenter i C++");
	Course *linalg = new Course("MA142G", "Linjar algebra");

	Enrollments ht2013;

	ht2013.enroll(adam, mjukkomp);
	ht2013.enroll(erik, mjukkomp);
	ht2013.enroll(anders, mjukkomp);
	ht2013.enroll(peter, mjukkomp);

	ht2013.enroll(adam, linalg);
	ht2013.enroll(erik, linalg);
	ht2013.enroll(anders, linalg);
	ht2013.enroll(peter, linalg);

	printEnrollments(ht2013);

	std::cout << "\n### Removing Anders from DA327G. ###\n";
	ht2013.disenroll(anders, mjukkomp);
	printEnrollments(ht2013);

	std::cout << "\n### Removing Peter from all courses. ###\n";
	ht2013.disenroll(peter);
	printEnrollments(ht2013);

	std::cout << "\n### Removing all students from MA142G. ###\n";
	ht2013.disenroll(linalg);
	printEnrollments(ht2013);

	std::cin.get();

	return 0;
}