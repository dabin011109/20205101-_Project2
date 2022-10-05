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

    // p.160, 2번 문제
    double r, volume;
    cout << "반지름을 입력하시오: ";
    cin >> r;
    volume = calc_volume(r);

    cout << "구의 부피는 " << volume << endl;

    // p.162, 9번 문제
    int dice1, dice2, sum;

    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;

    cout << "사용자의 주사위: " << dice1 << "+" << dice2 << "=" << sum << endl;
    if ((sum == 7) || (sum == 11))
        cout << "사용자가 이겼습니다." << endl;
    else if ((sum == 2) || (sum == 3) || (sum == 12))
        cout << "사용자가 졌습니다." << endl;
    else
        cout << "비겼습니다." << endl;

    // p.164, 13번 문제
    string password;

    cout << "암호를 입력하시오: ";
    cin >> password;

    bool check = pw_check(password);
    if (check == true)
        cout << "안전합니다." << endl;
    else
        cout << "안전하지 않습니다." << endl;

}