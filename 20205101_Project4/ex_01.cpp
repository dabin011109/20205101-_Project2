// p434, 3�� ����

#include<iostream>

using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
public:
	Box(int l = 0, int w = 0, int h = 0) :length(l), width(w), height(h){ }
	double getVolume(void) {
		return length * width * height;
	}
	bool operator<(Box& b) 
	{
		return (this->getVolume() < b.getVolume());
	}
	friend void printBox(Box box) 
	{
		cout << "������ ����: " << box.length << endl;
		cout << "������ �ʺ�: " << box.width << endl;
		cout << "������ ����: " << box.height << endl;
		cout << "������ ����: " << box.getVolume() << endl;
		cout << endl;
	}
};


int main()
{
	Box a(10, 10, 10), b(20, 20, 20);
	cout << "���� #1" << endl;
	printBox(a);

	cout << "���� #2" << endl;
	printBox(b);

	if (a < b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}