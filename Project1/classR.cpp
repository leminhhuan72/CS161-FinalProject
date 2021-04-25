#include "classR.h"
#include <iostream>
using namespace std;

void createAClass(classR& _init_)
{
 cout<<"Type the name of the class\n";
 getline(cin,_init_.name);
 cout<<"How many students are there in this class\n?";
 cin>>_init_.num_of_students;

}

void inputAClass (classR& dest,ifstream & fin )
{
	cout<<"What is the path of the file containing information of all students ? ";
	string path ; 
	getline (cin,path);
	fin.open(path);  
	

	if(!fin.eof())
	{
		dest.member = new student[dest.num_of_students];
         for(int i= 0 ; i < dest.num_of_students;++i)
	    {
		fin>>dest.member[i].No;
		fin.get();
		getline(fin,dest.member[i].StudentID,',');
		getline(fin,dest.member[i].First_name,',');
		getline(fin,dest.member[i].Last_name,',');
		
		// 1,20125033,Le,Minh Huan ,1,24,05,2002,221502615
	     }
	}
	else cout<<"cant not open file \n";
	

}
