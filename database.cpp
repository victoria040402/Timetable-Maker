#include <iostream>
#include "sqlite/sqlite3.h"
#include <string>
#include <assert.h>
#include <stdio.h>
#include "Class.h"
using namespace std;
static int createTables(const char* s);
static int insertData(const char* s);
static int selectData(const char* s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int createDB(const char* s);
string student_name;
int student_id, course_id;
int main(int argc, char** argv)
{
	const char* dir = "C:\\Users\\victo\\Desktop\\Project\\Project\\UniTimetable.db";
	sqlite3* db;
	createDB(dir);
	createTables(dir);
	insertData(dir);
	selectData(dir);
	Student studentA;
	return 0;
}
static int createDB(const char* s)
{
	sqlite3* db;
	int exit = 0;
	exit = sqlite3_open("UniTimetable.db", &db);
	sqlite3_close(db);
	return 0;
}
static int insertData(const char* s)
{
	sqlite3* db;
	string sql="INSERT INTO TEACHERS(TEACHER_ID, TEACHER_NAME, ROOM_ID, CLASS_ID, DAY, TIME) VALUES(1, 'Mr Smith', 1, 1, 'Monday', '9am-12pm'),"
		"(1, 'Mr Smith', 2, 1, 'Tuesday', '9am-12pm'),"
		"(1, 'Mr Smith', 1, 2, 'Wednesday', '12pm-2pm'),"
		"(1, 'Mr Smith', 3, 1, 'Thursday', '9am-12pm'),"
		"(2, 'Mrs Potts', 2, 3, 'Monday', '12pm-2pm'),"
		"(2, 'Mrs Potts', 1, 1, 'Tuesday', '12pm-2pm'),"
		"(2,'Mrs Potts', 2, 1, 'Wednesday ', '4pm-6pm'),"
		"(2, 'Mrs Potts', 1, 4, 'Friday', '12pm-2pm'),"
		"(3, 'Mr Robinson', 1, 1, 'Monday', '2pm-4pm'),"
		"(3, 'Mr Robinson', 2, 5, 'Tuesday', '12pm-2pm'),"
		"(3, 'Mr Robinson', 1, 1, 'Wednesday', '9am-12pm'),"
		"(3, 'Mr Robinson', 1, 1, 'Thursday', '2pm-4pm'),"
		"(4, 'Miss Jensen', 3, 1, 'Monday', '12pm-2pm'),"
		"(4, 'Miss Jensen', 3, 1, 'Tuesday', '12pm-2pm'),"
		"(4, 'Miss Jensen', 2, 6, 'Wednesday', '2pm-4pm'),"
		"(4, 'Miss Jensen', 3, 1, 'Friday', '9am-12pm'),"
		"(5, 'Mrs Marlow', 2, 1, 'Monday', '4pm-6pm'),"
		"(5, 'Mrs Marlow', 3, 5, 'Wednesday', '4pm-6pm'),"
		"(5, 'Mrs Marlow', 2, 1, 'Thursday', '9am-12pm'),"
		"(5, 'Mrs Marlow', 2, 1, 'Friday', '12pm-2pm');";
	char* messaggeError;
	int exit = sqlite3_open("UniTimetable.db", &db);
	if (exit != SQLITE_OK) {
		cerr << "Error insert" << endl;
		sqlite3_free(&messaggeError);
	}
	else
		cout << "Data inserted successfully" << endl;
	sql = "insert into ROOMS VALUES (" + to_string(1) + ", " +to_string(1)+";";
	sql = "insert into ROOMS VALUES (" + to_string(2) + ", "+ to_string(1)+";";
	sql = "insert into ROOMS VALUES (" + to_string(3) + ", "+to_string(1)+");";
	sql = "insert into ROOMS VALUES (" + to_string(4) + ", "+to_string(2)+");";
	if (exit != SQLITE_OK) {
		cerr << "Error insert" << endl;
		sqlite3_free(&messaggeError);
	}
	else
		cout << "Data inserted successfully" << endl;
	sql = "insert into MODULES VALUES (" + to_string(1) + ", " + to_string(1) + ", 'Computer Science', 'Object Oriented Programming');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into MODULES VALUES (" + to_string(1) + ", " + to_string(1) + ", 'Computer Science', 'Programming Algorithms');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into MODULES VALUES (" + to_string(1) + ", " + to_string(1) + ", 'Computer Science', 'Databases');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into MODULES VALUES (" + to_string(1) + ", " + to_string(1) + ", 'Computer Science', 'Software Design');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into MODULES VALUES (" + to_string(1) + ", " + to_string(1) + ", 'Computer Science', 'Computer Arcitechture and Networks');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into CLASSES VALUES(" + to_string(1) + ", " + to_string(1) + ", 'Henry Mills');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into CLASSES VALUES(" + to_string(1) + ", " + to_string(2) + ", 'David Nolan');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into CLASSES VALUES(" + to_string(1) + ", " + to_string(3) + ", 'Emma Swan');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into CLASSES VALUES(" + to_string(1) + ", " + to_string(4) + ", 'Cillian Jones');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "insert into CLASSES VALUES(" + to_string(1) + ", " + to_string(5) + ", 'Mary Blanchard');";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sqlite3_close(db);
	return 0;
}

static int selectData(const char* s)
{
	sqlite3* db;
	int exit = sqlite3_open("UniTimetable.db", &db);
	string sql = "SELECT * FROM CLASSES;";
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	return 0;
}
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}
static int createTables(const char* s)
{
	sqlite3* db;
	string sql = "CREATE TABLE IF NOT EXISTS TEACHERS("
		"TEACHER_ID   INT,"
		"TEACHER_NAME   CHAR(50)   NOT NULL, "
		"ROOM_ID   INT   NOT NULL,"
		"CLASS_ID   INT   NOT NULL,"
		"DAY   TEXT,"
		"TIME   TEXT   NOT NULL,"
		"PRIMARY KEY(TEACHER_ID, DAY) );";
	int exit = 0;
	exit = sqlite3_open("UniTimetable.db", &db);
	char* messaggeError;
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Create Table" << endl;
		sqlite3_free(messaggeError);
	}
	else
		cout << "Tables created successfully" << endl;
	sql= "CREATE TABLE IF NOT EXISTS MODULES("
		"MODULE_ID INT PRIMARY KEY,"
		"COURSE_ID INT NOT NULL,"
		"COURSE_NAME CHAR(50) NOT NULL,"
		"MODULE_NAME CHAR(50) NOT NULL);";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "CREATE TABLE IF NOT EXISTS ROOMS("
		"ROOM_ID    INTEGER PRIMARY KEY,"
		"COURSE_ID   INT    NOT NULL);";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Create Table" << endl;
		sqlite3_free(messaggeError);
	}
	else
		cout << "Tables created successfully" << endl;
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sql = "CREATE TABLE IF NOT EXISTS CLASSES("
		"CLASS_ID INT NOT NULL,"
		"STUDENT_ID INT PRIMARY KEY,"
		"STUDENT_NAME);";
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Create Table" << endl;
		sqlite3_free(messaggeError);
	}
	else
		cout << "Tables created successfully" << endl;
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
	sqlite3_close(db);
	return (0);
}
