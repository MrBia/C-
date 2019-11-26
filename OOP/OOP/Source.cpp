#include <cstdlib>
#include "patient.h"
#include <time.h>
#include <vld.h>

int main()
{
	
	patient p;
	int t;
	p.show();
	while (p.GetState() == 1) {
		printf("Take Medicine (0 = NO, 1 = YES)\n"); 

		cin >> t;
		if (t == 1) {
			int min = 1;
			int max = 30; 
			srand(time(0));
			int medicine_resistance = min + rand() % (max - min + 1);
			cout << "mecidin: " << medicine_resistance << "\n";
			p.TakeMedicine(medicine_resistance);
			p.show();
			
		}
		else if (t == 2) {
			break;
		}
	}

	return 0;
}
