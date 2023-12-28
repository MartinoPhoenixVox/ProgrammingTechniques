#include <iostream>
using namespace std;
void nhap(int& a, int b, int c)
{
	do {
		cin >> a;
		if (a < b || a > c)
			cout << "Nhap sai. Nhap lai:\t";
	} while (a < b || a > c);
	cout << endl;
}
void nhapMang(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri thu " << i << ":\t";
		cin >> a[i];
	}
	cout << endl;
}
void xuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << a[i] << "\t";
	}
	cout << endl;
}
void daoSo(int& a, int& b)
{
	int tam = 0;
	tam = a;
	a = b;
	b = tam;
}
void daoMang(int*& a, int n)
{
	for (int i = 0; i <= n / 2 - 1; i++)
	{
		daoSo(a[i], a[n - 1 - i]);
	}
}
int main()
{
	int n;
	cout << "Ban muon nhap bao nhieu gia tri?\t";
	nhap(n, 1, INT_MAX);
	int* a;
	a = new int [n];
	nhapMang(a, n);
	cout << "Mang dang luu tru:";
	xuatMang(a, n);
	daoMang(a, n);
	cout << "Mang sau khi dao nguoc:";
	xuatMang(a, n);
	delete[] a;
	a = NULL;
	return 0;
}