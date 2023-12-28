#include <iostream>
using namespace std;
#define MAXSIZE 30

int main()
{
	int n;
	int max = INT_MIN, maxAdd = 0;
	bool c = false;
	int* p;
	cout << "Ban muon nhap may gia tri?\t";
	do {
		cin >> n;
		if (n < 1 || n > MAXSIZE)
			cout << "Nhap sai. Nhap lai:\t";
	} while (n < 1 || n > MAXSIZE);
	cout << endl;
	p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] =\t";
		cin >> *(p + i);
		cout << endl;
	}
	//Xuat so le
	cout << "Cac phan tu la so le trong mang:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		if (p[i] % 2 != 0)
		{
			cout << *(p + i) << "\t";
			c = true;
		}
	}
	cout << endl;
	if (!c)
		cout << "Mang khong co phan tu le trong mang!\n";
	//Dia chi gia tri lon nhat
	for (int i = 0; i < n; i++)
		if (p[i] > max)
		{
			max = p[i];
			maxAdd = i;
		}
	cout << endl << "Gia tri lon nhat la " << max << " o vi tri " << maxAdd << endl;
	delete []p;
	p = NULL;
	return 0;
}