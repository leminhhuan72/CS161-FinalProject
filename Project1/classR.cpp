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