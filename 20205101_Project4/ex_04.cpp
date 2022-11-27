// p476, 3번 문제

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
		cout << "이름: " << name << endl;
		cout << "월급: " << this->computeSalary() << endl;
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
		cout << "보너스: " << bonus << endl;
		cout << "전체 급여: " << computeSalary() << endl;
	}
	int computeSalary()
	{
		return(Employee::computeSalary() + bonus);
	}
};

int main()
{
	Manager m("김철수", 200, 100);
	m.print();
}