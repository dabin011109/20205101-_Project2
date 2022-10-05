#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

inline double calc_volume(double radius) {
    return (4.0 / 3.0 * 3.14 * pow(radius, 3));
}

bool pw_check(string pw) {
    for (auto& s : pw) {
        if ((s >= 48 && s <= 57) && (s >= 'a' && s <= 'z') && (s >= 'A' && s <= 'Z'))
            return true;
        else return false;
    }
}

int main() {

    // p.160, 2�� ����
    double r, volume;
    cout << "�������� �Է��Ͻÿ�: ";
    cin >> r;
    volume = calc_volume(r);

    cout << "���� ���Ǵ� " << volume << endl;

    // p.162, 9�� ����
    int dice1, dice2, sum;

    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;

    cout << "������� �ֻ���: " << dice1 << "+" << dice2 << "=" << sum << endl;
    if ((sum == 7) || (sum == 11))
        cout << "����ڰ� �̰���ϴ�." << endl;
    else if ((sum == 2) || (sum == 3) || (sum == 12))
        cout << "����ڰ� �����ϴ�." << endl;
    else
        cout << "�����ϴ�." << endl;

    // p.164, 13�� ����
    string password;

    cout << "��ȣ�� �Է��Ͻÿ�: ";
    cin >> password;

    bool check = pw_check(password);
    if (check == true)
        cout << "�����մϴ�." << endl;
    else
        cout << "�������� �ʽ��ϴ�." << endl;

}