#include "student.h"

void inputAStudent(student& a, ifstream& fin) {
  fin >> a.No;
  fin >> ws;
  getline(fin, a.StudentID);
  getline(fin, a.First_name);
  getline(fin, a.Last_name);
  // getline(fin, a.sclass);

  fin >> ws;
  fin >> a.Gender;
  inputADate(a.Date_of_Birth, fin);
  fin >> ws;
  getline(fin, a.SocialID);
  getline(fin, a.userName);
  fin >> ws;
}
void saveAStudent(student& a, ofstream& fout) {
  fout << "No:" << '\t' << a.No << endl;
  fout << "Student ID:" << '\t' << a.StudentID << endl;
  fout << "First Name:" << '\t' << a.First_name << endl;
  fout << "Last Name:" << '\t' << a.Last_name << endl;
  //fout << "Class:" << '\t' << a.sclass << endl;
  fout << "Gender:" << '\t' << a.Gender << endl;
  fout << "Date of birth:" << '\t';
  outputADate(a.Date_of_Birth, fout);
  fout << "Social ID:" << '\t' << a.SocialID << endl;
}
void outputAStudent(student& a) {
  cout << a.No << '\n'
       << a.StudentID << '\n'
       << a.First_name << ' ' << a.Last_name << '\n'
       // << a.sclass << '\n'
       << a.Gender << '\n';
  outputADateToScreen(a.Date_of_Birth);

  cout << a.SocialID << '\n';
}
bool changePass(string currentPass, string currentUser) {
  cout << "please enter your password again: " << endl;
  string(test);
  cin.ignore();
  getline(cin, test, '\n');
  if (test.compare(currentPass) != 0) {
    cout << "wrong password, please try again" << endl;
    return false;
  } else {
    cout << "enter your new pass: " << endl;
    string newPass;
    getline(cin, newPass, '\n');
    while (newPass == currentPass) {
      cout << "it is identical with current password, please try again: " << endl;
      getline(cin, newPass, '\n');
    }
    ifstream fin;
    ofstream fout;
    fin.open("studentAccount.txt");
    if (fin.is_open()) {
      int n1;
      fin >> n1;
      accountInfo* acc;
      acc = new accountInfo[n1];
      for (int i = 0; i < n1; i++) {
        getline(fin, acc[i].name, ',');
        getline(fin, acc[i].pass, '\n');
        if (acc[i].name == currentUser && acc[i].pass == currentPass) {
          acc[i].pass = newPass;
          cout << "Your password has changed successfully! ";
        }
      }

      fout.open("studentAccount.txt");
      if (fout.is_open()) {
        fout << n1;
        for (int i = 0; i < n1; i++) {
          fout << acc[i].name << ',';
          fout << acc[i].pass << '\n';
        }
        fout.close();
      } else {
        cout << "sorry cannot open file";
        return false;
      }
      delete[] acc;
    } else {
      cout << "sorry cannot open file";
      return false;
    }
    fin.close();

    return true;
  }
}
bool studentLogin(string& userName) {
  bool login = false;
  string currentUser;
  string currentPass;

  while (!login) {
    string name, pass;

    cout << "enter your username:" << '\n';

    getline(cin, name, '\n');

    cout << "enter your password: " << '\n';

    getline(cin, pass);
    ifstream fin;
    fin.open("studentAccount.txt");
    if (!fin.is_open()) {
      cout << "No data on student accounts" << endl;
      return false;
    } else {
      string name1, pass1;

      while (!fin.eof() && getline(fin, name1, ',') && getline(fin, pass1) && !login) {
        if (name1.compare(name) == 0 && pass1.compare(pass) == 0) {
          cout << "LOGIN SUCCESSFULLY!\n";
          login = true;
          currentPass = pass;
          currentUser = name;
        }
      }
    }
    fin.close();
    if (!login) cout << "wrong username or password ,do you want to try again (Y\\n)" << '\n';
    string hook;
    getline(cin, hook);
    if (hook == "n" || hook == "N" || hook == "no" || hook == "NO" || hook == "No") return false;
  }
  return true;
}

