#include <iostream>
#include <string>
#define MAXS 45
#define ORG_YEAR 1990
#define CURRENT_YEAR 2022
using namespace std;

struct SinhVien
{
	string maSo;
	string hoTen;
	string diaChi;
	int namSinh;
	double diemToan, diemVan, diemNN;
};

//ham nhap gia tri nguyen
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		 if (n <= a || n >= b)
			 cout << "THONG BAO: NHAP SAI. NHAP LAI: ";
	} while (n <= a || n >= b);
}

//ham nhap gia tri thuc
void nhapD(double& n, double a, double b)
{
	do {
		cin >> n;
		 if (n <= a || n >= b)
			 cout << "THONG BAO: NHAP SAI. NHAP LAI: ";
	} while (n < a || n > b);
}

//ham nhap thong tin 1 sinh vien
void nhap1SV(SinhVien &sv)
{
	cout << "Nhap ma so sinh vien: ";
	cin >> sv.maSo;
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, sv.hoTen);
	cout << "Nhap dia chi thuong tru: ";
	getline(cin, sv.diaChi);
	cout << "Nhap nam sinh: ";
	nhap(sv.namSinh, ORG_YEAR, CURRENT_YEAR);
	cout << "Nhap diem toan: ";
	nhapD(sv.diemToan, 0, 10);
	cout << "Nhap diem van: ";
	nhapD(sv.diemVan, 0, 10);
	cout << "Nhap diem ngoai ngu: ";
	nhapD(sv.diemNN, 0, 10);
}

//ham nhap thong tin tat ca sinh vien
void nhapDSSV(SinhVien* sv, int n)
{
	cout << "NHAP SINH VIEN:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "SINH VIEN [" << i + 1 << "]\n";
		nhap1SV(sv[i]);
	}
}

//ham xuat thong tin cua 1 sinh vien
void xuat1SV(SinhVien sv)
{
	cout << "Ma so sinh vien: " << sv.maSo
		<< "\nHo ten sinh vien: " << sv.hoTen
		<< "\nDia chi thuong tru: " << sv.diaChi
		<< "\nNam sinh: " << sv.namSinh
		<< "\nDiem toan: " << sv.diemToan
		<< "\nDiem van: " << sv.diemVan
		<< "\nDiem ngoai ngu: " << sv.diemNN << endl;
}

//ham xuat thong tin tat ca sinh vien
void xuatDSSV(SinhVien* sv, int n)
{
	cout << "XUAT SINH VIEN:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "SINH VIEN [" << i + 1 << "]\n";
		xuat1SV(sv[i]);
	}
}

//ham tinh diem trung binh 1 sinh vien
double trungBinh1SV(SinhVien sv)
{
	double tb = (sv.diemToan + sv.diemVan) * 2 + 5 * sv.diemNN;
	return tb;
}

//ham tinh diem trung binh tat ca sinh vien
void trungBinhDSSV(SinhVien* sv, int n, double*& tb)
{
	for (int i = 0; i < n; i++)
	{
		tb[i] = trungBinh1SV(sv[i]);
		cout << "Ma so sinh vien: " << sv[i].maSo
				<< "\nHo ten sinh vien: " << sv[i].hoTen
				<< "\nDiem trung binh: " << tb[i] << endl;
	}
}

string xepLoai1SV(double tb)
{
	if (tb < 6.5)
	{
		if (tb < 5)
			return "Duoi TB";
		else
			return "TB";
	} 
	else 
		if (tb < 8)
			return "Kha";
		else return "Gioi";
}

//xep loai tat ca sinh vien
void xepLoaiDSSV()
{

}

int main()
{
	//khai bao ( & khoi tao) bien
	int size;

	//khai bao mang theo kieu du lieu SinhVien
	SinhVien sv[MAXS] = {0};

	//khai bao mang diemTB
	double diemTB[MAXS];

	//khai bao mang xep loai
	string xepLoai[MAXS];

	//nhap so luong sinh vien
	cout << "1 lop hoc co toi da 45 sinh vien. Lop hoc dang xet co bao nhieu sinh vien ?\t";
	nhap(size, 0, MAXS);

	//nhap thong tin sinh vien
	nhapDSSV(sv, size);

	//xuat thong tin sinh vien
	xuatDSSV(sv, size);



	//tra ve gia tri
	return 0;
}