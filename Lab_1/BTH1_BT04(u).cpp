#include <iostream>
using namespace std;
const int maxr = 5, maxc = 6;
void nhap(int& a, int b, int c)
{
	do {
		cin >> a;
		if (a <= c || a > b)
			cout << "Nhap sai. Nhap lai:\t";
	} while (a <= c || a > b);
}
void nhapGiaTri(int a[][maxc], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap " << c << " gia tri vao dong thu " << i + 1 << ":\t";
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
		cout << endl;
	}
}
void chon(int r, int c, int& ruse, int& cuse)
{
	int chon;
	do {
		cout << "Chon hang hay cot?\n1. Hang\n2. Cot\n\n";
		cin >> chon;
		if (chon < 1 || chon > 2)
			cout << "Chi chon 1 trong 2. Chon lai.\n";
	} while (chon < 1 || chon > 2);
	switch (chon)
	{
	case 1:
		cout << "\nHang thu bao nhieu?\t";
		nhap(ruse, r - 1, -1);
		break;
	case 2:
		cout << "\nCot thu bao nhieu?\t";
		nhap(cuse, c - 1, -1);
		break;
	}
}
int tong(int a[][maxc], int r, int c, int& ruse, int& cuse)
{
	int tong = 0;
	if (ruse != -1)
		for (int i = 0; i < c; i++)
			tong += a[ruse][i];
	else if (cuse != -1)
		for (int i = 0; i < r; i++)
			tong += a[i][cuse];
	return tong;
}
void timX(int b[][maxc], int a[][maxc], int r, int c, int x, int& dem)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (x == a[i][j])
			{
				for (int m = 0; m < 3; i++)
					b[dem][m] = a[i][j];
				dem++;
			}
	if (dem == 0)
		cout << x << " khong ton tai.\n";

}
int main()
{
	int r, c, rtam = -1, ctam = -1, x, dem = 0;
	int max, min, minC, minR, maxC, maxR;
	int a[maxr][maxc];
	int b[maxr][maxc] = {0};
	// a
	cout << "Nhap so hang:\t";
	nhap(r, maxr, 0);
	cout << "Nhap so cot:\t";
	nhap(c, maxc, 0);
	nhapGiaTri(a, r, c);
	// b
	chon(r, c, rtam, ctam);
	if (rtam != -1)
		cout << "\nTong cua hang " << rtam << " la " << tong(a, r, c, rtam, ctam);

	else if (ctam != -1)
		cout << "Tong cua cot " << ctam << " la ";
	cout << tong(a, r, c, rtam, ctam);
	// c
	cout << "\nNhap gia tri x bat ky:\t";
	nhap(x, INT_MAX, INT_MIN);
	timX(b, a, r, c, x, dem);
	if (dem != 0)
		cout << "x xuat hien " << dem << " lan, tai cac vi tri:\n";
	for (int i = 0; i < dem; i++)
		for (int j = 0; j < 3; j++)
		{
			cout << "\tHang " << i << " cot " << j;
			cout << endl;
		}
}