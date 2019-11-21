#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
#include <fstream>

using namespace std;

int input();                          // nhap lua chon
int inputNum();                       // nhap so luong student
bool isNumber(string str);			  // kiem tra co phai so khong
int strToNum(string str);			  // chuyen chuoi thanh so
int inputID();                        // nhap id
int inputScore();					  // nhap score

struct Student {
	int id;
	string name;
	float score;
};

int main()
{
	list <Student*> listStudent;
	//Student* stdn = new Student;
	ofstream file;

	
	while (true) {
		int choose;
		int exit = 0;
		cout << "-------------MENU--------------\n";
		cout << "1. Input\n";
		cout << "2. Display\n";
		cout << "3. Save to file\n";
		cout << "4. Load from file\n";
		cout << "5. Exit\n";
		cout << "-----------------\n";
		
		choose = input();   // nhap lua chon

		switch (choose){
			case 1: {
				cout << "Input: \n";
				while (true) {
					int count;
					count = inputNum();                // nhap so luong student

					
					for (int i = 0; i < count; i++) {
						Student* stdn = new Student;
						cout << "student " << i + 1 << "\n";
						
						(*stdn).id = inputID();			// nhap ID

						if (listStudent.size() > 0) {                    // neu lon hon 1 student thi kiem tra id
							bool check = true;
							list<Student*>::iterator p;
							while (check) {
								check = false;
								for (p = listStudent.begin(); p != listStudent.end(); p++) {
									if ((**p).id == (*stdn).id) {
										check = true;
										cout << "id khong duoc trung, nhap lai: ";
										(*stdn).id = inputID();
										break;
									}
								}
							}
						}


						cout << "name: ";
						getline(cin, (*stdn).name);

						(*stdn).score = inputScore();
						while (((*stdn).score < 0 || (*stdn).score > 10)) {           // thieu kiem tra nhap vao la chuoi hay so
							cout << "nhap lai! gia tri nam trong khoang 0-10\n";

							(*stdn).score = inputScore();
						}

						listStudent.push_back(stdn);
						//delete stdn;
					}
					break;
				}
				break;
			}

			case 2: {
				cout << "List Student: \n";
				cout << setw(10) << left << "ID";
				cout << setw(30) << left << "NAME";
				cout << setw(20) << left << "SCORE" << "\n";

				list<Student*>::iterator ptr;
				for (ptr = listStudent.begin(); ptr != listStudent.end(); ptr++) {
					cout << setw(10) << left << (**ptr).id;
					cout << setw(30) << left << (**ptr).name;
					cout << setw(20) << left << (**ptr).score << "\n";
				}

				
				break;
			}

			case 3: {
				const char* filePath = "C:/Users/Admin/Desktop/C-/data.txt";

				//ofstream file;
				file.open("C:/Users/Admin/Desktop/C-/data.txt");             // mo file, neu chua co thi tao
				if (!file) {
					cout << "cannot open file \n";
				}
				else {
					cout << "file is saved\n";
					list<Student*>::iterator p;
					for (p = listStudent.begin(); p != listStudent.end(); p++) {
						file << (**p).id << " " << (**p).name << " " << (**p).score << "\n";
					}
				}
				file.close();
				break;
			}

			case 4: {
				ifstream f;
				f.open("C:/Users/Admin/Desktop/C-/data.txt");
				cout << "data in file: \n";
				if (!file) {
					cout << "File chua duoc tao.\n";
				}
				else {
					while (!f.eof()) {
						string s;
						f >> s;
						cout << s << "\n";
					}
				}

				break;
			}

			case 5: {
				exit = 1;
				list<Student*>::iterator p;
				for (p = listStudent.begin(); p != listStudent.end(); p++) {
					delete* p;
				}
				break;
			}
		}

		if (exit == 1) break;
	}

	return 0;
}
//atof
bool isNumber(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

int strToNum(string str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		num = num * 10 + (str[i] - 48);
	}

	return num;
}

int input() {
	string c;
	int choose = 5;
	while (true) {
		cout << "Choose: ";
		getline(cin, c);
		if (isNumber(c)) {
			choose = strToNum(c);
		}
		else {
			cout << "Nhap lai\n";
			continue;
		}
		if (choose <= 0 || choose > 5) {
			cout << "Nhap lai\n";
			continue;
		}
		else {
			break;
		}
	}

	return choose;
}

int inputNum() {
	string c;
	int num = 0;
	while (true) {
		cout << "Input count of student: ";
		getline(cin, c);

		if (isNumber(c)) {
			num = strToNum(c);
			break;
		}
		else {
			cout << "Nhap lai\n";
		}
	}
	return num;
}

int inputID() {
	string c;
	int num = 0;
	while (true) {
		cout << "id: ";
		getline(cin, c);

		if (isNumber(c)) {
			num = strToNum(c);
			break;
		}
		else {
			cout << "Nhap lai\n";
		}
	}
	return num;
}

int inputScore() {
	string c;
	int num = 0;
	while (true) {
		cout << "score: ";
		getline(cin, c);

		if (isNumber(c)) {
			num = strToNum(c);
			break;
		}
		else {
			cout << "Nhap lai\n";
		}
	}
	return num;
}
// ham tra ve so 0