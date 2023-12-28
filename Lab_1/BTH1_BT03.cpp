#include <iostream>
using namespace std;
const int maxr = 10, maxc = 15;
int main()
{
	int r, c, tong = 0;
	int max, min, minC, minR, maxC, maxR;
	int a[maxr][maxc];
	//Nhap mang
	do {
		cout << "Bao nhieu hang?\t";
		cin >> r;
		if (r < 0 || r > maxr)
			cout << "Nhap sai. Nhap lai.\n";
	} while (r < 0 || r > maxr);
	do {
		cout << "Bao nhieu cot?\t";
		cin >> c;
		if (c < 0 || c > maxc)
			cout << "Nhap sai. Nhap lai.\n";
	} while (c < 0 || c > maxc);
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap " << c << " gia tri vao dong thu " << i + 1 << ":\t";
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
		cout << endl;
	}
	//Tinh tong
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tong += a[i][j];
	//Xuat tong
	cout << "Tong tat ca gia tri trong mang =\t" << tong << endl;
	//Max, min
	max = min = a[0][0];
	minC = minR = maxC = maxR = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				maxR = i;
				maxC = j;
			}
			if (min > a[i][j])
			{
				min = a[i][j];
				minR = i;
				minC = j;
			}
		}
	cout << "Max = " << max << " tai hang " << maxR + 1 << " cot " << maxC + 1 << endl
		<< "Min = " << min << " tai hang " << minR + 1 << " cot " << minC + 1<< endl;
	return 0;
}