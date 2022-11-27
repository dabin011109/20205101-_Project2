#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z): x{x}, y{y}, z{z} { }

	// const & : 복사가 되지 않고 값 변경도 안된 -> 효율적
	const float& operator[](int index) const
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}
};

class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	// 함수에 레퍼런스를 붙이면 인덱스 위치에 값을 바로 바꿀 수 있음
	char& operator[](int index)
	{
		return _chars[index];
	}
};

int main()
{
	Vector v0{ 1, 2, 3 }; // 인덱스 연산자 [](첨자연산자)
	cout << v0[0] << endl; // x=1 v0.operator[](int index)
	cout << v0[1] << endl; // y=2
	cout << v0[2] << endl; // z=3

	// 함수에 &를 붙이면 값을 변경할 수 있음
	// 하지만 const가 붙으면 값 자체를 바꾸는 것이 안됨
	// v0[0] = 100; 불가능
	cout << v0[0] << endl;
	cout << endl;

	String str{ "abc" };
	cout << str[0] << endl; // a
	cout << str[1] << endl; // b
	cout << str[2] << endl; // c
}