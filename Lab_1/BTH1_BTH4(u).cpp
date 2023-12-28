#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXR = 5, MAXC = 6;
void nhap(int& a, int b, int c)
{
	do {
		cin >> a;
		if (a < b || a > c)
			cout << "Nhap sai. Nhap lai.\t";
	} while (a < b || a > c);
	cout << endl;
}
void nhapMang(int a[][MAXC], int& r, int& c)
{
	cout << "Nhap so luong dong:\t";
	nhap(r, 1, MAXR);
	cout << "Nhap so luong cot:";
	nhap(c, 1, MAXC);
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap gia tri vao hang thu " << i << ":\t";
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
		cout << endl;
	}
}
void khoiTao(int a[][MAXC], int& r, int& c)
{
	srand(time(NULL));
	cout << "Nhap so luong dong:\t";
	nhap(r, 1, MAXR);
	cout << "Nhap so luong cot:\t";
	nhap(c, 1, MAXC);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			a[i][j] = rand() % 10;
}
void xuatMang(int a[][MAXC], int r, int c)
{
	cout << "Ta co mang:\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
void chon(int r, int c, int& rg, int& cg)
{
	int chon;
	cout << "Chon dong hay cot:\t";
	nhap(chon, 1, 2);
	switch (chon)
	{
	case 1:
		cout << "Nhap so dong ban chon de thuc hien phep toan:\t";
		nhap(rg, 0, r - 1);
		break;
	case 2:
		cout << "Nhap so cot ban chon de thuc hien phep toan:\t";
		nhap(cg, 0, c - 1);
		break;
	}
}
int tinhTong(int a[][MAXC], int r, int c, int rg, int cg)
{
	int tong = 0;
	if (rg != -1)
		for (int i = 0; i < c; i++)
			tong += a[rg][i];
	if (cg != -1)
		for (int i = 0; i < r; i++)
			tong += a[i][cg];
	return tong;
}
int demX(int a[][MAXC], int r, int c, int x, int& dem)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] = x)
				dem++;
	return dem;
}
int main()
{
//BT4
	int a[MAXR][MAXC];
	int r1, c1, rtam = -1, ctam = -1, tong, x, dem;
	//Nhap mang
	//nhapMang(a, r1, c1);
	//Khoi tao
	khoiTao(a, r1, c1);
	//Nhap mang
	xuatMang(a, r1, c1);
	//Tinh tong
	chon(r1, c1, rtam, ctam);
	if (rtam != -1)
		cout << "Tong cua dong " << rtam << " la " << tinhTong(a, r, c, rtam, ctam);
	else if (rtam != -1)
		cout << "Tong cua cot " << ctam << " la " << tinhTong(a, r, c, rtam, ctam);
	//Nhap x
	nhap(x, INT_MIN, INT_MAX);

	return 0;
}