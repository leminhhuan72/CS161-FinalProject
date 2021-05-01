#include "course.h"
using namespace std;

void courseRegis(course*& totalCourse)  // 7
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
        cout << "This course is already added !" << endl;
        cout << "enter any character to return back";
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
    cout << "Full name: " << endl;
    getline(cin, cur->fullname, '\n');
    cout << "Classroom: " << endl;
    cin.ignore();
    getline(cin, cur->classroom, '\n');
    cout << "this course is intended for class :" << endl;
    cin.ignore();
    getline(cin, cur->clas, '\n');

    cout << "Lecturer: " << endl;
    cout << "  Username: " << endl;
    getline(cin, cur->lecturer.username, '\n');
    cout << " Full Name: " << endl;
    getline(cin, cur->lecturer.name, '\n');
    cout << "  Degree: " << endl;
    getline(cin, cur->lecturer.degree, '\n');
    cout << "  Gender: " << endl;
    getline(cin, cur->lecturer.gender, '\n');
    inputADateFromConsole(cur->startDate, "Started Date");
    inputADateFromConsole(cur->finishDate, "Finished Date");
    cout << "Started Hour(hour): " << endl;
    cin >> cur->startTime.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->startTime.minu;
    cout << "Finished Hour(hour): " << endl;
    cin >> cur->finishTime.hour;
    cout << "Finished Hour(minute): " << endl;
    cin >> cur->finishTime.minu;
    cout << "First session performed on: " << endl;
    cin.ignore();
    inputADateFromConsole(cur->first.day);
    cout << "What time that session occurred: " << endl;
    cout << "Started Hour(hour): " << endl;
    cin >> cur->first.time.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->first.time.minu;
    cout << "Seconde session performed on: " << endl;
    cin.ignore();
    inputADateFromConsole(cur->second.day);
    cout << "What time that session occurred: " << endl;
    cout << "Started Hour(hour): " << endl;
    cin >> cur->second.time.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->second.time.minu;

  } else {
    cur = new course;
    count = 1;
    cur->num = count;
    cur->name = name;
    cout << "Full name: " << endl;
    getline(cin, cur->fullname, '\n');
    cout << "Classroom: " << endl;
    cin.ignore();
    getline(cin, cur->classroom, '\n');
    cout << "this course is intended for class :" << endl;
    cin.ignore();
    getline(cin, cur->clas, '\n');

    cout << "Lecturer: " << endl;
    cout << "  Username: " << endl;
    getline(cin, cur->lecturer.username, '\n');
    cout << "  Name: " << endl;
    getline(cin, cur->lecturer.name, '\n');
    cout << "  Degree: " << endl;
    getline(cin, cur->lecturer.degree, '\n');
    cout << "  Gender: " << endl;
    getline(cin, cur->lecturer.gender, '\n');
    inputADateFromConsole(cur->startDate, "Started Date");
    inputADateFromConsole(cur->finishDate, "Finished Date");
    cout << "Started Hour(hour): " << endl;
    cin >> cur->startTime.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->startTime.minu;
    cout << "Finished Hour(hour): " << endl;
    cin >> cur->finishTime.hour;
    cout << "Finished Hour(minute): " << endl;
    cin >> cur->finishTime.minu;
    cout << "First session performed on: " << endl;
    cin.ignore();
    inputADateFromConsole(cur->first.day);
    cout << "What time that session occurred: " << endl;
    cout << "Started Hour(hour): " << endl;
    cin >> cur->first.time.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->first.time.minu;
    cout << "Seconde session performed on: " << endl;
    cin.ignore();
    inputADateFromConsole(cur->second.day);
    cout << "What time that session occurred: " << endl;
    cout << "Started Hour(hour): " << endl;
    cin >> cur->second.time.hour;
    cout << "Started Hour(minute): " << endl;
    cin >> cur->second.time.minu;

    totalCourse = cur;
    cur = nullptr;
    totalCourse->pNext = nullptr;
  }
}
void storecoursesList(course* totalCourse, semester recent) {
  string path = "./course/" + recent._this_year->schoolYrNo + to_string(recent.No) + ".txt";
  ofstream fout;
  fout.open(path, ios::app);
  if (!fout.is_open()) {
    cout << "can not open the text file to store the course information";
  } else {
  }

  fout.close();
}