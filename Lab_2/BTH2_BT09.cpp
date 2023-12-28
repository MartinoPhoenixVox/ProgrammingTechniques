/*Ham de quy chuyen so nguyen dang nhi phan sang thap phan
Nhap: so nhi phan
Xuat: so thap phan
Vd: 11011 => 1*2^4 + 1*2^3 + 0*2^2 + 1*2^1 + 1*2^0=*/
#include <iostream>
using namespace std;
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n < a || n > b)
			cout << "Nhap sai gia tri. NHap lai:\t";
	} while (n < a|| n > b);
	cout << endl;
}
int luyThua(int a, int n)
{
	if (n == 0)
		return 1;
	return a * luyThua(a, n - 1);
}
int dem(int n)
{
	if (n < 10)
		return 1;
	return 1 + dem(n / 10);
}
int dao(int n)
{
	if (n < 10)
		return n;
	return n % 10 * luyThua(10, dem(n) - 1) + dao(n / 10);
}
int nhiThap(int n)
{
	if (n < 1)
		return n;
	return n % 10 * luyThua(2, dem(n) - 1) + nhiThap(n / 10);
}
int main()
{
	int n;
	cout << "Nhap 1 so nguyen dang nhi phan:\t";
	nhap(n, 0, INT_MAX);
	cout << "Dang thap phan cua " << n << ":\t";
	n = dao(n);
	cout << nhiThap(n); 
	return 0;
}