#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x, float y, float z): x{x}, y{y}, z{z}{}

	// cin, cout은 이미 정의된 이름이므로 멤버함수로 만들 수 없음 -> 전역함수로 만들어 줘야 함
	// 이때 클래스 내부 변수를 이용하려면 전역함수 앞에 friend 키워드 사용
	friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}

	friend istream& operator>>(istream& is, Vector& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}

};

int main()
{
	// 벡터 자체를 입력, 출력하는 연산자 오버로딩 함수
	Vector v0{ 1, 2, 3 };
	cout << v0 << endl; 
	// cout.operator(v) : cout은 어딘가에 이미 정의되어 있으므로 이런표현은 안됨
	// -> operator<<(cout, v)<<enld;->endl, cout 멤버함수 cout.enld

	Vector v1;
	cin >> v1; // operator>>(cin, v)
	cout << v1 << endl;
}