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
int fibo(int n)
{
	if (n == 1 || n == 0)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}
int main()
{
	int n;
	cout << "Nhap 1 so nguyen khong am:\t";
	nhap(n, 0, INT_MAX);
	cout << "Gia tri Fibonacci cua " << n << " la " << fibo(n) << endl;
	return 0;
}