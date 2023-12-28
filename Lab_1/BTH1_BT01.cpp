#include <iostream>
using namespace std;
const int r = 3, c = 4;
int main()
{
	int a[r][c] = { {8, 4, -1, 5}, {2, 2, 6, 9}, {11, 2, 5, 4} };
	cout << "Mang dang luu tru:\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
	return 0;
}