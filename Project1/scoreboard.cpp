#include <iostream>
#include <fstream>
#include "gotoXY.h"
#include <string.h>
#include "scoreboard.h"
using namespace std;


void viewScoreBoardOfCourse(string nameYear, string nameSemester, string nameCourse){

	ifstream fin;
	fin.open( nameYear + '-' + nameSemester + '-' + nameCourse+'-'+"score.txt");
	//fin.open("2021-2-cs162-score.txt");
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to back";
		string u;
		cin >> u;
		return;
	}
	int n;
	fin>>n;
	fin.ignore();
	string nothing;
	char nothing1;
	int count =1;
	scoreboard* source;
	source = new scoreboard[n];
	for (int i = 0; i < n; ++i)
	{   
	    source[i].no=count;
		getline(fin, source[i].ID, ',');
		getline(fin, source[i].fullname, ',');
		fin.ignore();
		getline(fin, source[i].sClass, ',');
		fin >> source[i].score.midtermMark;
		fin >> nothing1;
		fin >> source[i].score.finalMark;
		fin >> nothing1;
		fin >> source[i].score.otherMark;
		fin >> nothing1;
		fin >> source[i].score.totalMark;
		fin>>nothing1;
		getline(fin,nothing,'\n');
	    count++;
}
	
	int column = 11, row = 5;
	gotoXY(column,row);
	cout<<"no";
	gotoXY(column+10, row);
	cout << "ID";
	gotoXY(column + 20, row);
	cout << "Fullname";
	gotoXY(column + 30, row);
	cout << "Midterm";
	gotoXY(column + 60, row);
	cout << "Final";
	gotoXY(column + 70, row);
	cout << "Other";
	gotoXY(column + 80, row);
	cout << "Total";
	row++;
	for (int i = 0; i < n; i++) {
        gotoXY(column,row);
        cout<<source[i].no;
		gotoXY(column+10, row);
		cout << source[i].ID;
		gotoXY(column + 20, row);
		cout << source[i].fullname;
		gotoXY(column + 50, row);
		cout << source[i].score.midtermMark;
		gotoXY(column + 60, row);
		cout << source[i].score.finalMark;
		gotoXY(column + 70, row);
		cout << source[i].score.otherMark;
		gotoXY(column + 80, row);
		cout << source[i].score.totalMark;
		row++;

	}
   
	delete[]source;
	return;		
	}
void viewScoreBoardOfClass(string nameYear, string nameSemester,string nameClass){

	ifstream fin;
	fin.open( nameYear + '-' + nameSemester + '-' + nameClass+'-'+"score.txt");
	
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to back";
		string u;
		cin >> u;
		return;
	}
	int n;
	fin>>n;
	fin.ignore();
	string nothing;
	char nothing1;
	int count =1;
	scoreboard* source;
	source = new scoreboard[n];
	
	delete[]source;
	return;		
	}
		
