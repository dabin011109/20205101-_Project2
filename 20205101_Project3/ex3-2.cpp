#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) : x{ x }, y{ y }, z{ z } { }

	Vector operator=(Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
};

int main()
{
	int a = 1; 
	int b = a; // 복사
	int c;
	c = a; // 대입
	
	Vector v0{ 1, 2, 3 };
	Vector v1 = v0; // 복사
	Vector v2;
	v2 = v0; // 대입 -> v2.operator=(v0)

	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;
}