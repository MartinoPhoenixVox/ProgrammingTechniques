#include <iostream>
#include <conio.h>
using namespace std;

//nhap gia tri so nguyen
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "NHAP SAI. NHAP LAI:";
	} while (n <= a || n >= b);
}

//tri tuyet doi cua so nguyen
int tri(int a)
{
	if (a < 0)
		return -a;
	return a;
}

//dinh nghia kieu du lieu PhanSo
struct PhanSo
{
	int tu, mau;
};

//nhap phan so
void nhapPS(PhanSo& ps)
{
	cout << "Nhap tu so: ";
	cin >> ps.tu;
	cout << "Nhap mau so: ";
	do {
		cin >> ps.mau;
		if (ps.mau == 0)
			cout << "Nhap sai. Nhap lai: ";
	} while (ps.mau == 0);
}

//tim uoc chung lon nhat
int UCLN(int a, int b) // a chia b
{
	int du;
	while (b != 0)
	{
		du = a % b;
		a = b;
		b = du;
	}
	return a;
}

//toi gian phan so
PhanSo toiGianPS(PhanSo ps)
{
	int a = UCLN(ps.tu, ps.mau);
	a = tri(a);
	ps.tu /= a;
	ps.mau /= a;
	return ps;
}

//co dinh dau cua phan so
PhanSo dauPS(PhanSo ps)
{
	if (ps.mau < 0)
	{
		ps.tu *= -1;
		ps.mau *= -1;
	}
	return ps;
}

//tinh tong phan so
PhanSo tongPS(PhanSo ps1, PhanSo ps2)
{
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}

//tinh hieu phan so
PhanSo hieuPS(PhanSo ps1, PhanSo ps2)
{
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau - ps1.mau * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}

//tinh tich phan so
PhanSo tichPS(PhanSo ps1, PhanSo ps2)
{
	PhanSo kq;
	kq.tu = ps1.tu * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}

//tinh thuong phan so
PhanSo thuongPS(PhanSo ps1, PhanSo ps2)
{
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau;
	kq.mau = ps1.mau * ps2.tu;
	return kq;
}

//xuat phan so
void xuatPS(PhanSo ps)
{
	ps = dauPS(ps);
	ps = toiGianPS(ps);
	cout << ps.tu << "/" << ps.mau << endl;
}

int main()
{
	//khai bao, khoi tao bien
	int chon0, chon1;
	bool checkPS1 = false, checkPS2 = false, checkKQ = false;

	//khai bao bien kieu struct
	PhanSo ps1, ps2, kq;

	//menu
	do {
		system("cls");
		cout << "MENU:\n"
			<< "1. Nhap phan so:\n"
			<< "2. Xuat phan so:\n"
			<< "3. Tinh tong 2 phan so\n"
			<< "4. Tinh hieu 2 phan so\n"
			<< "5. Tinh tich 2 phan so\n"
			<< "6. Tinh thuong 2 phan so\n"
			<< "7. Thoat chuong trinh\n"
			<< "BAN CHON: ";
		nhap(chon0, 0, 8);
		cout << "\n\n";

		switch (chon0)
		{
		case 1:
			cout << "NHAP PHAN SO:\n"
				<< "1. Phan so thu nhut\n"
				<< "2. Phan so thu hai\n"
				<< "BAN CHON: ";
			nhap(chon1, 0, 3);
			cout << "\n\n";
			switch (chon1)
			{
			case 1:
				cout << "PHAN SO THU NHUT:\n";
				nhapPS(ps1);
				checkPS1 = true;
				cout << "THONG BAO: NHAP PHAN SO THU NHUT THANH CONG !\n";
				break;
			case 2:
				cout << "PHAN SO THU HAI:\n";
				nhapPS(ps2);
				checkPS2 = true;
				cout << "THONG BAO: NHAP PHAN SO THU HAI THANH CONG !\n";
				break;
			}
			break;
		case 2:
			cout << "XUAT PHAN SO:\n"
				<< "1. Phan so thu nhut\n"
				<< "2. Phan so thu hai\n"
				<< "3. Phan so ket qua cua phep tinh vua thuc hien\n"
				<< "BAN CHON: ";
			nhap(chon1, 0, 4);
			cout << "\n\n";
			switch (chon1)
			{
			case 1:
				if (checkPS1)
				{
					cout << "PHAN SO THU NHUT:\n";
					xuatPS(ps1);
					cout << "THONG BAO: XUAT PHAN SO THU NHUT THANH CONG !\n";
				}
				else cout << "THONG BAO: BAN CHUA NHAP PHAN SO THU NHUT !\n";
				break;
			case 2:
				if (checkPS2)
				{
					cout << "PHAN SO THU HAI:\n";
					xuatPS(ps2);
					cout << "THONG BAO: XUAT PHAN SO THU HAI THANH CONG !\n";
				}
				else cout << "THONG BAO: BAN CHUA NHAP PHAN SO THU HAI !\n";
				break;
			case 3:
				if (checkKQ)
				{
					cout << "PHAN SO KET QUA:\n";
					xuatPS(kq);
					cout << "THONG BAO: XUAT PHAN SO KET QUA THANH CONG !\n";
				}
				else cout << "THONG BAO: BAN CHUA THUC HIEN PHEP TINH NAO !\n";
				break;
			}
			break;
		case 3:
			if (checkPS1 && checkPS2)
			{
				kq = tongPS(ps1, ps2);
				checkKQ = true;
				cout << "THONG BAO: TINH TONG THANH CONG !";
			}
			else cout << "THONG BAO: BAN CHUA NHAP DAY DU 2 PHAN SO !";
			break;
		case 4:
			if (checkPS1 && checkPS2)
			{
				kq = hieuPS(ps1, ps2);
				checkKQ = true;
				cout << "THONG BAO: TINH HIEU THANH CONG !";
			}
			else cout << "THONG BAO: BAN CHUA NHAP DAY DU 2 PHAN SO !";
			break;
		case 5:
			if (checkPS1 && checkPS2)
			{
				kq = tichPS(ps1, ps2);
				checkKQ = true;
				cout << "THONG BAO: TINH TICH THANH CONG !";
			}
			else cout << "THONG BAO: BAN CHUA NHAP DAY DU 2 PHAN SO !";
			break;
		case 6:
			if (checkPS1 && checkPS2)
			{
				kq = thuongPS(ps1, ps2);
				checkKQ = true;
				cout << "THONG BAO: TINH THUONG THANH CONG !";
			}
			else cout << "THONG BAO: BAN CHUA NHAP DAY DU 2 PHAN SO !";
			break;
		default:
			cout << "THONG BAO: THOAT CHUONG TRINH\n";
		}

		_getch();
	} while (chon0 >= 1 && chon0 <= 6);
	
	//tra ve gia tri
	return 0;
}