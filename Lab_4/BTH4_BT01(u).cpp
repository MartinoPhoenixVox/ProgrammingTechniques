#include <iostream>
#include <conio.h>
using namespace std;

#define maxc 101

void nhap(int &n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "Nhap sai. Nhap lai:\t";
	} while (n <= a || n >= b);
	cout << endl;
}

//so sanh chuoi
int demChuoi(char *a)
{
	int demKyTu = 0;
	while (*(a + demKyTu) != '\n')
		demKyTu++;
	return demKyTu;
}
void soChuoi(char *a, char *b)
{
	if (demChuoi(a) < demChuoi(b))
		cout << "Chuoi 1 dai hon chuoi 2";
	else if (demChuoi(a) == demChuoi(b))
		cout << "Chuoi 1 bang chuoi 2";
	else cout << "Chuoi 1 nho hon chuoi 2";
}

int main()
{
	//khai bao va khoi tao
	bool check1 = false, check2 = false;
	int chon, chon1, chon2;
	char a[maxc];
	char b[maxc];

	//menu
	do {
		system("cls");
		cout << "Menu:\n"
			<< "1. Nhap chuoi\n"
			<< "2. Xuat chuoi\n"
			<< "3. So sanh chuoi\n"
			<< "4. Chuyen chuoi sang dang in hoa ky tu dau tien moi tu\n"
			<< "5. Noi chuoi\n"
			<< "6. Ket thuc\n"
			<< "Ban chon:\t";
		nhap(chon, -100, 100);

		switch (chon)
		{
		case 1:
			cout << "Hay chon:\n"
				<< "1. Chuoi 1\n"
				<< "2. Chuoi 2\n"
				<< "Ban chon:\t";
			nhap(chon1, 0, 3);
			switch (chon1)
			{
			case 1:
				cout << "Nhap duoi day:\n";
				cin.getline(a, maxc, '\n');
				check1 = true;
				break;
			case 2:
				cout << "Nhap duoi day:\n";
				cin.getline(b, maxc, '\n');
				check2 = true;
				break;
			}	
			break;

		case 2:
			cout << "Hay chon:\n"
				<< "1. Chuoi 1\n"
				<< "2. Chuoi 2\n"
				<< "Ban chon:\t";
			nhap(chon2, 0, 3);
			switch (chon2)
			{
			case 1:
				if (check1)
				{
					cout << "Nhap duoi day:\n";
					cout << a;
				}
				else cout << "Chua nhap chuoi. Yeu cau nhap\n";
				break;
			case 2:
				if (check2)
				{
					cout << "Nhap duoi day:\n";
					cout << b;
				}
				else cout << "Chua nhap chuoi. Yeu cau nhap\n";
				break;
			}
			break;

		case 3:
			if(check1 && check2)
			{
				soChuoi(a, b);
			}
			else cout << "Xin hay nhap day du cac chuoi";
			break;
			//Case 4 tro di chua lam

		case 4:
			if(check1 && check2)
			{
				
			}
			else cout << "Xin hay nhap day du cac chuoi";
			break;

		case 5:
			if(check1 && check2)
			{
				
			}
			else cout << "Xin hay nhap day du cac chuoi";
			break;

		default:
			cout << "Ban chon thoat. Dang thoat...\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 5);

	//tra ve
	return 0;
}