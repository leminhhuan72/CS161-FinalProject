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
	
		getline(fin,nothing,'\n');
	    count++;
}
	
	int column = 1, row = 5;
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
    fin.close();
	delete[]source;
	return;		
	}
void updateStudentResult(string nameYear, string nameSemester, string nameCourse,string nameStudent )
//one course only
{
	
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
	
		getline(fin,nothing,'\n');
	    count++;
}
for (int j=0;j<n;j++){
	if (nameStudent.compare(source[j].fullname)==0){
		string test;
		cout<<"Do you want to change midterm Mark? If not, press 0 or else press any key"<<endl;
		if (test!="0"){
			cout<<"enter new mark: "<<endl;
			cin>>source[j].score.midtermMark;
		} 
		cout<<"Do you want to change final Mark? If not, press 0 or else press any key"<<endl;
		if (test!="0"){
			cout<<"enter new mark: "<<endl;
			cin>>source[j].score.finalMark;
	}
	    cout<<"Do you want to change other mark? If not, press 0 or else press any key"<<endl;
		if (test!="0"){
			cout<<"enter new mark: "<<endl;
			cin>>source[j].score.otherMark;
}
        cout<<"Do you want to change total Mark? If not, press 0 or else press any key"<<endl;
		if (test!="0"){
			cout<<"enter new mark: "<<endl;
			cin>>source[j].score.totalMark;}
   
    
}
}
 fin.close();
 ofstream fout;
fout.open(nameYear + '-' + nameSemester + '-' + nameCourse+'-'+"score.txt");
fout<<n;
	for (int i = 0; i < n; ++i)
	{ 
    fout<<source[i].ID<<",";
	fout<<source[i].fullname<<",";
	fout<<source[i].sClass<<",";
	fout<< source[i].score.midtermMark;
	fout<< ",";
	fout<< source[i].score.finalMark;
	fout<<",";
	fout<< source[i].score.otherMark;
	fout<<",";
	fin >> source[i].score.totalMark;
	fout<<endl;
	
}
fout.close();
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
		
