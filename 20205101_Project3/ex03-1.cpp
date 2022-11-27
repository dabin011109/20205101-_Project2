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

	// const & : ���簡 ���� �ʰ� �� ���浵 �ȵ� -> ȿ����
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

	// �Լ��� ���۷����� ���̸� �ε��� ��ġ�� ���� �ٷ� �ٲ� �� ����
	char& operator[](int index)
	{
		return _chars[index];
	}
};

int main()
{
	Vector v0{ 1, 2, 3 }; // �ε��� ������ [](÷�ڿ�����)
	cout << v0[0] << endl; // x=1 v0.operator[](int index)
	cout << v0[1] << endl; // y=2
	cout << v0[2] << endl; // z=3

	// �Լ��� &�� ���̸� ���� ������ �� ����
	// ������ const�� ������ �� ��ü�� �ٲٴ� ���� �ȵ�
	// v0[0] = 100; �Ұ���
	cout << v0[0] << endl;
	cout << endl;

	String str{ "abc" };
	cout << str[0] << endl; // a
	cout << str[1] << endl; // b
	cout << str[2] << endl; // c
}