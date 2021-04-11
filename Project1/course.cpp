#include <iostream>
#include <fstream>
#include "course.h"
using namespace std;

void courseRegis(course totalCourse) // 7
{
	cout << "Please input the name of the new course(EX:CS162): ";
	string name;
	int count = 0;
	cin.ignore();
	cin.getline( name, '\n');
	//type of struct related to course 
	course* cur = nullptr;
	//a pointer points to list of course TotalCourse
	if (totalCourse != nullptr) {
		cur = totalCourse;
		while (cur != nullptr) {
			if (cur->name == name) {
				cout << "This course was avaliable!" << endl;
				cout<<"enter any character to return back"
				string u;
				cin >> u;
				return;
			}
			count++;
			cur = cur->pNext;
		}
		cur = totalCourse;
		while (cur->pNext != nullptr) {
			cur = cur->pNext;
		}
		count = count + 1;
		cur->pNext = new course;
		cur = cur->pNext;
		cur->num = count;
		cur->name = name;
		cout << "Full name: "<<endl;
		cin.get(cur->fullname,'\n')
		cout << "Classroom: "<,endl;
		cin.ignore();
		cin.get(cur->classroom,'\n')
		cout<<"this course is intended for class :"<<endl;
		cin.ignore();
		cin.get(cur->clas,'\n')
		
		cout << "Lecturer: " << endl;
		cout << "  Username: "<<endl;
		getline(cin, cur->lecturer.username, '\n');
		cout << "  Name: "<<endl;
		getline(cin, cur->lecturer.name, '\n');
		cout << "  Degree: "<<endl;
		getline(cin, cur->lecturer.degree, '\n');
		cout << "  Gender: "<<endl;
		getline(cin, cur->lecturer.gender, '\n');
		cout << "Started Date(date): "<<endl;
		cin >> cur->startdate.d;
		cout << "Started Date(month): "<<endl;
		cin >> cur->startdate.m;
		cout << "Started Date(year): "<<endl;
		cin >> cur->startDate.y;
		cout << "Finished Date(date): "<<endl;
		cin >> cur->finishDate.d;
		cout << "Finished Date(month): "<<endl;
		cin >> cur->finishDate.m;
		cout << "Finished Date(year): "<<endl;
		cin >> cur->finishDate.y;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->startTime.h;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->startTime.m;
		cout << "Finished Hour(hour): "<<endl;
		cin >> cur->finishTime.h;
		cout << "Finished Hour(minute): "<<endl;
		cin >> cur->finishTime.m;
		cout<<"First session performed on: "<<endl;
		cin.ignore();
		cin.getline(cur->first.day,'\n');
		cout<<"What time that session occurred: "<<endl
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->first.day.time.h;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->first.day.time.m;
		cout<<"Seconde session performed on: "<<endl;
		cin.ignore();
		cin.getline(cur->second.day,'\n');
		cout<<"What time that session occurred: "<<endl
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->second.day.time.h;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->second.day.time.m;
		
	}
	else {
		cur = new courseStruct;
		count = 1;
		cur->num = count;
		cur->name = name;
		cout << "Full name: ";
		
	cin.get(cur->fullname,'\n')
		cout << "Classroom: ";
		cin.ignore();
		cin.get(cur->classroom,'\n')
		cout<<"this course is intended for class :"
		cin.ignore();
		cin.get(cur->clas,'\n')
		
		cout << "Lecturer: " << endl;
		cout << "  Username: ";
		getline(cin, cur->lecturer.username, '\n');
		cout << "  Name: ";
		getline(cin, cur->lecturer.name, '\n');
		cout << "  Degree: ";
		getline(cin, cur->lecturer.degree, '\n');
		cout << "  Gender: ";
		getline(cin, cur->lecturer.gender, '\n');
		cout << "Started Date(date): ";
		cin >> cur->startdate.d;
		cout << "Started Date(month): ";
		cin >> cur->startdate.m;
		cout << "Started Date(year): ";
		cin >> cur->startDate.y;
		cout << "Finished Date(date): ";
		cin >> cur->finishDate.d;
		cout << "Finished Date(month): ";
		cin >> cur->finishDate.m;
		cout << "Finished Date(year): ";
		cin >> cur->finishDate.y;
		cout << "Started Hour(hour): ";
		cin >> cur->startTime.h;
		cout << "Started Hour(minute): ";
		cin >> cur->startTime.m;
		cout << "Finished Hour(hour): ";
		cin >> cur->finishTime.h;
		cout << "Finished Hour(minute): ";
		cin >> cur->finishTime.m;
		cout<<"First session performed on: "<<endl;
		cin.ignore();
		cin.getline(cur->first.day,'\n');
		cout<<"What time that session occurred: "<<endl
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->first.day.time.h;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->first.day.time.m;
		cout<<"Seconde session performed on: "<<endl;
		cin.ignore();
		cin.getline(cur->second.day,'\n');
		cout<<"What time that session occurred: "<<endl
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->second.day.time.h;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->second.day.time.m;
		
		pHeadCourse = cur;
		cur = nullptr;
		pHeadCourse->pNext = nullptr;
	}
}
