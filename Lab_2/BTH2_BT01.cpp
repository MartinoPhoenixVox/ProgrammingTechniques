#include <iostream>
#include <conio.h>
using namespace std;
void cls()
{
	_getch();
	system("cls");
}
void nhap(int& n, int x, int y)
{
	do {
		cin >> n;
		if (n < x || n > y)
			cout << "Gia tri nhap sai. Moi nhap lai:\t";
	} while (n < x || n > y);
}
int S1(int n)
{
	if (n == 1)
		return 1;
	return n + S1(n - 1);
}
int S2(int n)
{
	if (n == 1)
		return 1;
	return n * n + S2(n- 1);
}
double S3(int n)
{
	if (n == 1)
		return 1;
	return 1.0 / n + S3(n - 2);
}
int giaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}
int S4(int n)
{
	if (n == 1)
		return 1;
	return giaiThua(n) + S4(n - 1);
}
int main()
{
	int n, chon, exit = 1;
	do {
		cout << "Menu:\n"
			<< "1. Tinh tong cac so hang lien tiep\n"
			<< "2. Tinh tong binh phuong cac so hang lien tiep\n"
			<< "3. Tinh tong cac phan so co mau la 1 va tu la cac so hang lien tiep\n"
			<< "4. Tinh tong cac giai thua lien tiep\n"
			<< "Ban chon:\t";
		nhap(chon, INT_MIN, INT_MAX);
		switch(chon)
		{
		case 1:
			cls();
			cout << "Nhap n:\t";
			nhap(n, 1, INT_MAX);
			cout << "S1 =\t" << S1(n) << endl;
			break;
		case 2:
			cls();
			cout << "Nhap n:\t";
			nhap(n, 1, INT_MAX);
			cout << "S2 =\t" << S2(n) << endl;
			break;
		case 3:
			cls();
			cout << "Nhap n:\t";
			do {
				nhap(n, 1, INT_MAX);
				if (n % 2 == 0)
					cout << "n phai la so le. Nhap lai:\t";
			} while (n % 2 == 0);
			cout << "S3 =\t" << S3(n) << endl;
			break;
		case 4:
			cls();
			cout << "Nhap n:\t";
			nhap(n, 1, INT_MAX);
			cout << "S4 =\t" << S4(n) << endl;
			break;
		default:
			cls();
			cout << "Ban muon thoat\n"
				<< "Dung thi chon 1. Nguoc lai chon 0\n"
				<< "Ban chon:\t";
			nhap(exit, 0, 1);
			if (exit == 0)
			{
				cout << "Ban chon tiep tuc\n";
				chon = INT_MIN;
				break;
			}
			cout << "Ban chon thoat. Tam biet!" << endl;
			chon = -1;
		}
		cls();
	} while (chon == INT_MIN || chon > 0 && chon < 5);
	return 0;
}