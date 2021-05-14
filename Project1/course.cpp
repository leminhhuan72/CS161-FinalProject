#include "course.h"
using namespace std;

void courseRegis(course*& totalCourse)  // 7
{
  int count = 0;
  cout << "Please input 1 to registrate a course \n 2 to exit \n";
  int n;
  cin >> n;
  while (n != 1 && n != 2) {
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
  }
  while (n == 1) {
    count++;
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
      cin >> ws;
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
      cin >> ws;
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
  cout << "Have input " << count << " courses" << endl;
}
bool storecoursesList(semester& recent) {
  course* cur = recent.list_of_course;
  string path = "./course/" + recent._this_year->schoolYrNo + to_string(recent.No) + ".txt";
  ofstream fout;
  ofstream fout_2;
  fout.open(path, ios::trunc);
  if (!fout.is_open()) {
    cout << "can not open the text file to store the course information";
    return false;
  } else {
    while (cur != nullptr) {
      string path_2 = "./studentOfCourse/" + recent._this_year->schoolYrNo + to_string(recent.No) + to_string(cur->num) + ".txt";
      fout_2.open(path_2);
      if (fout_2.is_open()) {
        cout << "File course " << cur->ID << " has been created\n";
      } else
        cout << "Can not open the student list of course file !\n\n";
      fout_2.close();
      fout << cur->num << endl;
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
      // total line: 12
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
    if (file_is_empty(path)) {
      cout << "THE COURSES FILE IS EMPTY!\n\n";
      return false;
    } else {
      cout << "Load all courses successfully!\n\n";
      recent_sem.list_of_course = new course;
      course* cur = recent_sem.list_of_course;
      while (!fin.eof()) {
        cur->pNext = new course;
        fin >> cur->pNext->num;
        fin >> cur->pNext->ID;
        fin >> ws;
        getline(fin, cur->pNext->fullname);
        fin >> ws;
        fin >> cur->pNext->numOfCredits;
        fin >> cur->pNext->maxStudent;
        fin >> ws;
        getline(fin, cur->pNext->classroom);
        getline(fin, cur->pNext->lecturer.username);
        getline(fin, cur->pNext->lecturer.name);
        getline(fin, cur->pNext->first.day_in_week);
        fin >> ws;
        fin >> cur->pNext->first.shift;
        fin >> ws;
        getline(fin, cur->pNext->second.day_in_week);
        fin >> ws;
        fin >> cur->pNext->second.shift;
        fin >> ws;
        cur = cur->pNext;
        cur->pNext = nullptr;
      }
      course* tmp = recent_sem.list_of_course;
      recent_sem.list_of_course = recent_sem.list_of_course->pNext;
      delete tmp;
    }
  } else {
    cout << "Can not open the courses file!\n\n";
    return false;
  }

  fin.close();
  return true;
}
//task 11
void deleteACourse(course*& totalCourse) {
  cout << "please input the name or the fullname of the course you want to delete: " << endl;
  string test;
  getline(cin, test);
  course* cur = totalCourse;
  if (cur == nullptr) {
    cout << "No existed courses to delete, please add some courses" << endl;
    cout << "enter any character to return back";
    string u;
    cin >> u;
    return;
  }
  if (totalCourse->ID == test || totalCourse->fullname == test) {
    course* tmp = totalCourse;
    totalCourse = totalCourse->pNext;
    delete tmp;
    cur = totalCourse;
    while (cur != nullptr) {
      cur->num = cur->num - 1;
      cur = cur->pNext;
    }
    cout << "DELETE COURSE " << test << " SUCCESSFULLY!\n\n";
  } else {
    while (cur->pNext != nullptr) {
      if (cur->pNext->ID == test || cur->pNext->fullname == test) {
        course* tem = cur->pNext;
        cur->pNext = cur->pNext->pNext;
        delete tem;
        while (cur->pNext != nullptr) {
          cur->pNext->num = cur->pNext->num - 1;
          cur = cur->pNext;
        }
        cout << "DELETE COURSE " << test << " SUCCESSFULLY!\n\n";
        return;
      }
      cur = cur->pNext;
    }
  }
}
//task 10

void viewListOfCourse(semester recent_sem) {
  if (!recent_sem.list_of_course) {
    cout << "There is no course!\n";
    return;
  } else {
    cout << "No" << '\t' << "ID" << '\t' << "FullName          " << '\t' << "ROOM" << '\t' << "CREDITS" << '\t' << "LECTURER'S.NAME" << '\t' << "SESS 1" << ' ' << "SHIFT" << '\t' << "SESS 2" << ' ' << "SHIFT" << '\n';
    while (recent_sem.list_of_course) {
      outputACourseToScr(*recent_sem.list_of_course);
      recent_sem.list_of_course = recent_sem.list_of_course->pNext;
    }
  }
}
void outputACourseToScr(course a) {
  string shift[4] = {"7:30", "9:30", "13:30", "15:30"};
  cout << a.num << '\t' << a.ID << '\t' << a.fullname << '\t' << a.classroom << '\t' << a.numOfCredits << '\t' << a.lecturer.name << "\t" << a.first.day_in_week << ' ' << shift[a.first.shift - 1] << '\t' << a.second.day_in_week << ' ' << shift[a.second.shift - 1] << endl;
}

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
    if (cur->ID == name1 || cur->fullname == name1) {
      cout << "do you want to update name of course" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "input the name you want to change to: " << endl;
        getline(cin, cur->ID, '\n');
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
        getline(cin, cur->lecturer.gender);
      }
      //nothing , rest
      cout << "do you want to update the time that first session occurred?" << endl;
      getline(cin, test1);
      if (!check1(test1)) {
        cout << "First session performed on: " << endl;

        getline(cin, cur->first.day_in_week);
        cout << "Which shift that session occurred: " << endl;
        cin >> ws;
        cin >> cur->first.shift;
        cin >> ws;

        cout << "do you want to update the time that second session occurred?" << endl;
        getline(cin, test1);
        if (!check1(test1)) {
          cout << "Second session performed on: " << endl;
          getline(cin, cur->second.day_in_week);
          cout << "Which shift that session occured" << endl;
          cin >> ws;
          cin >> cur->second.shift;
          cin >> ws;
        }
      }
      cur = cur->pNext;
    }
  }
}
void enrollACourse(student& recent, semester& recent_sem) {
  cout << "HOW MANY COURSES DO YOU WANT TO ENROLL?\n";
  int n;
  cin >> n;
  recent.courseNo = new int[n + 1];
  recent.courseNo[0] = n;
  bool scheduleCheck[6][4];
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 4; ++j) {
      scheduleCheck[i][j] = true;
    }
  viewListOfCourse(recent_sem);
  for (int i = 1; i <= n; ++i) {
    cout << "Input your number choice (course No) ?\n";
    int tmp;
    cin >> tmp;
    while (!checkCourseValid(recent_sem, tmp)) {
      cout << "The course if full now !";
      cout << "Do you want to enroll another course (1: yes, 2: no)\n";
      int n = intCheck(1, 2);
      if (n == 2)
        return;
      else {
        cout << "please input a number (course No)";
        cin >> tmp;
      }
    }
    bool check = true;
    while (check) {
      int week_1, week_2, shift_1, shift_2;
      scheduleExtract(recent_sem, week_1, shift_2, week_2, shift_2, tmp);

      if (scheduleCheck[week_1][shift_1] && scheduleCheck[week_2][shift_2]) {
        recent.courseNo[i] = tmp;
        scheduleCheck[week_1][shift_1] = scheduleCheck[week_2][shift_2] = false;
        check = false;
        ofstream fout;
        string path_2 = "./studentOfCourse/" + recent_sem._this_year->schoolYrNo + to_string(recent_sem.No) + to_string(tmp) + ".txt";
        fout.open(path_2, ios::app);
        fout << recent.StudentID << ',' << recent.First_name << ',' << recent.Last_name << '\n';
        fout.close();

      } else {
        cout << "THIS COURSE SESSION CONFLICTS TO ADD COURSES\n Plase make another choice\n";
        cout << "Input your number choice (course No) ?\n";
        cin >> tmp;
      }
    }
  }
}
void scheduleExtract(semester& recent_sem, int& week_1, int& shift_1, int& week_2, int& shift_2, int courseNo) {
  course* cur = recent_sem.list_of_course;
  while (courseNo > 1) {
    cur = cur->pNext;
    if (!cur) cout << "There is no course corresponding to the course number\n";
    --courseNo;
  }
  string day_in_week_ar[6] = {"MON", "TUE", "WED", "THU", "FRI", "SAT"};
  for (int i = 0; i < 6; ++i) {
    if (cur->first.day_in_week == day_in_week_ar[i]) week_1 = i;
    if (cur->second.day_in_week == day_in_week_ar[i]) week_2 = i;
  }
  shift_1 = cur->first.shift;
  shift_2 = cur->second.shift;
}
bool checkCourseValid(semester& recent_sem, int courseNo) {
  ifstream fin;
  string path = "./studentOfCourse/" + recent_sem._this_year->schoolYrNo + to_string(recent_sem.No) + to_string(courseNo) + ".txt";
  fin.open(path, ios::ate);
  int position = fin.tellg();
  course* cur = recent_sem.list_of_course;
  while (courseNo > 1) {
    cur = cur->pNext;
    --courseNo;
  }
  if (position - 1 < cur->maxStudent) return true;
  return false;
}
void viewCourseStudent(semester& recent_sem) {
  cout << "WHICH COURSE YOU WANT TO VIEW STUDENTS LIST \n";
  viewListOfCourse(recent_sem);
  course* tmp = recent_sem.list_of_course;
  while (tmp->pNext) {
    tmp = tmp->pNext;
  }
  int numOfCourse = tmp->num;
  int n = intCheck(1, numOfCourse);
  ifstream fin;
  string path_2 = "./studentOfCourse/" + recent_sem._this_year->schoolYrNo + to_string(recent_sem.No) + to_string(n) + ".txt";
  fin.open(path_2);
  if (!fin.is_open()) {
    cout << "Can not open file\n";
    return;
  }
  if (file_is_empty(path_2)) {
    cout << "There is no student enrolled yet\n";
    return;
  }

  int order = 1;
  cout << setw(3) << left << "No";
  cout << setw(13) << "Student ID";
  cout << setw(30) << "Full Name" << endl;
  while (!fin.eof()) {
    string ID;
    string firstName;
    string lastName;
    getline(fin, ID, ',');
    getline(fin, firstName, ',');
    getline(fin, lastName, '\n');
    fin >> ws;
    cout << setw(3) << left << order++;
    cout << setw(13) << ID;
    cout << setw(30) << firstName + " " + lastName << endl;
  }
}
