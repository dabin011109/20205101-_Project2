#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

int main() {

    // p.353, 1�� ����
    int i;
    cout << "�� ���� ������ �Է��մϱ�? ";
    cin >> i;

    int* p;
    p = new int[i];
    for (int j = 0; j < i; j++) {
        cout << "������ �Է��Ͻÿ� : ";
        cin >> p[j];
    }

    cout << "�Էµ� ������: ";

    for (int j = 0; j < i; j++) {
        cout << p[j] << ", ";
    }

    cout << endl;
    cout << endl;

    delete[] p;


    // p.353, 2�� ����
    int length;

    cout << "�󸶳� ���� �̸��� �Է� �Ͻðڽ��ϱ�? ";
    cin >> length;

    string* names = new string[length];

    for (int i = 0; i < length; i++) {
        cout << "�̸� �Է� # " << i + 1 << ": ";
        cin >> names[i];
    }
    cout << endl;

    cout << "������ �̸� ����Դϴ�." << endl;
    for (int i = 0; i < length; i++) {
        cout << "�̸� #" << i + 1 << ": " << names[i] << endl;
    }

    delete[] names;
}