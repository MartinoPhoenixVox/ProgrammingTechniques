#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

//kieu du lieu phong ban
struct PhongBan
{
	string maPhong;
	string tenPhong;
};

int main()
{
	//nhap du lieu phong ban
	PhongBan pb;
	cout << "HAY NHAP MA PHONG BAN:\t";
	getline(cin, pb.maPhong);
	cout << "HAY NHAP TEN PHONG BAN:\t";
	getline(cin, pb.tenPhong);
	cout << endl;

	//xuat du lieu phong ban
	cout << "MA PHONG BAN\t" << pb.maPhong << "\n"
		<< "TEN PHONG BAN:\t" << pb.tenPhong << endl;

	//tra ve gia tri
	_getch();
	return 0;
}