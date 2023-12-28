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
int demCS(int n, int i)
{
	if (n == 0)
		return i;
	i++;
	return demCS(n / 10, i);
}
int main()
{
	int n, i = 0;
	cout << "Nhap 1 so nguyen khong am n:\t";
	nhap(n, 0, INT_MAX);
	cout << n << " co " << demCS(n, i) << " chu so\n";
	return 0;
}
