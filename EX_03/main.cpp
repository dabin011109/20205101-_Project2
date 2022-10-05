#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

int main() {

    // p.353, 1번 문제
    int i;
    cout << "몇 개의 정수를 입력합니까? ";
    cin >> i;

    int* p;
    p = new int[i];
    for (int j = 0; j < i; j++) {
        cout << "정수를 입력하시오 : ";
        cin >> p[j];
    }

    cout << "입력된 정수는: ";

    for (int j = 0; j < i; j++) {
        cout << p[j] << ", ";
    }

    cout << endl;
    cout << endl;

    delete[] p;


    // p.353, 2번 문제
    int length;

    cout << "얼마나 많은 이름을 입력 하시겠습니까? ";
    cin >> length;

    string* names = new string[length];

    for (int i = 0; i < length; i++) {
        cout << "이름 입력 # " << i + 1 << ": ";
        cin >> names[i];
    }
    cout << endl;

    cout << "다음은 이름 목록입니다." << endl;
    for (int i = 0; i < length; i++) {
        cout << "이름 #" << i + 1 << ": " << names[i] << endl;
    }

    delete[] names;
}