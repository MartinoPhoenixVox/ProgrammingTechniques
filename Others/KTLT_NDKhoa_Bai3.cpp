#include <iostream>
using namespace std;
#define MAXSIZE 10

struct MonHoc {
	char MaMH[20]; //mã môn học
	char TenMH[50]; //tên môn học
	char Khoa[30]; //khoa chủ quản môn học
	int SoTC; //số tín chỉ môn học
};
int counter(MonHoc mh[]) {
	int n = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		if (mh[i].SoTC >= 3 && mh[i].SoTC <= 4) n++;
	}
	return n;
}
void CNTT(MonHoc mh[]) {
	int n = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		if (mh[i].Khoa[0] == 'C' && mh[i].Khoa[1] == 'N' && mh[i].Khoa[2] == 'T' && mh[i].Khoa[3] == 'T') {
			cout << n << "___" << mh[i].MaMH << "___" << mh[i].TenMH << "___" << mh[i].Khoa << "___" << mh[i].SoTC << endl;
			n++;
		}
	}
}

int main() {
	MonHoc mh[MAXSIZE];
	int n = 0;
	mh[0] = {"mh01152151", "Toan Cao Cap", "Khong co", 2};
	mh[1] = { "mh06145577", "Tin Hoc Dai Cuong", "Khong co", 3 };
	mh[2] = { "mh04153325", "Giao Duc The Chat", "Khong co", 4 };
	mh[3] = { "mh02103456", "CSDL", "CNTT", 2 };
	mh[4] = { "mh07153647", "Luat Kinh Te", "Tai chinh", 2 };
	mh[5] = { "mh02154475", "CTDL", "CNTT", 4 };
	mh[6] = { "mh01155478", "Triet Hoc Co Ban", "Khong co", 2 };
	mh[7] = { "mh03120471", "LT Windows", "CNTT", 3 };
	mh[8] = { "mh03145547", "UDW", "CNTT", 4 };
	mh[9] = { "mh04153588", "KTVM", "Tai chinh", 2 };
	cout << "Co " << counter(mh) << " mon hoc co tu 3 toi 4 tin chi!\n";
	CNTT(mh);
}