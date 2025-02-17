#pragma once
#include <iostream>
using namespace std;
class Teachers
{
public:
	string teacher_name;
	int teacher_id;
	int course_id;
	int room_id;
	int module_id;
	string day;
	int period;
};
class Student
{
public:
	string student_name;
	int student_id;
	int course_id;
};
class Course
{
public:
	string course_name;
	int course_id;
};
class Room
{
public:
	int room_id;
	int course_id;
	string course_name;
};
class Module
{
public:
	int module_id;
	string module_name;
	int course_id;
};
