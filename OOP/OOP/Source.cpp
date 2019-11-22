#include "MyPoint.h"
using namespace std;

int main()
{
	MyPoint* p = new MyPoint(3, 4);
	MyPoint pp;

	pp.SetX(1);
	pp.SetY(2);
	
	cout << "distance: " << p->Distance(pp);
	return 0;
}