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

#endif
