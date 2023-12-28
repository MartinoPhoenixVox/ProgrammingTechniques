#include <iostream>
using namespace std;
#define MAXN 10
void nhap(int& a, int b, int c)
{
	do {
		cin >> a;
		if (a < b || a > c)
			cout << "Nhap sai. Nhap lai.\t";
	} while (a < b || a > c);
	cout << endl;
}
void xuatMang(int a[][MAXN],int n)
{
	cout << "Ta co mang:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
int main()
{
	int a[MAXN][MAXN];
	int n, val = 1;
	cout << "Nhap n:";
	nhap(n, 2, MAXN);
	for (int i = 0; i < n; i++)
		if (i % 2 != 0)
			for (int j = n - 1; j >= 0; j--)
				a[j][i] = val++;
		else 
			for (int j = 0; j < n; j++)
				a[j][i] = val++;
	xuatMang(a, n);
	return 0;
}
