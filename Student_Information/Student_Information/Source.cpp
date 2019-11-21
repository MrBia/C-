#include <iostream>
#include <string.h>
#include <list>
#include <iterator>
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
						cout << "name: ";
						cin >> stdn.name;
						cout << "score: ";
						cin >> stdn.score;

						listStudent.push_back(stdn);
					}
					break;
				}
				break;
			}

			case 2: {

				list<Student>::iterator ptr;
				for (ptr = listStudent.begin(); ptr != listStudent.end(); ptr++) {
					cout << "id: "<< (*ptr).id;
					cout << "name: " << (*ptr).name;
					cout << "score: " << (*ptr).score;
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