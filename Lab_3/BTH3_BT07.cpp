
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXSIZE 100

using namespace std;

void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "Nhap sai. Nhap lai:\t";
	} while (n <= a || n >= b);
}

void khoiTaoMang(int* a, int &n)
{
	srand(time(NULL));
	cout << "Ban muon khoi tao mang gom bao nhieu gia tri?\t";
	nhap(n, 0, MAXSIZE + 1);
	cout << "Khoi tao mang:\t";
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
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

bool timX(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return true;
	return false;
}

int traX(int* a, int n, int x)
{
	if (timX(a, n, x))
	{
		for (int i = 0; i < n; i++)
			if (a[i] == x)
				return i;
	}
	else a = NULL;
	return -1;
}

int main()
{
	//khai bao va khoi tao
	int size, x;
	int arr[MAXSIZE];

	//khoi tao mang
	khoiTaoMang(arr, size);

	//xuat mang
	cout << "Mang gom cac gia tri sau:";
	xuatMang(arr, size);

	//nhap so nguyen can tim
	cout << "Nhap so nguyen can tim (tu -100 den 100):\t";
	nhap(x, -101, 101);

	// tra ve vi tri xuat hien so nguyen can tim neu co
	if (timX(arr, size, x))
		cout << "Vi tri xuat hien dau tien cua gia tri \"" << x << "\" nam o vi tri [" << traX(arr, size, x) << "]\n";
	else 
		cout << "Mang khong chua gia tri nay.\n";

	//tra ve gia tri
	return 0;
}