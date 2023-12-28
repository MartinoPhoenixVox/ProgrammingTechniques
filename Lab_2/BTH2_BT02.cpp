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
int giaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}
int main()
{
	int n;
	cout << "Nhap 1 so nguyen khong am:\t";
	nhap(n, 0, INT_MAX);
	cout << n << "! =\t" << giaiThua(n);
	cout << endl;
	return 0;
}