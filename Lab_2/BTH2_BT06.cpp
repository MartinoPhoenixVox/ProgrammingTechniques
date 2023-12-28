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
int soDaoNguoc(int n, int sdn)
{
	if (n == 0)
		return sdn;
	sdn *= 10;
	sdn += n % 10;
	return soDaoNguoc(n / 10, sdn);
}
int main()
{
	int n, sdn = 0;
	cout << "Nhap 1 so nguyen khong am:\t";
	nhap(n, 0, INT_MAX);
	cout << "So dao nguoc cua " << n << " la " << soDaoNguoc(n, sdn) << endl;;
	return 0;
}