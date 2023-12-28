#include <iostream>
using namespace std;
void nhap(int& a, int b, int c)
{
	do {
		cin >> a;
		if (a < b || a > c)
			cout << "Nhap lai:\t";
	} while (a < b || a > c);
	cout << endl;
}
void xuat(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << *( *(a + i) + j) << "\t";
		cout << endl << endl;
	}
}
void tamGiacPascal(int** &a, int h)
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				*( *(a + i) + j) = 1;
			else *( *(a + i) + j) = *( *(a + i - 1) + j) + *( *(a + i - 1) + j - 1);
		}
}
int main()
{
	int n;
	cout << "Tam giac bao nhieu don vi?\t";
	nhap(n, 1, 25);
	int **a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int [n];
	tamGiacPascal(a, n);
	xuat(a, n);
	for (int i = 0; i < n; i++)
		delete []a[n];
	delete []a;
	a = NULL;
	return 0;
}