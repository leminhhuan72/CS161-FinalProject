#include "course.h"
using namespace std;

void courseRegis(course*& totalCourse)  // 7
{
  cout << "Please input 1 to registrate a course \n 2 to exit \n";
  int n;
  cin >> n;
  while (n != 1 && n != 2) {
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
  }
  while (n == 1) {
    cout << "Please input the code of the new course(EX:CS162): ";
    string name;
    int count = 0;
    cin >> ws;
    getline(cin, name, '\n');
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
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
    while (n != 1 && n != 2) {
      cout << "Please input 1 to registrate a course \n 2 to exit \n";
      cin >> n;
    }
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
bool loadCourses(semester& recent_sem) {
  string path = "./course/" + recent_sem._this_year->schoolYrNo + to_string(recent_sem.No) + ".txt";
  ifstream fin;
  fin.open(path);
  if (fin.is_open()) {
    if (file_is_empty(path))
      return false;
    else {
      recent_sem.list_of_course = new course;
      course* cur = recent_sem.list_of_course;
      while (!fin.eof()) {
        cur->pNext = new course;
        fin >> cur->pNext->ID;
        fin >> ws;
        getline(fin, cur->pNext->fullname);
        fin.get();
        fin >> cur->pNext->numOfCredits;
        fin >> cur->pNext->maxStudent;
        fin >> ws;
        getline(fin, cur->pNext->classroom);
        getline(fin, cur->pNext->lecturer.username);
        getline(fin, cur->pNext->lecturer.name);
        getline(fin, cur->pNext->first.day_in_week);
        fin >> ws;
        fin >> cur->pNext->first.shift;
        getline(fin, cur->pNext->second.day_in_week);
        fin >> ws;
        fin >> cur->pNext->second.shift;
        cur = cur->pNext;
        cur->pNext = nullptr;
      }
      course* tmp = recent_sem.list_of_course;
      recent_sem.list_of_course = recent_sem.list_of_course->pNext;
      delete tmp;
    }
  } else
    return false;
  fin.close();
  return true;
}