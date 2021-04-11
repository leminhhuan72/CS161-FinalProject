#include "student.h"
#include "Date.h"
#include "classR.h"
#include <iostream>
/*
try to figure out and write all functions of
Viet Hoang : Student
My ky : Class
thai viet nhat : school year
minh huan : semester
**note : don't change the include
 - if there is something not clear, let's have a dicussion
 = pull request only after a coding session
 - if you have something uncertain about git / github (i.e : how to update your local respo ,..., d.m me )
*/
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	classR apcs1, apcs2, clc1, clc2, vp;
	createAClass("20APCS1.txt", apcs1, fin);
	addStudent2Class("20APCS1.txt", apcs2, fin);
	createAClass("20APCS2.txt", apcs2, fin);
	addStudent2Class("20APCS2.txt", apcs2, fin);
	createAClass("20CLC1.txt", clc1, fin);
	addStudent2Class("20CLC1.txt", apcs2, fin);
	createAClass("20CLC2.txt", clc2, fin);
	addStudent2Class("20CLC2.txt", apcs2, fin);
	createAClass("20VP.txt", vp, fin);
	addStudent2Class("20VP.txt", apcs2, fin);
	return 0;
}