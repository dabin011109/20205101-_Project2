// p470, student 클래스 작성

#include<iostream>
#include<string>
using namespace std;

class Person
{
	string name;
	int birthYear;
public:
	Person(string name, int year)
	{
		this->name = name;
		this->birthYear = year;
	}
	void print()
	{
		cout << "성명: " << name << endl;
		cout << "출생연도: " << birthYear << endl;
	}
};

// 상속
class Student :public Person
{
	string university;
public:
	Student(string name, int year, string university) : Person(name, year) // 부모 클래스 생성자 호출
	{
		this->university = university;
	}
	// 멤버 함수 재정의
	void print()
	{
		// 부모 클래스의 멤버 함수 호출 : 부모 클래스::함수이름 -> 범위연산자 사용
		Person::print();
		cout << "대학교: " << university << endl;
	}
};

int main()
{
	Student s("홍길동", 1997, "한국대학교");
	s.print();
	return 0;
}