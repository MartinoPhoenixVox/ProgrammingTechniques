#include <iostream>
using namespace std;
void nhap(int& n, int x, int y)
{
	do {
		cin >> n;
		if (n < x || n > y)
			cout << "Gia tri nhap sai. Moi nhap lai:\t";
	} while (n < x || n > y);
}
int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	int d = a % b;
	a = b;
	b = d;
	return UCLN(a, b);
}
int main()
{
	int a, b;
	cout << "Nhap so nguyen thu 1:\t";
	nhap(a, INT_MIN, INT_MAX);
	cout << "Nhap so nguyen thu 2:\t";
	nhap(b, INT_MIN, INT_MAX);
	cout << "Uoc chung lon nhut cua " << a << " va " << b << " la " << UCLN(a, b) << endl;
	return 0;
}