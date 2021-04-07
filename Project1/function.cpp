#include <iostream>
#include <fstream>
#include "Header.h"
void inputAStudent(student& a, ifstream& fin)
{
	
fin >> a.No;
a.StudentID = new char[100];
fin.ignore(100, '\n');
fin.get(a.StudentID, 100, '\n');
a.First_name = new char[100];
fin.ignore(100, '\n');
fin.get(a.First_name, 100, '\n');
a.Last_name = new char[100];
fin.ignore(100, '\n');
fin.get(a.Last_name, 100, '\n');
int Gender;
fin >> Gender;
Date Date_of_Birth;
inputaDate(a.Date_of_Birth, fin);
a.SocialID = new char[100];
fin.ignore(100, '\n');
fin.get(a.SocialID, 100, '\n');

}
void inputaDate(Date& Date_of_Birth,ifstream& fin);
