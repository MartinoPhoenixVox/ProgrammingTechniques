#include <iostream>
using namespace std;

int main()
{
	int x, y;
	int* p;
	p = &x;
	*p = 80;
	cout << "Dia chi cua bien x: " << &x << endl;
	cout << "dia chi luu trong con tro p: " << p << endl;
	cout << "Gia tri cua bien ma p tro den: " << *p << endl;
	cout << "Gia tri cua x: " << x << endl;
	bool kq = *p == x;
	if(kq)
		cout << x << " la gia tri p sang luu tru\n";
	else cout << x << " khong la gia tri p sang luu tru\n";
	return 0;
}