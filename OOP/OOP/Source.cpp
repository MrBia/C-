#include <cstdlib>
#include "patient.h"


int main()
{
	patient p;
	char t;
	while (p.GetState() == 1) {
		printf("Take Medicine (0 = NO, 1 = YES)\n"); 
		//scanf("%c", &t);
		cin >> t;
		if (t == 1) {
			int min = 1;
			int max = 60; 
			int medicine_resistance = min + rand() % (max - min + 1);
			p.TakeMedicine(medicine_resistance);
		}
	}

	return 0;
}