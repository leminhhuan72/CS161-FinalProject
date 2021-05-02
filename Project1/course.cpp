#include "course.h"
using namespace std;

void courseRegis(course*& totalCourse)  // 7
{
  cout << "Please input the code of the new course(EX:CS162): ";
  string name;
  int count = 0;
  cin >> ws;
  getline(cin, name, '\n');
  cout << name;
  //type of struct related to course
  course* cur = nullptr;
  //a pointer points to list of course TotalCourse
  if (totalCourse != nullptr) {
    cur = totalCourse;
    while (cur != nullptr) {
      if (cur->ID == name) {
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
    cur->ID = name;
    cout << "Full name: " << endl;
    getline(cin, cur->fullname, '\n');
    cout << "How many creadits does this course have ?" << endl;
    cin >> cur->numOfCredits;
    cout << "How many students maximum does this course have ? " << endl;
    cin >> cur->maxStudent;
    cout << "Classroom: " << endl;
    cin.ignore();
    getline(cin, cur->classroom, '\n');

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
    cout << "First session performed on: " << endl;
    cin.ignore();
    getline(cin, cur->first.day_in_week);
    cout << "Which shift that session occurred (1: 7:30, 2: 9:30 , 3: 1:30, 4: 15:30): " << endl;
    cin >> cur->first.shift;
    cout << "Seconde session performed on: " << endl;
    cin.ignore();
    getline(cin, cur->second.day_in_week);
    cout << "Which shift that session occurred (1: 7:30, 2: 9:30 , 3: 1:30, 4: 15:30): " << endl;
    cin >> cur->second.shift;
  } else {
    cur = new course;
    count = 1;
    cur->num = count;
    cur->ID = name;
    cout << "Full name: " << endl;
    getline(cin, cur->fullname, '\n');
    cout << "How many credits does this course have ?" << endl;
    cin >> cur->numOfCredits;
    cout << "How many students maximum does this course have ? " << endl;
    cin >> cur->maxStudent;
    cout << "Classroom: " << endl;
    cin.ignore();
    getline(cin, cur->classroom, '\n');
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
    cout << "First session performed on: " << endl;
    cin.ignore();
    getline(cin, cur->first.day_in_week);
    cout << "Which shift that session occurred (1: 7:30, 2: 9:30 , 3: 1:30, 4: 15:30): " << endl;
    cin >> cur->first.shift;
    cout << "Seconde session performed on: " << endl;
    cin.ignore();
    getline(cin, cur->second.day_in_week);
    cout << "Which shift that session occurred (1: 7:30, 2: 9:30 , 3: 1:30, 4: 15:30): " << endl;
    cin >> cur->second.shift;

    totalCourse = cur;
    cur = nullptr;
    totalCourse->pNext = nullptr;
  }
}
bool storecoursesList(course* totalCourse, semester recent) {
  course* cur = totalCourse;
  string path = "./course/" + recent._this_year->schoolYrNo + to_string(recent.No) + ".txt";
  ofstream fout;
  fout.open(path, ios::app);
  if (!fout.is_open()) {
    cout << "can not open the text file to store the course information";
    return false;
  } else {
    while (cur != nullptr) {
      fout << cur->ID << endl;
      fout << cur->fullname << endl;
      fout << cur->numOfCredits << endl;
      fout << cur->maxStudent << endl;
      fout << cur->classroom << endl;
      fout << cur->lecturer.username << endl;
      fout << cur->lecturer.name << endl;
      fout << cur->first.day_in_week << endl;
      fout << cur->first.shift << endl;
      fout << cur->second.day_in_week << endl;
      fout << cur->second.shift << endl;
      cur = cur->pNext;
      // total line: 11
    }
  }

  fout.close();
  return true;
}