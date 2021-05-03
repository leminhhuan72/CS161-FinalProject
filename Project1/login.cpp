#include "login.h"

void login() {
  for (int i = 0; i < 6; ++i)
    cout << '\t';
  cout << "THIS IS HCMUS PORTAL "
       << "\n";
  for (int i = 0; i < 3; ++i)
    cout << '\t';
  cout << "ARE YOU STUDENT OR STAFF ( Enter 1 if you are student , 2 if you are staff " << endl;
  Date Now;
  string currentUser;
  getCurrentDate(Now);
  cout << "The current date is ";
  outputADateToScreen(Now);
  int n;
  cin >> n;
  while (n != 1 && n != 2) {
    cout << "Please input 1 if you are student or 2 if you are staff";
    cin >> n;
  }
  cin.get();
  schoolYr recent;
  semester recent_sem;
  courseRegisSession recent_Session;

  if (n == 1) {
    if (studentLogin(currentUser)) {
      student recent_stu;
      checkSchoolYr_st(recent);
      bool regisActive;
      bool scoreBoard = false;
      checkSemester_st(recent_sem, recent, Now, regisActive);
      if (!loadCourses(recent_sem)) regisActive = false;
      menuChoice_st(recent, recent_sem, recent_stu, regisActive, scoreBoard);
    }
  } else if (n == 2) {
    if (staffLogin(currentUser)) {
      checkSchoolYr(recent);
      checkSemester(recent_sem, recent);
      bool fullClass = false;
      bool scoreBoard = false;
      if (canLoadClass(recent)) {
        fullClass = loadClass(recent);
        if (fullClass) {
          cout << "load full classes successfully!\n\n";
        } else
          cout << "load classes unsuccessfully\n\n";
      } else {
        cout << "NOT ENOUGH INFORMATION ABOUT CLASSES AND STUDENTS\n\n";
      }
      bool loadCourse = loadCourses(recent_sem);
      menuChoice(recent, recent_sem, loadCourse, fullClass, scoreBoard);

    } else {
      return;
      cout << "GOOD BYE!!!!!";
    }
  }
  delete[] recent.classLs->member;
  delete[] recent.classLs;
  //deleteCourseList(recent_sem.list_of_course);
}
void checkSchoolYr(schoolYr& recent) {
  if (loadSchoolYr(recent)) {
    cout << "The recent school year is " << recent.schoolYrNo << endl;
    cout << "The start date is ";
    outputADateToScreen(recent.start_day);
    cout << "The end date is ";
    outputADateToScreen(recent.end_day);
    cout << "There are " << recent.num_of_class << " classes in this school year\n\n";
  } else {
    cout << "please input a new schoolYear\n";
    cout << "1: input a new school Year\n";
    cout << "2: exit\n";
    int n;
    while (cin >> n) {
      if (n == 1) {
        createSchoolYr(recent);
        break;
      } else if (n == 2)
        return;
      else
        cout << "1: input a new school Year\n 2: exit \n";
    }
  }
}
void checkSemester(semester& recent_sem, schoolYr& recent) {
  if (loadSemester(recent_sem, recent)) {
    cout << "The recent semester is ";
    switch (recent_sem.No) {
      case 1:
        cout << "Fall\n";
        break;
      case 2:
        cout << "Spring\n";
        break;
      default:
        cout << "Summer\n";
        break;
    }
    cout << "The start date of this semester is ";
    outputADateToScreen(recent_sem.start_date);
    cout << "The end date of this semester is ";
    outputADateToScreen(recent_sem.end_date);
    cout << "The start date of the course registration session is ";
    outputADateToScreen(recent_sem.regis_start);
    cout << "The end date of the course registration session is ";
    outputADateToScreen(recent_sem.regis_end);

  } else {
    cout << "please input a new semester\n";
    cout << "1: input a new semester\n";
    cout << "2: exit\n";
    int n;
    cin >> n;
    while (n != 1 && n != 2) {
      cout << "1: input a new semester\n 2: exit \n";
      cin >> n;
    }
    if (n == 1) {
      createASemester(recent_sem, recent);
    } else if (n == 2)
      return;
  }
}
void checkSchoolYr_st(schoolYr& recent) {
  if (loadSchoolYr(recent)) {
    cout << "The recent school year is " << recent.schoolYrNo << endl;
    cout << "The start date is ";
    outputADateToScreen(recent.start_day);
    cout << "The end date is ";
    outputADateToScreen(recent.end_day);
    cout << "There are " << recent.num_of_class << " classes in this school year\n\n";
  } else {
    cout << "There has been no information about this school year yet\n";
    return;
  }
}
void checkSemester_st(semester& recent_sem, schoolYr& recent, Date Now, bool& regisActive) {
  if (loadSemester(recent_sem, recent)) {
    cout << "The recent semester is ";
    switch (recent_sem.No) {
      case 1:
        cout << "Fall\n";
        break;
      case 2:
        cout << "Spring\n";
        break;
      default:
        cout << "Summer\n";
        break;
    }
    cout << "The start date of this semester is ";
    outputADateToScreen(recent_sem.start_date);
    cout << "The end date of this semester is ";
    outputADateToScreen(recent_sem.end_date);
    cout << "The start date of the course registration session is ";
    outputADateToScreen(recent_sem.regis_start);
    cout << "The end date of the course registration session is ";
    outputADateToScreen(recent_sem.regis_end);
    if (compare2Days(Now, recent_sem.regis_start) >= 0 && compare2Days(Now, recent_sem.regis_end) <= 0) {
      cout << "The course registration session is active, you can register courses now\n";
      regisActive = true;
    } else {
      regisActive = false;
      cout << "The course registration session is not active yet\n";
    }
  } else {
    cout << "There has been no information about this semester yet\n";
    return;
  }
}
void menuChoice(schoolYr& recent, semester& recent_sem, bool loadCourse, bool fullClass, bool scoreBoard) {
  if (loadCourse) {
    cout << "WHICH TASK YOU WANT TO DO ?\n";

    cout << "WHICH TASK YOU WANT TO DO ?\n";
    cout << "1 TO CREATE A NEW SCHOOL YEAR \n";
    cout << "2 TO CREATE A NEW SEMESTER \n";
    cout << "3 TO ADD A NEW COURSE\n";
    cout << "4 TO VIEW LIST OF COURSES\n";
    cout << "5 TO DELETE A COURSE\n";
    cout << "6 TO UPDATE A COURSE INFO\n";
    if (fullClass)
      cout << "7 TO VIEW CLASSES LISTS AND STUDENTS LIST\n";
    else
      cout << "8 TO ADD A CLASS CSV FILE\n";
    cout << "ANY OTHER KEYS TO EXIT\n";
    int n;
    cin >> n;
    cin.get();
    switch (n) {
      case 1:

      {
        createSchoolYr(recent);
        break;
      }
      case 2: {
        createASemester(recent_sem, recent);
        break;
      }
      case 3: {
        courseRegis(recent_sem.list_of_course);
        if (storecoursesList(recent_sem))
          cout << "STORE COURSES INFORMATION SUCCESSFULLY!\n";
        else
          cout << "STORE COURSES INFORMATION UNSUCCESSFULLY!\n";
        break;
      }
      case 4: {
        viewListOfCourse(recent_sem);

        break;
      }
      case 5: {
        deleteACourse(recent_sem.list_of_course);
        if (storecoursesList(recent_sem))
          cout << "STORE COURSES INFORMATION SUCCESSFULLY!\n";
        else
          cout << "STORE COURSES INFORMATION UNSUCCESSFULLY!\n";

        break;
      }
      case 6: {
        updateCourseInfo(recent_sem.list_of_course);
        if (storecoursesList(recent_sem))
          cout << "STORE COURSES INFORMATION SUCCESSFULLY!\n";
        else
          cout << "STORE COURSES INFORMATION UNSUCCESSFULLY!\n";
      }
      case 7: {
        cout << "WHICH CLASS YOU WANT TO VIEW STUDENTS LIST \n";
        for (int i = 0; i < recent.num_of_class; ++i) {
          cout << i + 1 << " " << recent.classLs[i].name << '\n';
        }
        int n;
        cin >> n;
        int n2 = 1;
        while (n2 == 1) {
          viewAClass(recent.classLs[n - 1]);
          cout << "DO YOU WANT VIEW MORE CLASS?\n 1:yes \n other number : no)\n";
          cin >> n2;
          if (n2 == 1) {
            cout << "WHICH CLASS YOU WANT TO VIEW STUDENTS LIST \n";
            for (int i = 0; i < recent.num_of_class; ++i) {
              cout << i + 1 << " " << recent.classLs[i].name << '\n';
            }
            cin >> n;
          }
        }
        break;
      }
      case 8: {
        inputAClass();
        break;
      }
      default:
        exit;
        break;
    }
  } else {
    cout << "THERE HAVE NOT BEEN ANY COURSES ADDED YET.\n";
    cout << "WHICH TASK YOU WANT TO DO ?\n";
    cout << "1 TO CREATE A NEW SCHOOL YEAR \n";
    cout << "2 TO CREATE A NEW SEMESTER \n";
    cout << "3 ADD COURSES TO THIS SEMESTER\n";
    if (fullClass)
      cout << "4 TO VIEW CLASSES LISTS AND STUDENTS LIST\n";
    else
      cout << "5 TO ADD A CLASS CSV FILE\n";
    cout << "ANY OTHER KEYS TO EXIT\n";
    int n;
    cin >> n;
    cin.get();
    switch (n) {
      case 1: {
        createSchoolYr(recent);
        break;
      }
      case 4: {
        classR _init_;
        createAClass(_init_);
        break;
      }
      case 5: {
        inputAClass();
        break;
      }
      case 2: {
        createASemester(recent_sem, recent);
        break;
      }
      case 3: {
        courseRegis(recent_sem.list_of_course);
        if (storecoursesList(recent_sem))
          cout << "STORE COURSES INFORMATION SUCCESSFULLY!\n";
        else
          cout << "STORE COURSES INFORMATION UNSUCCESSFULLY!\n";
        break;
      }
      default:
        exit;
        break;
    }
  }
}
void menuChoice_st(schoolYr& recent, semester& recent_sem, student& recent_stu, bool regisActive, bool scoreBoard) {
  if (regisActive) {
    bool check = true;
    while (check) {
      cout << "WHICH TASK YOU WANT TO DO ?\n";
      cout << "1 TO ENROLL COURSE \n";
      cout << "3 TO EXIT \n";
      int tmp = intCheck(1, 3);
      if (tmp == 3)
        check = false;
      switch (tmp) {
        case 1: {
          enrollACourse(recent_stu, recent_sem);
          break;
        }
        case 2: {
          break;
        }
        default:
          cout << "GOOD BYE!";
          break;
      }
    }

  } else {
    bool check = true;
    while (check) {
      cout << "WHICH TASK YOU WANT TO DO ?\n";
      cout << "1 TO VIEW PROFILE\n";
      cout << "2 TO VIEW LIST OF ENROLLED COURSES\n";
      cout << "3 TO VIEW SCHEDULE\n";
      cout << "4 TO EXIT\n";
      int tmp = intCheck(1, 4);
      cout << tmp << endl;
      if (tmp == 4)
        check = false;
      switch (tmp) {
        case 1: {
          //viewProFile(recent_stu);
          break;
        }
        case 2: {
          // viewEnrolledCourses(recent_sem, recent_stu);
          break;
        }
        case 3: {
          // viewSchedule(recent_stu)
        }
        default:
          cout << "GOOD BYE!";
          break;
      }
    }
  }
}
int intCheck(int l, int r) {
  char n;
  cout << "input a number from" << l << " to " << r << endl;
  cin >> n;
  int check = (int)n;
  while (check < l + 48 || check > r + 48) {
    cout << "input a number from" << l << " to " << r << endl;
    cin.get(n);
    check = (int)n;
  }
  return check - 48;
}