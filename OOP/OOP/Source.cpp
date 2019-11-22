#include "MyPoint.h"
using namespace std;

int main()
{
	MyPoint* p = new MyPoint(3, 4);
	MyPoint pp = *p;

	p->Display();
	cout << "distance: "<< p->Distance(pp) << "\n";

	p->SetX(1);
	p->SetY(2);
	cout << "x: " << p->GetX() << "\n";
	cout << "y: " << p->GetY() << "\n";
	pp = *p;
	cout << "distance: " << p->Distance(pp) << "\n";
	return 0;
}