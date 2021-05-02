#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_
#include <iostream>
using namespace std;
struct mark{
	double totalMark;
	double midtermMark;
	double finalMark;
	double otherMark;
};
struct scoreboard {
	string fullname;
	string sClass;
	string ID;
	int no;
	mark score;
};
struct gpa{
	double first;
	double second;
	double third;
	double overall;
};
void viewScoreBoardOfCourse(char nameYear[], char nameSemester[], char nameCourse[]);
void updateStudentResult(char nameYear[], char nameSemester[], char nameCourse[],string nameStudent );
void viewScoreBoardOfClass(string nameYear, string nameSemester,string nameClass);
void importStudentToCSV( char nameyear[], char namesemester[], char namecourse[]) ;
void importScoreboard(char nameyear[], char namesemester[], char namecourse[]);

#endif
