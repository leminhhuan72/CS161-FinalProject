#include "student.h"


void inputAStudent(student& a , ifstream &fin )
{

    fin>>a.No ; 
    getline(fin, a.StudentID);
    getline(fin, a.First_name);
    getline(fin, a.Last_name);
    string gender ; 
    getline(fin, gender );
    if(gender == "male")a.Gender=true ;
    else a.Gender = false ;  
    inputADate(a.Date_of_Birth,fin);
    getline(fin, a.SocialID);
}
void saveAStudent(student& a, ofstream& fout)
{
    fout << "No:" << '\t' << a.No << endl;
    fout << "Student ID:" << '\t' << a.StudentID << endl;
    fout << "First Name:" << '\t' << a.First_name << endl;
    fout << "Last Name:" << '\t' << a.Last_name << endl;
    fout << "Gender:" << '\t' << a.Gender << endl;
    fout << "Date of birth:" << '\t';
    outputADate(a.Date_of_Birth, fout);
    fout << "Social ID:" << '\t' << a.SocialID << endl;
}
void outputAStudent(student &a ){
    cout << a.No <<'\n'<<a.StudentID<<'\n'<<a.First_name<<' '<<a.Last_name<<'\n'<<a.Gender<<'\n';
    outputADateToScreen(a.Date_of_Birth);
    
    cout<<a.SocialID<<'\n';
    
}
bool changePass(string currentPass,string currentUser){
				cout<<"please enter your password again: "<<endl;
			string(test);
			cin.ignore();
			getline(cin,test,'\n');
			if (test.compare(currentPass)!=0){
				cout<<"wrong password, please try again"<<endl;
				return false;
			}
			else{
				cout<<"enter your new pass: "<<endl;
				string newPass;
				getline(cin,newPass,'\n');
				while (newPass==currentPass){
					cout<<"it is identical with current password, please try again: "<<endl;
					getline(cin,newPass,'\n');
				}
				ifstream fin;
				ofstream fout;
				fin.open("studentAccount.txt");
				if (fin.is_open()){
					int n1;
					fin>>n1;
					accountInfo *acc;
					acc= new accountInfo[n1];
					for (int i = 0; i < n1; i++) {

			        getline(fin, acc[i].name, ',');
			        getline(fin, acc[i].pass, '\n');
			        if (acc[i].name == currentUser && acc[i].pass == currentPass)
				{
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
		}
		else {
			cout << "sorry cannot open file";
			return false;
		}
			delete[]acc;
	}
		else {
			cout << "sorry cannot open file";
			return false;
		}
		fin.close();
	
		return true;
}
}
void studentLogin()
{
	bool check=false;
	bool login=true;

	string currentUser;
	string currentPass;
	while(login)
{
	string name,pass;
	cout<<"enter your username: "<<'\n';
	getline(cin,name,'\n');
	cout<<"enter your password: "<<endl;
	getline(cin,pass);
	ifstream fin;
	fin.open("studentAccount.txt");
		if(!fin.is_open())
		{
			cout<<"No data on student accounts"<<endl;
			return;
		}
		else
		{
			string name1,pass1;

		while(!fin.eof()&&getline(fin,name1, ',')&&getline(fin, pass1,',')&&!check)
		{
			if(name1.compare(name)==0&&pass1.compare(pass)==0){
				
				check =true;
				login=false;
				currentPass=pass;
				currentUser=name;
				
			}
		}
		
	    }
		if (!check) cout<<"wrong username or password ,do you want to try again (Y\\n)"<<'\n';
		string hook ;
		getline(cin,hook);
		if(hook=="n"||hook=="N"||hook == "no"||hook == "NO"||hook == "No")login=false;


   fin.close();
}
while (check)
   {
	//cac thao tac ma student thuc hien khi login thanh cong
	bool notRest = true;
	while (notRest){
	cout<<"Enter 0 to change password "<<'\n';
	cout<<"Enter 9 to exit "<<'\n';
	int x;
	cin>>x;

	switch(x){
		case 0://change password
		bool a=changePass(currentPass,currentUser);
		while (!a){
			a=changePass(currentPass,currentUser);
		}
		break;

		case 9: return ; 
		}
				}
	}
	

}
//void enrollCourse(int&count, ifstream&fin,string nameyear,string semester,ofstream &fout)
void listOfStudentsInCourse(student*& pStudent, string nameyear, string namesemester, string namecourse) 
{
	ifstream fin;
	fin.open( nameyear + '-' + namesemester + '-' + namecourse+".txt");
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to back";
		string u;
		cin >> u;
		return;
	}
	else{
		int i=0;
		pStudent = new student[1000];
		while (!fin.eof()){
			inputAStudent(pStudent[i],fin);
			cout<<pStudent[i].First_name<<" "<<pStudent[i].Last_name<<endl;
			i++;
		}
	}
}
void staffLogin(){
	bool check=false;
	bool login=true;

	string currentUser;
	string currentPass;
	while(login){
	string name,pass;
	cout<<"enter your username: "<<endl;

	getline(cin,name);
	cout<<"enter your password: "<<endl;
	getline(cin,pass);
	ifstream fin;
	fin.open("staffAccount.txt");
		if(!fin.is_open()){
			cout<<"No data on staff accounts"<<endl;
			return;
		}
		else{
		while(!fin.eof()){
			int n;
			fin>>n;
			fin.ignore();
			string name1,pass1;
			getline(fin,name1, ',');
			getline(fin, pass1, '\n');
			if(name1.compare(name)==0&&pass1.compare(pass)==0){
				check =true;
				login=false;
				currentPass=pass;
				currentUser=name;
			}
		}
	}

if (!check) cout<<"wrong username or password, please try again";
fin.close();
}
while (check){
	//cac thao tac ma student thuc hien khi login thanh cong
	bool notRest = true;
	while (notRest){
	int x;
	cin>>x;
	switch(x){
		case 0://change password
		bool a=changePass(currentPass,currentUser);
		while (!a){
			a=changePass(currentPass,currentUser);
		}
		break;
		}
				}
			}
		}
