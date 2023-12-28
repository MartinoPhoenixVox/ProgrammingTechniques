#include <iostream>
using namespace std;
const int r = 4, c = 3;
int main()
{
	int a[r][c];
	int i = 0, j;
	while (i < r)
	{
		cout << "Nhap " << c << " gia tri cho dong thu " << i + 1 << ":\t";
		j = 0;
		while (j < c)
		{
			cin >> a[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	cout << "Mang dang luu tru:\n";
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			cout << a[i][j] << "\t";
			j++;
		}
		cout << endl;
		i++;
	}
	return 0;
}