#include <iostream>
#include <fstream>
using namespace std;
const int minInt = -100, maxInt = 100;

void nhap(int &n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "THONG BAO: NHAP SAI. NHAP LAI: ";
	} while (n <= a || n >= b);
}

int main()
{
	//bien
	int a, b, kq;
	//nhap
	cout << "Nhap so nguyen thu nhut: ";
	nhap(a, minInt, maxInt);
	cout << "Nhap so nguyen thu hai: ";
	nhap(b, minInt, maxInt);
	//tinh tong
	kq = a + b;
	cout << "Tong cua 2 so nguyen: " << kq << endl;
	//dua kq vao tap tin BTH6_BT01.txt
	ofstream outF;
	outF.open("BTH6_BT01.txt");
		if (outF.is_open())
		{
			outF << kq;
			outF.close();
			cout << "THONG BAO: GHI FILE THANH CONG!\n";
		} else cout << "THONG BAO: KHONG THE MO FILE!\n";
}