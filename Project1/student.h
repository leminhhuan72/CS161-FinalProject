#ifndef _STUDENT_H_
#define _STUDENT_H_
//#include "course.h"
#include "date.h"

struct accountInfo {
  string name;
  string pass;
};
struct student {
  int No;
  string StudentID;
  string First_name;
  string Last_name;
  int Gender;  // 0: female , 1: male
  Date Date_of_Birth;
  string SocialID;
  string userName;
  int* courseNo;
  ~student() {
    delete[] courseNo;
  }
  //string sclass; ?
  //input a student
};

void inputAStudent(student& a, ifstream& fin);
void saveAStudent(student& a, ofstream& fout);
void outputAStudent(student& a, ofstream& fout);
bool studentLogin(string& currentUser);
bool staffLogin(string& currentUser);
bool changePass(string currentPass, string newPass);
//oid enrollACourse(course* list_of_course);
void listOfStudentsInCourse(student*& pStudent, string nameyear, string namesemester, string namecourse, int& n);
#endif
