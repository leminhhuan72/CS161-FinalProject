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
      checkSchoolYr_st(recent);
      bool regisActive;
      checkSemester_st(recent_sem, recent, Now, regisActive);
      if (!loadCourses(recent_sem)) regisActive = false;
      if (regisActive) {
        cout << "WHICH TASK YOU WANT TO DO ?\n";
        cout << "1 TO ENROLL COURSE \n";
        cout << "2 TO CREATE A CLASS\n";
        cout << "3 TO ADD STUDENTS TO A CLASS\n";
        cout << "4 TO CREATE A NEW SEMESTER \n";
      } else {
        cout << "WHICH TASK YOU WANT TO DO ?\n";
        cout << "1 TO CREATE A NEW SCHOOL YEAR \n";
        cout << "2 TO CREATE A CLASS\n";
        cout << "3 TO ADD STUDENTS TO A CLASS\n";
        cout << "4 TO CREATE A NEW SEMESTER \n";
      }
    }
  } else if (n == 2) {
    if (staffLogin(currentUser)) {
      checkSchoolYr(recent);
      checkSemester(recent_sem, recent);
      if (loadCourses(recent_sem)) {
        cout << "WHICH TASK YOU WANT TO DO ?\n";
        cout << "1 TO CREATE A NEW SCHOOL YEAR \n";
        cout << "2 TO CREATE A CLASS\n";
        cout << "3 TO ADD STUDENTS TO A CLASS\n";
        cout << "4 TO CREATE A NEW SEMESTER \n";
        cout << "5 TO VIEW LIST OF COURSES\n";
        cout << "ANY OTHER KEYS TO EXIT\n";
      } else {
        cout << "THERE HAVE NOT BEEN ANY COURSES ADDED YET.\n";
        cout << "WHICH TASK YOU WANT TO DO ?\n";
        cout << "1 TO CREATE A NEW SCHOOL YEAR \n";
        cout << "2 TO CREATE A CLASS\n";
        cout << "3 TO ADD STUDENTS TO A CLASS\n";
        cout << "4 TO CREATE A NEW SEMESTER \n";
        cout << "5 ADD COURSES TO THIS SEMESTER\n";
        cout << "ANY OTHER KEYS TO EXIT\n";
      }
      menuChoice(recent, recent_sem);

    } else {
      cout << "GOOD BYE!!!!!";
    }
  }
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
void menuChoice(schoolYr& recent, semester& recent_sem) {
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
      classR _init_;
      createAClass(_init_);
      break;
    }
    case 3: {
      inputAClass();
      break;
    }
    case 4: {
      createASemester(recent_sem, recent);
      break;
    }
    case 5: {
      courseRegis(recent_sem.list_of_course);
      if (storecoursesList(recent_sem.list_of_course, recent_sem))
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