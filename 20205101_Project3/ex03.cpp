#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x, float y, float z): x{x}, y{y}, z{z}{}

	// cin, cout�� �̹� ���ǵ� �̸��̹Ƿ� ����Լ��� ���� �� ���� -> �����Լ��� ����� ��� ��
	// �̶� Ŭ���� ���� ������ �̿��Ϸ��� �����Լ� �տ� friend Ű���� ���
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
	// ���� ��ü�� �Է�, ����ϴ� ������ �����ε� �Լ�
	Vector v0{ 1, 2, 3 };
	cout << v0 << endl; 
	// cout.operator(v) : cout�� ��򰡿� �̹� ���ǵǾ� �����Ƿ� �̷�ǥ���� �ȵ�
	// -> operator<<(cout, v)<<enld;->endl, cout ����Լ� cout.enld

	Vector v1;
	cin >> v1; // operator>>(cin, v)
	cout << v1 << endl;
}