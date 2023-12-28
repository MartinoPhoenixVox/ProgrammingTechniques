// btlt 2
// dung cap phat dong
#include <iostream>
#include <conio.h>

using namespace std;

#define maxr 30
#define maxc 30
#define MAXSIZE 900

void nhap(int &n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "Nhap sai. Nhap lai:\t";
	} while (n <= a || n >= b);
	cout << endl;
}

// nhap 1 mang so nguyen row dong, col cot
void nhapMang(int **&a, int &row, int &col, bool &k)
{
	cout << "Nhap so dong:\t";
	nhap(row, 1, maxr);
	cout << "Nhap so cot:\t";
	nhap(col, 1, maxc);
	for (int i = 0; i < row; i++)
	{
		cout << "Nhap gia tri dong thu " << i << ":\t";
		for (int j = 0; j < col; j++)
			cin >> a[i][j];
		cout << endl;
	}
	k = true;
}

// xuat 1 mang so nguyen row dong, col cot
void xuatMang(int **a, int row, int col)
{
	cout << "Mang da duoc nhap:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << *(*(a + i) + j);
		cout << endl;
	}
}
void xuatMang1D(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << a[i];
	}
	cout << endl;
}

// tinh tong phan tu so nguyen to
bool kiemSNT(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x * 1.0); i++)
		if (x % i == 0)
			return false;
	return true;
}
int tongSNT(int **a, int row, int col)
{
	int tong = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (kiemSNT(*(*(a + i) + j)))
				tong += *(*(a + i) + j);
	return tong;
}

// tra ve so nguyen to trong mang
void traSNT(int **a, int row, int col, int kq[], int &n)
{
	n = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (kiemSNT(*(*(a + i) + j)))
			{
				kq[n] = *(*(a + i) + j);
				n++;
			}		
}

int main()
{
	//khai bao va khoi tao
	bool check = false;
	int chon = 0;
	int r = 1, c = 1, n;
	int **a;
	a = new int* [r];
	for (int i = 0; i < r; i++)
		a[i] = new int [c];
	int soNguyenTo[MAXSIZE] = { 0 };
	
	// menu 
	do {
		system("cls");
		cout << "Chuc nang:\n"
			<< "1. Nhap mang\n"
			<< "2. Xuat mang\n"
			<< "3. Tinh tong so nguyen to trong mang\n"
			<< "4. Tra ve so nguyen to trong mang\n"
			<< "5. Thoat\n"
			<< "Ban chon:\t";
		nhap(chon, 0, 6);
		switch (chon)
		{
		case 1:
			nhapMang(a, r, c, check);
			break;
		case 2:
			if (check)
			{
				xuatMang(a, r, c);
			}
			else cout << "Vui long nhap mang\n";
			break;
		case 3:
			if (check)
			{
				if (tongSNT(a, r, c) != 0)
					cout << "Tong cac so nguyen to trong mang =" << tongSNT(a, r, c) << endl;
				else cout << "Mang khong co so nguyen to.\n";
			}
			else cout << "Vui long nhap mang\n";
			break;
		case 4:
			if (check)
			{
				if (tongSNT(a, r, c) != 0)
				{
					traSNT(a, r, c, soNguyenTo, n);
					xuatMang1D(soNguyenTo, n);
				}
				else cout << "Mang khong co so nguyen to.\n";
			}
			else cout << "Vui long nhap mang\n";
			break;
		default:
			cout << "Ban chon thoat. Dang thoat chuong trinh...\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 4);

	// xoa cap phat dong
	for (int i = 0; i < r; i++)
		delete [] a[i];
	delete [] a;

	//tra ve gia tri
	return 0;
}