#include "Enrollments.h"

void Enrollments::enroll(Student *student, Course *course)
{
	mCourseToStudents[course].insert(student);
	mStudentToCourses[student].insert(course);
}

void Enrollments::disenroll(Student *student, Course *course)
{
	mCourseToStudents[course].erase(student);
	mStudentToCourses[student].erase(course);
}

void Enrollments::disenroll(Student *student)
{
	mStudentToCourses.erase(student);
	for(auto i = mCourseToStudents.begin(); i != mCourseToStudents.end(); ++i)
	{
		i->second.erase(student);
	}
}

void Enrollments::disenroll(Course *course)
{
	mCourseToStudents.erase(course);
	for(auto i = mStudentToCourses.begin(); i != mStudentToCourses.end(); ++i)
	{
		i->second.erase(course);
	}
}

std::set<Student *> Enrollments::getStudents(Course *course) const
{
	auto students = mCourseToStudents.find(course);
	if(students == mCourseToStudents.end())
	{
		std::set<Student *> empty;
		return empty;
	}
	else
	{
		return students->second;
	}
}

std::set<Course *> Enrollments::getCourses(Student *student) const
{
	auto courses = mStudentToCourses.find(student);
	if(courses == mStudentToCourses.end())
	{
		std::set<Course *> empty;
		return empty;
	}
	else
	{
		return courses->second;
	}
}

std::set<Student *> Enrollments::getAllStudents() const
{
	std::set<Student *> students;
	for(auto i = mStudentToCourses.begin(); i != mStudentToCourses.end(); ++i)
	{
		students.insert(i->first);
	}
	return students;
}

std::set<Course *> Enrollments::getAllCourses() const
{
	std::set<Course *> courses;
	for(auto i = mCourseToStudents.begin(); i != mCourseToStudents.end(); ++i)
	{
		courses.insert(i->first);
	}
	return courses;
}