#include "MyPoint.h"
using namespace std;


MyPoint::MyPoint()
{
}


MyPoint::~MyPoint()
{
}

MyPoint::MyPoint(int x, int y) {
	this->mPosX = x;
	this->mPosY = y;
}

void MyPoint::Display() {
	cout << "X: " << this->mPosX << "\n";
	cout << "y: " << this->mPosY << "\n";
}

void MyPoint::SetX(int x) {
	this->mPosX = x;
}

void MyPoint::SetY(int y) {
	this->mPosY = y;
}

int MyPoint::GetX() {
	return this->mPosX;
}

int MyPoint::GetY() {
	return this->mPosY;
}

float MyPoint::Distance(MyPoint p) {
	float dis;
	dis = sqrt(pow(p.mPosX, 2) + pow(p.mPosY, 2));
	return dis;
}