// p476, 3�� ����

#include<iostream>
#include<string>
using namespace std;

class Employee {
	string name;
	int salary;
public:
	Employee (string n, int s):name{n}, salary{s}{}
	void print()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << this->computeSalary() << endl;
	}
	int computeSalary() 
	{
		return salary;
	}
};

class Manager : public Employee
{
	int bonus;
public:
	Manager(string n, int s, int b) :Employee(n, s)
	{
		bonus = b;
	}
	void print()
	{
		Employee::print();
		cout << "���ʽ�: " << bonus << endl;
		cout << "��ü �޿�: " << computeSalary() << endl;
	}
	int computeSalary()
	{
		return(Employee::computeSalary() + bonus);
	}
};

int main()
{
	Manager m("��ö��", 200, 100);
	m.print();
}