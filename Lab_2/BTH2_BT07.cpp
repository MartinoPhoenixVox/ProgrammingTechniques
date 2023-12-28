#include <iostream>
using namespace std;
void nhap(int& n, int x, int y)
{
	do {
		cin >> n;
		if (n < x || n > y)
			cout << "Gia tri nhap sai. Moi nhap lai:\t";
	} while (n < x || n > y);
	cout << endl;
}
int tongChan(int n, int s)
{
	if (n == 0)
		return s;
	int m = n % 10;
	if (m % 2 == 0)
		s += m;
	return tongChan(n / 10, s);
}
int tongLe(int n, int s)
{
	if (n == 0)
		return s;
	int k = n % 10;
	if (k % 2 != 0)
		s += k;
	return tongLe(n / 10, s);
}
int main()
{
	int n, tong = 0;
	cout << "Nhap 1 so nguyen khong am:\t";
	nhap(n, 0, INT_MAX);
	cout << "Tong chan cua " << n << " la " << tongChan(n, tong) << endl;
	tong = 0;
	cout << "Tong le cua " << n << " la " << tongLe(n, tong) << endl;
	return 0;
}