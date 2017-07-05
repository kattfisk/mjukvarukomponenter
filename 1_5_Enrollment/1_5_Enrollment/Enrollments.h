#ifndef Enrollments_H
#define Enrollments_H

#include <set>
#include <map>
#include <vector>

class Student;
class Course;

class Enrollments
{
public:
	void enroll(Student *student, Course *course);
	void disenroll(Student *student, Course *course);
	void disenroll(Student *student);
	void disenroll(Course *course);
	std::set<Student *> getStudents(Course *course) const;
	std::set<Course *> getCourses(Student *student) const;
	std::set<Student *> getAllStudents() const;
	std::set<Course *> getAllCourses() const;

private:
	std::map<Course *, std::set<Student *>> mCourseToStudents;
	std::map<Student *, std::set<Course *>> mStudentToCourses;

};

#endif // Enrollments_H