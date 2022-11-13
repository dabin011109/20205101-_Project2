#include<iostream>
#include<cstring> // strcpy, strcmp 등을 사용 가능
using namespace std;

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

	bool operator==(const String& str)const
	{
		return strcmp(_chars, str._chars) == 0; //true
	}

	bool operator>(const String& str)const
	{
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str)const
	{
		// <=의 반대? -> >
		return !(*this > str); // 이미 정의된 것을 이용
	}


	// !=의 반대 -> ==
	bool operator!=(const String& str)const
	{
		return !(*this == str);
	}

	// <
	bool operator<(const String& str)const
	{
		return strcmp(_chars, str._chars) < 0;
	}

	// >=
	bool operator>=(const String& str)const
	{
		return !(*this < str);
	}
};

int main()
{
	String str0{ "abc" };
	String str1{ "cde" };

	if (str0 == str1) // str0.operator==(str1)
		cout << "equal" << endl;

	if (str0 > str1) // str0.operator>(str1)
		cout << "str0>str1" << endl;

	if (str0 <= str1) // str0.operator<=(str1)
		cout << "str0<=str1" << endl;

	// != 확인
	if (str0 != str1)
		cout << "false" << endl;
	
	// < 확인
	if (str0 < str1)
		cout << "str0<str1" << endl;

	// >= 확인
	if (str0 >= str1)
		cout << "str0>=str1" << endl;
}