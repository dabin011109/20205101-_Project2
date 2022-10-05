#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

int main() {

	// p.115, 1번 문제
	string str1;
	string str2;

	cout << "첫 번째 문자열: ";
	cin >> str1;

	cout << "두 번째 문자열: ";
	cin >> str2;

	if (str1 == str2)
		cout << "2개의 문자열이 같습니다." << endl;
	else
		cout << "2개의 문자열은 다릅니다." << endl;

	// p.117, 10번 문제
	for (int a = 1; a <= 100; a++) {
		for (int b = 1; b <= 100; b++) {
			for (int c = 1; c <= 100; c++) {
				if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
					cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}

	// p.119, 16번 문제
	int cash = 50, goal = 250;
	int bets = 0, win = 0;

	srand(time(NULL));

	cout << "초기 금액 $" << cash << endl;
	cout << "목표 금액 $" << goal << endl;

	for (int game = 0; game < 1000; game++) {
		while (true) {
			bets++;
			if ((double)rand() / RAND_MAX < 0.5) cash++;

			else cash--;

			if (cash == goal) {
				win++;
				break;
			}
			else if (cash == 0)  break;

		}
	}

	cout << "1000 중의 " << win << "번 승리" << endl;
	cout << "이긴 확률 = " << (double) win / 1000.0 * 100.0 << endl;
	cout << "평균 배팅 횟수 = " << (double) bets / 1000 << endl;
}