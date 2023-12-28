#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAXSIZE 30
int main()
{
	int arr[MAXSIZE];
	int n;
	cout << "Nhap so luong phan tu:\t";
	do {
		cin >> n;
		if (n < 1 || n > MAXSIZE)
			cout << "Nhap lai:\t";
	} while (n < 1 || n > MAXSIZE);
	cout << endl;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
	int* p = arr;
	cout << "Dung ky phap do doi de xuat mang:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << *(p + i) << "\t";
	}
	cout << endl;
	cout << "Dung ky phap chi so de xuat mang:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << p[i] << "\t";
	}
	cout << endl;
	return 0;
}