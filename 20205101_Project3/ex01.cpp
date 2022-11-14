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
		return Vector{ this->x + v.x, y + v.y, z + v.z }; // ���⼭ this�� v0, v�� v1�� ��
	}

	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}

	// �������
	float operator*(const Vector& v)const
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	// ���Ͱ� * �Ǽ���
	Vector operator*(float n)const
	{
		return Vector{ x * n, y * n, z * n };
	}

	// ����, �������������ڴ� ���� ������ ������Ű�Ƿ� const�� ����� �� ����
	Vector& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	Vector& operator++(int) // int�� ������������������ ������������������ �˷��ֱ� ����
	{
		Vector temp = *this; // ������ ���� ����
		++x;
		++y;
		++z;
		return temp;
	}

	// ���׿����� +
	Vector operator+() const
	{
		return Vector{ +x, +y, +z };
	}

	// ���׿����� -
	Vector operator-(const Vector& v) const
	{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}

	// ���׿����� /
	Vector operator/(float n) const
	{
		return Vector{ x / n, y / n, z / n };
	}

	// ���������� --
	Vector& operator--()
	{
		--x;
		--y;
		--z;
		return *this;
	}

	// ���������� --
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

	Vector v2 = v0 + v1; // ���׿����� +, v0.operator+(v1)
	// Vector v2 = v0.operatoer+(v1); ���� �ᵵ ��
	v2.print(); // 1 3 5

	Vector v3 = -v1; // ���׿�����-, v1.operator-(); 
	// -�� �ڽ��� ���� -�� �ٲ��ִ� ���̱� ������ �Ķ���Ͱ� �ʿ����
	v3.print();

	// ���׿����� *
	// 1. ���Ϳ��� �� ������� : (v0.x*v1.x)+(v0.y*v1.y) = float ��
	// 2. ���Ͱ� * �Ǽ��� -> ���Ͱ�

	float v4 = v0 * v1; //v0.operator*(v1)
	cout << v4 << endl; // 0+2+6 = 8

	Vector v5 = v1 * 3.0f; //v1.operator(3.0f)
	v5.print();

	// ++v1 : ����
	// v1++ : ����

	Vector v6 = ++v1; //v1.operator++() -> ���� �����Ǵ� �����̹Ƿ� �Ķ���ʹ� ��� ��
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print();

	// ���׿����� + Ȯ��
	Vector v8 = +v3;
	v8.print();

	// ���׿����� - Ȯ��
	Vector v9 = v1 - v0;
	v9.print();

	// ���׿����� / Ȯ��
	Vector v10 = v5 / 3.0f;
	v10.print();

	// ���������� -- Ȯ��
	Vector v11 = --v1;
	v11.print();
	
	// ���������� -- Ȯ��
	Vector v12 = v1--;
	v12.print();
	v1.print(); // v1�� ���� �������� Ȯ��
}