#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outF;
	ifstream inF;
	int x, y, z;
	int a, b, c;
	double tbc;
	cout << "Nhap lan luot 3 so nguyen: ";
	cin >> x >> y >> z;
	//ghi vao file
	outF.open("BTH6_BT03.txt");
	if (outF.is_open())
	{
		outF << x << "#" << y << "#" << z;
		outF.close();
		cout << "THONG BAO: GHI VAO FILE THANH CONG!\n";
	} else cout << "THONG BAO: KHONG THE MO FILE!\n";
	//doc tu file
	inF.open("BTH6_BT03.txt");
	if (inF.is_open())
	{
		inF >> a;
		inF.ignore();
		inF >> b;
		inF.ignore();
		inF >> c;
		inF.ignore();
		inF.close();
		cout << "THONG BAO: DOC TU FILE THANH CONG!\n";
	} else cout << "THONG BAO: KHONG THE MO FILE!\n";
	tbc = (a + b + c) * 1.0 / 3;
	cout << "Trung binh cong cua 3 so vua duoc doc = " << tbc << endl;
}
