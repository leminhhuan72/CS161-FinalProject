struct scoreboard {
	string fullname;
	string id;
	int no;
	mark score;
};
struct mark{
	double totalMark;
	double midtermMark;
	double finalMark;
	double otherMark;
};
void viewScoreBoard(string nameYear, string nameSemester, string nameCourse,string Sclass){

	ifstream fin;
	fin.open( nameYear + '-' + nameSemester + '-' + nameCourse+'-'+sClass+".txt");
	if (!fin.is_open()) {
		cout << "can not open file ,please enter any character to back";
		string u;
		cin >> u;
		return;
	}
	int n;
	fin>>n;
	fin.ignore();
	char nothing;
	//CSV file
	//
	//
	//
	//
	//
	int column = 1, row = 5;
	gotoXY(column, row);
	cout << "ID";
	gotoXY(column + 10, row);
	cout << "Fullname";
	gotoXY(column + 40, row);
	cout << "Midterm";
	gotoXY(column + 50, row);
	cout << "Final";
	gotoXY(column + 60, row);
	cout << "Other";
	gotoXY(column + 70, row);
	cout << "Final";
	White();
	row++;
	for (int i = 0; i < n; i++) {

		gotoXY(column, row);
		cout << source[i].ID;
		gotoXY(column + 10, row);
		cout << source[i].name;
		gotoXY(column + 40, row);
		cout << source[i].score.midtermMark;
		gotoXY(column + 50, row);
		cout << source[i].score.finalMark;
		gotoXY(column + 60, row);
		cout << source[i].score.oterMark;
		gotoXY(column + 70, row);
		cout << source[i].score.totalMark;
		row++;

	}

	delete[]source;
	return;		
	}
