#include <iostream>
using namespace std;
void nhap(int& n, int x, int y)
{
	do {
		cin >> n;
		if (n < x || n > y)
			cout << "Gia tri nhap sai. Moi nhap lai:\t";
	} while (n < x || n > y);
}
double luyThua(int x, int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return (1.0 / x) * luyThua(x, n + 1);
	if (n > 0)
		return x * luyThua(x, n - 1);
}
int main()
{
	int x, n;
	cout << "Nhap co so:\t";
	nhap(x, INT_MIN, INT_MAX);
	cout << "Nhap luy thua:\t";
	nhap( n, INT_MIN, INT_MAX);
	cout << x << " ^ " << n << " =\t" << luyThua(x, n) << endl;
}