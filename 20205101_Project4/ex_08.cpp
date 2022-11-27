// p591, 4번 문제

#include<iostream>
using namespace std;

template<typename T>
T getSmalleset(T arr[], int n) {
	T min = arr[0];
	for (int i = 0; i < n; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int main()
{
	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "최소값: " << getSmalleset(list, 5) << endl;
}