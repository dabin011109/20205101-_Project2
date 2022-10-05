#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

int main() {

	// p.115, 1�� ����
	string str1;
	string str2;

	cout << "ù ��° ���ڿ�: ";
	cin >> str1;

	cout << "�� ��° ���ڿ�: ";
	cin >> str2;

	if (str1 == str2)
		cout << "2���� ���ڿ��� �����ϴ�." << endl;
	else
		cout << "2���� ���ڿ��� �ٸ��ϴ�." << endl;

	// p.117, 10�� ����
	for (int a = 1; a <= 100; a++) {
		for (int b = 1; b <= 100; b++) {
			for (int c = 1; c <= 100; c++) {
				if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
					cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}

	// p.119, 16�� ����
	int cash = 50, goal = 250;
	int bets = 0, win = 0;
	bool result;
	int wins = 0, total = 0;

	cout << "�ʱ� �ݾ� $" << cash << endl;
	cout << "��ǥ �ݾ� $" << goal << endl;

	srand((unsigned int)time(NULL));

	for (int game = 0; game < 1000; game++)
	{
		while (true)
		{
			bets++;
			if ((double)rand() / RAND_MAX < 0.5)
			{
				cash++;
				win++;
			}
			else cash--;

			if (cash <= 0)
			{
				result = false;
				break;
			}
			if (cash >= goal) {
				result = true;
				break;
			}
		}
		if (result == true) wins++;
	}
	cout << "1000 ���� " << wins << "�� �¸�" << endl;
	cout << "�̱� Ȯ�� = " << wins / 1000 * 100 << endl;
	cout << "��� ���� Ƚ�� = " << bets / 1000.0 << endl;
}