#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int m;
	ifstream inF;
	inF.open("BTH6_BT01.txt");
	if (inF.is_open())
	{
		inF >> m;
		inF.close();
		cout << "THONG BAO: DOC FILE THANH CONG!\n";
		cout << "m = " << m << endl;
	} else cout << "THONHG BAO: MO FILE KHONG THANH CONG!\n";
}