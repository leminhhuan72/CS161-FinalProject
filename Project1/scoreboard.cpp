#include <iostream>
#include "student.h"
#include <fstream>
#include "gotoXY.h"
#include <string.h>
#include "scoreboard.h"
using namespace std;

//task 23
void viewScoreBoardOfCourse(char nameYear[], char nameSemester[], char nameCourse[]){

	ifstream fin;
	char end[]="-score.txt";
	char link[]="-";
	strcat(nameYear,link);
	strcat(nameSemester,link);
	strcat(nameCourse,end);
	strcat(nameYear,nameSemester);
	strcat(nameYear,nameCourse);
	fin.open(nameYear);
	//fin.open( nameYear + '-' + nameSemester + '-' + nameCourse+'-'+"score.txt");
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
//task 24	
void updateStudentResult(char nameYear[], char nameSemester[], char nameCourse[],string nameStudent )
//one course only
{
	
	ifstream fin;
	char end[]="-score.txt";
	char link[]="-";
	strcat(nameYear,link);
	strcat(nameSemester,link);
	strcat(nameCourse,end);
	strcat(nameYear,nameSemester);
	strcat(nameYear,nameCourse);
	fin.open(nameYear);
	//fin.open( nameYear + '-' + nameSemester + '-' + nameCourse+'-'+"score.txt");
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
fout.open(nameYear);
//fout.open(nameYear + '-' + nameSemester + '-' + nameCourse+'-'+"score.txt");
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
//task 25 , havent finished
void viewScoreBoardOfClass(string nameYear, string nameSemester,string nameClass){

	ifstream fin;
	//fin.open( nameYear + '-' + nameSemester + '-' + nameClass+'-'+"score.txt");
	
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to return back";
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
//task 21
void exportStudentToCSV( char nameyear[], char namesemester[], char namecourse[]) 
{   
    
    char link[] ="-";
    char end[]=".txt";
    strcat(nameyear,link);
    strcat(namesemester,link);
    strcat(nameyear,namesemester);
    strcat(nameyear,namecourse);
    char copy[1000];
    strcpy(copy,nameyear);
    char end1[]="-studentList.txt";
    strcat(copy,end1);
    strcat(nameyear,end);
	ifstream fin;
	ofstream fout;
	int count;
	fin.open( nameyear);
	student* pStudent = new student[1000];
	//fin.open( nameyear + '-' + namesemester + '-' + namecourse+'-'+".txt");
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;
	}
	else{
		int i=0;
	
		fin>>count;
	fin.ignore();
		while (!fin.eof()){
			inputAStudent(pStudent[i],fin);	
			i++;
			
		}
		fin.close();
	}
		fout.open(copy);
		if (!fout.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;}
		else{
			int i=0;
			fout<<count<<endl;
			for(int i=0;i<count;i++){
			
			fout<<pStudent[i].First_name<<" "<<pStudent[i].Last_name<<","<<pStudent[i].StudentID<<endl;
		}
	}
		fout.close();
}
//task 22
void importScoreboard(char nameyear[], char namesemester[], char namecourse[]){

    char link[] ="-";
    char end[]="-mark.txt";
    strcat(nameyear,link);
    strcat(namesemester,link);
    strcat(nameyear,namesemester);
    strcat(nameyear,namecourse);
    char copy[100];
    char copy1[100];
    strcpy(copy,nameyear);
    strcpy(copy1,nameyear);
    char end1[]="-studentList.txt";
    char end2[]="-score.txt";
    strcat(copy,end1);
    strcat(nameyear,end);
    strcat(copy1,end2);
	ifstream fin;
	ofstream fout;
	char nothing;
	int count=0;
	
	student* pStudent = new student[1000];
		mark* pMark = new mark[1000];
	fin.open( copy);
	//fin.open( nameyear + '-' + namesemester + '-' + namecourse+'-'+".txt");
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;
	}
	else{
	int i=0;		
	fin>>count;
	fin.ignore();
		while (!fin.eof()){
			inputAStudent(pStudent[i],fin);	
			i++;
		}
}
fin.close();
fin.open(nameyear);
if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;
	}
	else{
		int j=0;
		fin>>count;
	
		while (!fin.eof()){
			fin>>pMark[j].midtermMark>>nothing>>pMark[j].finalMark>>nothing>>pMark[j].otherMark>>nothing>>pMark[j].totalMark;	
			j++;
		}
		
	}
fin.close();
// luu vao file score
	fout.open(copy1);
	if (!fout.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;}
		else{

			fout<<count<<endl;
			for(int i=0;i<count;i++){
			
			fout<<pStudent[i].StudentID<<","<<pStudent[i].First_name<<" "<<pStudent[i].Last_name<<","<<pStudent[i].sclass<<","<<pMark[i].midtermMark;
			fout<<","<<pMark[i].finalMark<<","<<pMark[i].otherMark<<","<<pMark[i].totalMark<<endl;
		}
	}
		fout.close();
}
//task 26
void viewPriScoreBoard(char nameYear[], char nameSemester[]){
	
}
