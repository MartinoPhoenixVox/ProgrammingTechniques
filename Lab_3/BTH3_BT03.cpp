#include <iostream>
using namespace std;

int main()
{
	int* p1;
	int* p2;
	int d, m, n;
	cout << "Nhap lan luot 2 so nguyen:\t";
	do {
		cin >> m >> n;
		if (m < INT_MIN || m > INT_MAX || n < INT_MIN || n > INT_MAX)
			cout << "Nhap sai. Nhap lai\t";
	} while (m < INT_MIN || m > INT_MAX || n < INT_MIN || n > INT_MAX);
	p1 = new int;
	*p1 = m;
	p2 = new int;
	*p2 = n;
	while (*p2 != 0)
	{
		d = *p1 % *p2;
		*p1 = *p2;
		*p2 = d;
	}
	cout << "Uoc chung lon nhat cua 2 so nguyen da nhap:\t" << *p1 << endl;
	delete p1;
	delete p2;
	return 0;
}