#include <iostream>
using namespace std;
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n < a || n > b)
			cout << "Nhap sai gia tri. Nhap lai:\t";
	} while (n < a || n > b);
	cout << endl;
}
int thapNhi(int n)
{
	if (n == 0)
		return 0;
	return n % 2 + thapNhi(n / 2) * 10;
}
int main()
{
	int n;
	cout << "Nhap 1 so nguyen duong:\t";
	nhap(n, 1, INT_MAX);
	cout << "So thap phan can chuyen doi:\t" << n << endl
		<< "Ket qua nhi phan:\t" << thapNhi(n) << endl;
	return 0;
}