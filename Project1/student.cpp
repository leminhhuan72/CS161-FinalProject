#include "student.h"
void inputAStudent(student& a , ifstream &fin ){
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
void outputAStudentToFile(student &a , ofstream &fout ){
    fout << a.No <<'\n'<<a.StudentID<<'\n'<<a.First_name<<' '<<a.Last_name<<'\n'<<a.Gender<<'\n';
    outputADate(a.Date_of_Birth,fout);
    fout<<a.SocialID<<'\n';
    
}
void outputAStudent(student &a ){
    cout << a.No <<'\n'<<a.StudentID<<'\n'<<a.First_name<<' '<<a.Last_name<<'\n'<<a.Gender<<'\n';
    outputADateToScreen(a.Date_of_Birth);
    
    cout<<a.SocialID<<'\n';
    
}

void studentLogin(){
	bool check=false;
	book login=true;
	while(login){
	string name,pass;
	cout<<"enter your username: "<<endl;
	cin.getline(name,'\n');
	cout<<"enter your password: "<<endl;
	cin.getline(pass,'\n');
	ifstream fin;
	fin.open("studentAccount.txt"){
		if(!fin.is_open()){
			cout<<"No data on student accounts"<<endl;
			return;
		}
		else{
		while(!fin.eof){
			string name1,pass1;
			fin>>name1;
			fin>>pass1;
			if(name1.compare(name)==0&&pass1.compare(pass)==0){
				check =true;
				login=false;
			}
		}
	}
}
if (!check) cout<<"wrong username or password, please try again"
fin.close();
}
while (check){
	//cac thao tac ma student thuc hien khi login thanh cong
}
}
//void enrollCourse(int&count, ifstream&fin,string nameyear,string semester,ofstream &fout)
void listOfStudentsInCourse(student*& pStudent, string nameyear, string namesemester, string namecourse, int& n) {
	ifstream fin;
	fin.open(nameyear + "-" + namesemester + "-" + namecourse + ".txt");
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
			inputAStudent(student[i],fin);
			cout<<student[i].First_name<<" "<<student[i].Last_name<<endl;
			i++;
		}
	}
}

