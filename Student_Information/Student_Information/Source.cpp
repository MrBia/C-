#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student {
	int id;
	string name;
	float score;
};

int main()
{
	list <Student> listStudent;
	Student stdn;
	ofstream file;

	
	while (true) {
		int choose;
		int exit = 0;
		cout << "-------------MENU--------------\n";
		cout << "1. Input\n";
		cout << "2. Display\n";
		cout << "3. Save to file\n";
		cout << "4. Load from file\n";
		cout << "0. Exit\n";
		cout << "-----------------\n";
		cout << "Choose: ";
		cin >> choose;

		switch (choose){
			case 1: {
				cout << "Input: \n";
				while (true) {
					int count;
					cout << "Input count of student: ";
					cin >> count;

					for (int i = 0; i < count; i++) {
						cout << "student " << i + 1 << "\n";
						cout << "id: ";
						cin >> stdn.id;
						if (listStudent.size() > 0) {                    // neu lon hon 1 student thi kiem tra id
							bool check = true;
							list<Student> ::iterator p;
							while (check) {
								check = false;
								for (p = listStudent.begin(); p != listStudent.end(); p++) {
									if ((*p).id == stdn.id) {
										check = true;
										cout << "id khong duoc trung, nhap lai: ";
										cin >> stdn.id;
										break;
									}
								}
							}
						}

						cin.ignore();
						cout << "name: ";
						getline(cin, stdn.name);

						cout << "score: ";
						cin >> stdn.score;
						while ((stdn.score < 0 || stdn.score > 10)) {           // thieu kiem tra nhap voa la chuoi hay so
							cout << "nhap lai! gia tri nam trong khoang 0-10\n";
							cin >> stdn.score;
						}

						listStudent.push_back(stdn);
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

				list<Student>::iterator ptr;
				for (ptr = listStudent.begin(); ptr != listStudent.end(); ptr++) {
					cout << setw(10) << left << (*ptr).id;
					cout << setw(30) << left << (*ptr).name;
					cout << setw(20) << left << (*ptr).score << "\n";
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
					cout << "file is opened\n";
					list<Student>::iterator p;
					for (p = listStudent.begin(); p != listStudent.end(); p++) {
						file << (*p).id << " " << (*p).name << " " << (*p).score << "\n";
					}
				}
				file.close();
				break;
			}

			case 4: {
				cout << "data in file: \n";
				if (!file) {
					cout << "File chua duoc tao.\n";
				}
				else {
					while (!file.eof()) {
						string s;
						file.get;
						cout << s << "\n";
					}
				}

				break;
			}

			case 0: {
				exit = 1;
				break;
			}
		}

		if (exit == 1) break;
	}

	return 0;
}