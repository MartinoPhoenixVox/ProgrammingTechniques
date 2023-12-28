#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAXSIZE 100
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n < a || n > b)
			cout << "Nhap gia tri sai. Nhap lai:\n";
	} while (n < a || n > b);
	cout << endl;
}
void khoiTaoMang(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
void xuatMang(const int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << a[i] << "\t";
	}
	cout << endl;
}
int tinhTong(const int a[], int n)
{
	if (n == 0)
		return a[n];
	return a[n] + tinhTong(a, n - 1);
}
int main()
{
	int a[MAXSIZE];
	int size;
	cout << "Ban muon mang chua bao nhieu gia tri?\t";
	nhap(size, 1, MAXSIZE);
	khoiTaoMang(a, size);
	cout << "Mang ngau nhien luu tru:";
	xuatMang(a, size);
	cout << "Tong cac gia tri trong mang bang " << tinhTong(a, size - 1) << endl;
	return 0;
}