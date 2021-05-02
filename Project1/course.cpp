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
//task 11
void deleteACourse(course*& totalCourse) {
  cout << "please input the name or the fullname of the course you want to delete: " << endl;
  string test;
  cin.ignore();
  getline(cin, test, '\n');
  course* cur = totalCourse;
  if (cur == nullptr) {
    cout << "No existed courses to delete, please add some courses" << endl;
    cout << "enter any character to return back";
    string u;
    cin >> u;
    return;
  }
  while (cur->pNext != nullptr) {
    if (cur->pNext->name == test || cur->pNext->fullname == test) {
      course* tem = cur->pNext;
      cur->pNext = cur->pNext->pNext;
      delete tem;
      while (cur->pNext != nullptr) {
        cur->pNext->num = cur->pNext->num - 1;
        cur = cur->pNext;
      }
      return;
    }
    cur = cur->pNext;
  }
}
//task 10
bool check1(string test) {
  if (test == "no" || test == "No" || test == "NO" || test == "nO") return false;
  return true;
}
void updateCourseInfo(course*& totalCourse) {
  cout << "input the name or fullname of course you want to update " << endl;
  string name1;
  string test1;
  string new1;
  cin.ignore();
  getline(cin, name1);
  course* cur = totalCourse;
  course* cur1 = totalCourse;
  if (cur == nullptr) {
    cout << "No existed courses to change information, please add some courses" << endl;
    cout << "enter any character to return back";
    string u;
    cin >> u;
    return;
  }
  while (cur != nullptr) {
    if (cur->name == name1 || cur->fullname == name1) {
      cout << "do you want to update name of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "input the name you want to change to: " << endl;
        getline(cin, cur->name, '\n');
      }
      cout << "do you want to update full name of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "input the name you want to change to: " << endl;
        getline(cin, cur->fullname, '\n');
      }
      cout << "do you want to update classroom of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "input the classroom(ex:I41) you want to change to: " << endl;
        getline(cin, cur->classroom, '\n');
      }
      cout << "do you want to update the class(ex:20ctt1) of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "input the class you want to change to: " << endl;
        getline(cin, cur->clas, '\n');
      }

      cout << "do you want to update the information of lecturer" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "  Username: " << endl;
        getline(cin, cur->lecturer.username, '\n');
        cout << "  Name: " << endl;
        getline(cin, cur->lecturer.name, '\n');
        cout << "  Degree: " << endl;
        getline(cin, cur->lecturer.degree, '\n');
        cout << "  Gender: " << endl;
      }
      //nothing , rest
      cout << "do you want to update the registration days of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "Started Date(date): " << endl;
        cin >> cur->startDate.date;
        cout << "Started Date(month): " << endl;
        cin >> cur->startDate.month;
        cout << "Started Date(year): " << endl;
        cin >> cur->startDate.year;
        cout << "Finished Date(date): " << endl;
        cin >> cur->finishDate.date;
        cout << "Finished Date(month): " << endl;
        cin >> cur->finishDate.month;
        cout << "Finished Date(year): " << endl;
        cin >> cur->finishDate.year;
        cout << "Started Hour(hour): " << endl;
        cin >> cur->startTime.hour;
        cout << "Started Hour(minute): " << endl;
        cin >> cur->startTime.minu;
        cout << "Finished Hour(hour): " << endl;
        cin >> cur->finishTime.hour;
        cout << "Finished Hour(minute): " << endl;
        cin >> cur->finishTime.minu;
      }
      cout << "do you want to update the time that first session occurred?" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "First session performed on: " << endl;
        cin.ignore();
        getline(cin, cur->first.day, '\n');
        cout << "What time that session occurred: " << endl;
        cout << "Started Hour(hour): " << endl;
        cin >> cur->first.time.hour;
        cout << "Started Hour(minute): " << endl;
        cin >> cur->first.time.minu;
      }
      cout << "do you want to update the time that second session occurred?" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "Seconde session performed on: " << endl;
        cin.ignore();
        getline(cin, cur->second.day, '\n');
        cout << "What time that session occurred: " << endl;
        cout << "Started Hour(hour): " << endl;
        cin >> cur->second.time.hour;
        cout << "Started Hour(minute): " << endl;
        cin >> cur->second.time.minu;
      }
    }
    cur = cur->pNext;
  }
}
