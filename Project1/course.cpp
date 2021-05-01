
#define nullptr NULL
#include "course.h"
using namespace std;

void courseRegis(course*& totalCourse) // 7
{
	cout << "Please input the name of the new course(EX:CS162): ";
	string name;
	int count = 0;
	cin.ignore();
	getline(cin, name, '\n');
	//type of struct related to course 
	course* cur = nullptr;
	//a pointer points to list of course TotalCourse
	if (totalCourse != nullptr) {
		cur = totalCourse;
		while (cur != nullptr) {
			if (cur->name == name) {
				cout << "This course was avaliable!" << endl;
				cout<<"enter any character to return back";
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
		getline(cin,cur->fullname,'\n');
		cout << "Classroom: "<<endl;
		cin.ignore();
		getline(cin,cur->classroom,'\n');
		cout<<"this course is intended for class :"<<endl;
		cin.ignore();
		getline(cin,cur->clas,'\n');
		
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
		cin >> cur->startDate.date;
		cout << "Started Date(month): "<<endl;
		cin >> cur->startDate.month;
		cout << "Started Date(year): "<<endl;
		cin >> cur->startDate.year;
		cout << "Finished Date(date): "<<endl;
		cin >> cur->finishDate.date;
		cout << "Finished Date(month): "<<endl;
		cin >> cur->finishDate.month;
		cout << "Finished Date(year): "<<endl;
		cin >> cur->finishDate.year;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->startTime.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->startTime.minu;
		cout << "Finished Hour(hour): "<<endl;
		cin >> cur->finishTime.hour;
		cout << "Finished Hour(minute): "<<endl;
		cin >> cur->finishTime.minu;
		cout<<"First session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->first.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->first.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->first.time.minu;
		cout<<"Seconde session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->second.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->second.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->second.time.minu;
		
	}
	else {
		cur = new course;
		count = 1;
		cur->num = count;
		cur->name = name;
	  cout << "Full name: "<<endl;
		getline(cin,cur->fullname,'\n');
		cout << "Classroom: "<<endl;
		cin.ignore();
		getline(cin,cur->classroom,'\n');
		cout<<"this course is intended for class :"<<endl;
		cin.ignore();
		getline(cin,cur->clas,'\n');
		
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
		cin >> cur->startDate.date;
		cout << "Started Date(month): "<<endl;
		cin >> cur->startDate.month;
		cout << "Started Date(year): "<<endl;
		cin >> cur->startDate.year;
		cout << "Finished Date(date): "<<endl;
		cin >> cur->finishDate.date;
		cout << "Finished Date(month): "<<endl;
		cin >> cur->finishDate.month;
		cout << "Finished Date(year): "<<endl;
		cin >> cur->finishDate.year;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->startTime.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->startTime.minu;
		cout << "Finished Hour(hour): "<<endl;
		cin >> cur->finishTime.hour;
		cout << "Finished Hour(minute): "<<endl;
		cin >> cur->finishTime.minu;
		cout<<"First session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->first.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->first.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->first.time.minu;
		cout<<"Seconde session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->second.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->second.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->second.time.minu;
		
		totalCourse = cur;
		cur = nullptr;
		totalCourse->pNext = nullptr;
	}
}
//task 11
void deleteACourse(course*& totalCourse){
	cout<<"please input the name or the fullname of the course you want to delete: "<<endl;
	string test;
	cin.ignore();
	getline(cin,test,'\n');
	course*cur=totalCourse;
	if(cur==nullptr){
		cout<<"No existed courses to delete, please add some courses"<<endl;
		cout<<"enter any character to return back";
				string u;
				cin >> u;
				return;
	}
		while (cur->pNext != nullptr) {
			if (cur->pNext->name == test||cur->pNext->fullname==test) {
				course* tem=cur->pNext;
				cur->pNext=cur->pNext->pNext;
				delete tem;
				while (cur->pNext!=nullptr){
					cur->pNext->num =cur->pNext->num-1;
					cur=cur->pNext;
				}
				return;
			}
			cur = cur->pNext;
		}
}
//task 10
bool check1(string test){
	if (test=="no"||test=="No"||test=="NO"||test=="nO") return false;
	return true;
}
void updateCourseInfo(course *&totalCourse){
	cout<<"input the name or fullname of course you want to update "<<endl;
	string name1;
	string test1;
	string new1;
	cin.ignore();
	getline(cin,name1);
	course *cur = totalCourse;
	course *cur1= totalCourse;
	if (cur==nullptr){
		cout<<"No existed courses to change information, please add some courses"<<endl;
		cout<<"enter any character to return back";
				string u;
				cin >> u;
				return;
	}
	while (cur!=nullptr){
		if(cur->name==name1||cur->fullname==name1){
			
			cout<<"do you want to update name of course"<<endl;
			getline(cin,test1);
			if (!check1(test1)){
			cout<<"input the name you want to change to: "<<endl;	
			getline(cin,cur->name,'\n');
			}
			cout<<"do you want to update full name of course"<<endl;
			getline(cin,test1);
			if (!check1(test1)){
				cout<<"input the name you want to change to: "<<endl;	
			getline(cin,cur->fullname,'\n');
            }
            cout<<"do you want to update classroom of course"<<endl;
			getline(cin,test1);
			if (!check1(test1)){
				cout<<"input the classroom(ex:I41) you want to change to: "<<endl;	
			getline(cin,cur->classroom,'\n');
		}
		cout<<"do you want to update the class(ex:20ctt1) of course"<<endl;
			getline(cin,test1);
			if (!check1(test1)){
			cout<<"input the class you want to change to: "<<endl;	
			getline(cin,cur->clas,'\n');
			}
			
			cout<<"do you want to update the information of lecturer"<<endl;
			getline(cin,test1);
			if (!check1(test1)){
		cout << "  Username: "<<endl;
		getline(cin, cur->lecturer.username, '\n');
		cout << "  Name: "<<endl;
		getline(cin, cur->lecturer.name, '\n');
		cout << "  Degree: "<<endl;
		getline(cin, cur->lecturer.degree, '\n');
		cout << "  Gender: "<<endl;	
		}
//nothing , rest
        	cout<<"do you want to update the registration days of course"<<endl;
			getline(cin,test1);
			if (!check1(test1)){		
		cout << "Started Date(date): "<<endl;
		cin >> cur->startDate.date;
		cout << "Started Date(month): "<<endl;
		cin >> cur->startDate.month;
		cout << "Started Date(year): "<<endl;
		cin >> cur->startDate.year;
		cout << "Finished Date(date): "<<endl;
		cin >> cur->finishDate.date;
		cout << "Finished Date(month): "<<endl;
		cin >> cur->finishDate.month;
		cout << "Finished Date(year): "<<endl;
		cin >> cur->finishDate.year;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->startTime.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->startTime.minu;
		cout << "Finished Hour(hour): "<<endl;
		cin >> cur->finishTime.hour;
		cout << "Finished Hour(minute): "<<endl;
		cin >> cur->finishTime.minu;}
		   cout<<"do you want to update the time that first session occurred?"<<endl;
		   getline(cin,test1);
		   if(!check1(test1)){
		cout<<"First session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->first.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->first.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->first.time.minu;}
		 cout<<"do you want to update the time that second session occurred?"<<endl;
		   getline(cin,test1);
		   if(!check1(test1)){
		cout<<"Seconde session performed on: "<<endl;
		cin.ignore();
		getline(cin,cur->second.day,'\n');
		cout<<"What time that session occurred: "<<endl;
		cout << "Started Hour(hour): "<<endl;
		cin >> cur->second.time.hour;
		cout << "Started Hour(minute): "<<endl;
		cin >> cur->second.time.minu;
	}
	}
		cur =cur->pNext;
	}
	
}
