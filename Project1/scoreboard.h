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
	double first=-1;
	double second=-1;
	double third=-1;
	double overall;
};

#endif
