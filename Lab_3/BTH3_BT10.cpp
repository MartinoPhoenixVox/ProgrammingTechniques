//dung cap phat dong khoi tao ngau nhien 2 ma tran
// tinh tong va tich cua chung

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

#define maxr 100
#define maxc 100

void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "Nhap lai:\t";
	} while (n <= a || n >= b);
	cout << endl;
}

// khoi tao mang ngau nhien (xong)
void khoiTaoMang(int** &a, int &row, int &col, char k)
{
	srand(time(0));
	cout << "Nhap so dong ma tran " << k << ":\t";
	nhap(row, 0, 10);
	cout << "Nhap so cot ma tran " << k << ":\t";
	nhap(col, 0, 10);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % 10;
		}
}

void xuatMang(int**& a, int& row, int& col, char k)
{
	cout << "Mang " << k << " co nhung gia tri sau:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

//tinh tong 2 mang
void tinhTong(int **a, int **b, int** &c, int ra, int ca, int rb, int cb, int &rc, int &cc, int & check)
{
	if (ra == rb && ca == cb)
	{
		rc = ra;
		cc = ca;
		for (int i = 0; i < rc; i++)
			for (int j = 0; j < cc; j++)
				c[i][j] = a[i][j] + b[i][j];
		check = 1;
		cout << "Thuc hien phep tinh thanh cong!\n";
	}
	else cout << "Phep tinh khong thuc hien duoc!\n";
}

//tinh tich 2 mang
void tinhTich(int** a, int** b, int**& c, int ra, int ca, int rb, int cb, int& rc, int& cc, int& check)
{
	if (rb == ca)
	{
		rc = ra;
		cc = cb;
		for (int i = 0; i < rc; i++)
			for (int j = 0; j < cc; j++)
			{
				c[i][j] = 0;
					for (int m = 0; m < rb; m++)
						c[i][j] += a[i][m] * b[m][j];
			}
		check = 2;
		cout << "Thuc hien phep tinh thanh cong!\n";
	}
	else cout << "Phep tinh khong thuc hien duoc!\n";
}

int main()
{
	//khai bao va khoi tao bien
	int ra, ca, rb, cb, rkq, ckq;
	int chon, chon1, chon2, tinh = 0;
	bool taoA = false, taoB = false;
	char ten;

	//khai bao va khoi tao cap phat dong (xong)
	int** a;
	a = new int* [maxr];
	for (int i = 0; i < maxr; i++)
		a[i] = new int[maxc];

	int** b;
	b = new int* [maxr];
	for (int i = 0; i < maxr; i++)
		b[i] = new int[maxc];

	int** kq;
	kq = new int* [maxr];
	for (int i = 0; i < maxr; i++)
		kq[i] = new int[maxc];

	//MENU
	/*
	* 1. Khoi tao mang 
	*	1.1. Mang A
	*	1.2. Mang B
	* 2. Xuat mang
	*	2.1. Mang A
	*	2.2. Mang B
	*	2.3. Mang ket qua
	* 3. Tinh tong 2 mang A B
	* 4. Tinh tich 2 mang A B
	* 5. Thoat
	*/

	cout << "\"Hello, world!\"";
	_getch();

	do {
		system("cls");
		cout << "MENU:\n"
			<< "1. Khoi tao mang\n"
			<< "2. Xuat mang\n"
			<< "3. Tinh tong 2 mang\n"
			<< "4. Tinh tich 2 mang\n"
			<< "5. Thoat chuong trinh\n"
			<< "Ban chon:\t";
		nhap(chon, 0, 6);
		switch (chon)
		{
		case 1: //xong
			cout << "1. Mang A\n"
				<< "2. Mang B\n"
				<< "Ban chon:\t";
			nhap(chon1, 0, 3);
			switch (chon1)
			{
			case 1:
				ten = 'A';
				khoiTaoMang(a, ra, ca, ten);
				taoA = true;
				break;
			case 2:
				ten = 'B';
				khoiTaoMang(b, rb, cb, ten);
				taoB = true;
				break;
			default:
				cout << "Ban quyet dinh khong khoi tao mang!\n";
			}
			break;
		case 2: //xong
			cout << "1. Mang A\n"
				<< "2. Mang B\n"
				<< "3. Mang ket qua (neu la phep cong thi mang ten \"+\"; neu la phep nhan thi mang ten \"*\")\n"
				<< "Ban chon:\t";
			nhap(chon2, 0, 4);
			switch (chon2)
			{
			case 1:
				ten = 'A';
				if (!taoA)
					cout << "Ban chua tao mang A!\n";
				else xuatMang(a, ra, ca, ten);
				break;
			case 2:
				ten = 'B';
				if (!taoB)
					cout << "Ban chua tao mang B!\n";
				else xuatMang(b, rb, cb, ten);
				break;
			case 3:
				if (tinh == 0)
					cout << "Ban chua thuc hien phep tinh!\n";
				else if (tinh == 1)
				{
					ten = '+';
					xuatMang(kq, rkq, ckq, ten);
				}
				else
				{
					ten = '*';
					xuatMang(kq, rkq, ckq, ten);
				}
				break;
			default:
				cout << "Ban quyet dinh khong khoi tao mang!\n";
			}
			break;
		case 3: //xong
			if (taoA && taoB)
			{
				tinhTong(a, b, kq, ra, ca, rb, cb, rkq, ckq, tinh);
			}
			else cout << "Ban chua khoi tao du so luong mang!\n";
			break;
		case 4: //xong
			if (taoA && taoB)
			{
				tinhTich(a, b, kq, ra, ca, rb, cb, rkq, ckq, tinh);
			}
			else cout << "Ban chua khoi tao du so luong mang!\n";
			break;
		default:
			cout << "Ban chon thoat chuong trinh.\n"
				<< "\"Goodbye, world!\"";
		}
		_getch();
	} while (chon >= 1 && chon <= 4);



	//xoa cap phat dong (xong)
	for (int i = 0; i < maxr; i++)
		delete[]a[i];
	delete[]a;
	a = NULL;

	for (int i = 0; i < maxr; i++)
		delete[]b[i];
	delete[]b;
	b = NULL;

	for (int i = 0; i < maxr; i++)
		delete[]kq[i];
	delete[]kq;
	kq = NULL;

	//tra ve gia tri (xong)
	return 0;
}
