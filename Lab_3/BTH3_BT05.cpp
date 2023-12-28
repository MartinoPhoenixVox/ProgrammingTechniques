#include <iostream>
using namespace std;
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n < a || n > b)
			cout << "Nhap lai:\t";
	} while (n < a || n > b);
	cout << endl;
}
void fibo(int*& a, int n)
{
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
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
int main()
{
	int n;
	cout << "Ban muon xuat bao nhieu so Fibonacci?\t";
	nhap(n, 1, INT_MAX);
	int* a;
	a = new int [n];
	fibo(a, n);
	xuatMang(a, n);
	delete []a;
	a = NULL;
	return 0;
}