//void enrollCourse(int&count, ifstream&fin,string nameyear,string semester,ofstream &fout)
void listOfStudentsInCourse(student*& pStudent, string nameyear, string namesemester, string namecourse) {
  ifstream fin;
  fin.open(nameyear + "-" + namesemester + "-" + namecourse + ".txt");
  if (!fin.is_open()) {
    cout << "can not open file ,please enter any character to back";
    string u;
    cin >> u;
    return;
  } else {
    int i = 0;
    pStudent = new student[1000];
    while (!fin.eof()) {
      inputAStudent(pStudent[i], fin);
      cout << pStudent[i].First_name << " " << pStudent[i].Last_name << endl;
      i++;
    }
  }
}
bool staffLogin(string& currentUser) {
  bool login = false;

  string currentPass;

  while (!login) {
    string name, pass;

    cout << "enter your username:" << '\n';

    getline(cin, name, '\n');

    cout << "enter your password: " << '\n';

    getline(cin, pass);
    ifstream fin;
    fin.open("staffAccount.txt");
    if (!fin.is_open()) {
      cout << "No data on staffs accounts" << endl;
      return false;
    } else {
      string name1, pass1;

      while (!fin.eof() && getline(fin, name1, ',') && getline(fin, pass1, ',') && !login) {
        if (name1.compare(name) == 0 && pass1.compare(pass) == 0) {
          cout << "LOGIN SUCCESSFULLY!\n";
          login = true;
          currentPass = pass;
          currentUser = name;
        }
      }
    }
    fin.close();
    if (!login) cout << "wrong username or password ,do you want to try again (Y\\n)" << '\n';
    string hook;
    getline(cin, hook);
    if (hook == "n" || hook == "N" || hook == "no" || hook == "NO" || hook == "No") return false;
  }
  return true;
}
/*
void enrollACourse(course* list_of_course) {
  course* cur = list_of_course;
  int count = 0;
  cout << "LIST OF COURSE:\n";

  int order = 0;
  while (cur) {
    cout << ++order << cur->name << '\n';
    cur = cur->pNext;
  }

  int hook;

  while (count < 6) {
    course* tmp = courseList;
    thisStudent.enrolledCourse = new course;
    course* tmp_2 = thisStudent.enrolledCourse;
    course* tmp_3 = thisStudent.enrolledCourse;
    cout << "Which course do you want to enroll?'\n";
    cin >> hook;
    while (hook <= 0 || hook > order) {
      cout << "Please input a number between 0 and " << order << '\n';
      cin >> hook;
    }
    while (hook > 0) {
      tmp = tmp->pNext;
      hook--;
    }
    tmp_2->pNext = new course;
    tmp_2 = tmp_2->pNext;

    *tmp_2 = *tmp;
    tmp_2->pNext = nullptr;
    thisStudent.enrolledCourse = thisStudent.enrolledCourse->pNext;
    delete tmp_3;
  }
}*/

/*
void listOfStudentsInCourse(student*& pStudent, char nameyear[], char namesemester[], char namecourse[]) 
{   
    char link[] ="-";
    char end[]=".txt";
    strcat(nameyear,link);
    strcat(namesemester,link);
    strcat(nameyear,namesemester);
    strcat(nameyear,namecourse);
    strcat(nameyear,end);
	ifstream fin;
	fin.open( nameyear);
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to return back";
		string u;
		cin >> u;
		return;
	}
	else{
		double count;
		fin>>count;
		//number of student
		int i=0;
		pStudent = new student[1000];
		while (!fin.eof()){
			inputAStudent(pStudent[i],fin);
			cout<<pStudent[i].First_name<<" "<<pStudent[i].Last_name<<endl;
			i++;
		}
	}
}*/