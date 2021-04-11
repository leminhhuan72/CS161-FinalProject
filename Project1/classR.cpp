#include "classR.h"
#include <iostream>
using namespace std;

void createAClass(string path, classR& _init_, ifstream& fin)
{
	cout << "Load class name from file." << endl;
	fin.open(path);
	if (!fin.is_open())
		cout << "Can't load file." << endl;
	else
	{
		getline(fin, _init_.name);
		fin >> _init_.num_of_students;
		_init_.member = new student[_init_.num_of_students];
		cout << "Load file successfully." << endl;
	}
	fin.close();
}
void addStudent2Class(string path, classR& _this_class_, ifstream& fin)
{
	cout << "Add student to class " << path << endl;
	fin.open(path);
	if (!fin.is_open())
		cout << "Can't load file." << endl;
	else
	{
		for (int i = 0; i < _this_class_.num_of_students; i++)
			inputAStudent(_this_class_.member[i], fin);
		cout << "Add student to class successfully." << endl;
	}
	fin.close();

