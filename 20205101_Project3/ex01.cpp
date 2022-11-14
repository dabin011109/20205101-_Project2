#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	Vector operator+(const Vector& v)const 
	{
		return Vector{ this->x + v.x, y + v.y, z + v.z }; // 여기서 this는 v0, v는 v1이 됨
	}

	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}

	// 내적계산
	float operator*(const Vector& v)const
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	// 벡터값 * 실수값
	Vector operator*(float n)const
	{
		return Vector{ x * n, y * n, z * n };
	}

	// 전위, 후위증감연산자는 값을 실제로 증가시키므로 const를 사용할 수 없음
	Vector& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	Vector& operator++(int) // int는 전위증감연산자인지 후위증감연산자인지 알려주기 위함
	{
		Vector temp = *this; // 현재의 상태 저장
		++x;
		++y;
		++z;
		return temp;
	}

	// 단항연산자 +
	Vector operator+() const
	{
		return Vector{ +x, +y, +z };
	}

	// 이항연산자 -
	Vector operator-(const Vector& v) const
	{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}

	// 이항연산자 /
	Vector operator/(float n) const
	{
		return Vector{ x / n, y / n, z / n };
	}

	// 전위연산자 --
	Vector& operator--()
	{
		--x;
		--y;
		--z;
		return *this;
	}

	// 후위연산자 --
	Vector& operator--(int)
	{
		Vector temp = *this;
		--(*this);
		return temp;
	}

	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

int main()
{
	Vector v0{ 0, 1, 2 };
	Vector v1{ 1, 2, 3 };

	Vector v2 = v0 + v1; // 이항연산자 +, v0.operator+(v1)
	// Vector v2 = v0.operatoer+(v1); 으로 써도 됨
	v2.print(); // 1 3 5

	Vector v3 = -v1; // 단항연산자-, v1.operator-(); 
	// -나 자신의 값을 -로 바꿔주는 것이기 때문에 파라미터가 필요없음
	v3.print();

	// 이항연산자 *
	// 1. 벡터연산 중 내적계산 : (v0.x*v1.x)+(v0.y*v1.y) = float 값
	// 2. 벡터값 * 실수값 -> 벡터값

	float v4 = v0 * v1; //v0.operator*(v1)
	cout << v4 << endl; // 0+2+6 = 8

	Vector v5 = v1 * 3.0f; //v1.operator(3.0f)
	v5.print();

	// ++v1 : 전위
	// v1++ : 후위

	Vector v6 = ++v1; //v1.operator++() -> 내가 증가되는 과정이므로 파라미터는 없어도 됨
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print();

	// 단항연산자 + 확인
	Vector v8 = +v3;
	v8.print();

	// 이항연산자 - 확인
	Vector v9 = v1 - v0;
	v9.print();

	// 이항연산자 / 확인
	Vector v10 = v5 / 3.0f;
	v10.print();

	// 전위연산자 -- 확인
	Vector v11 = --v1;
	v11.print();
	
	// 후위연산자 -- 확인
	Vector v12 = v1--;
	v12.print();
	v1.print(); // v1을 통해 후위연산 확인
}