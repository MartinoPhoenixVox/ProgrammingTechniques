#include <iostream>
using namespace std;
#define MAXSIZE 101
void delChar(char a[], int &s, char c) {
	char* ptr;
	ptr = a;
	for (int i = 0; i <= s; i++) {
		if (*(ptr + i) == c) {
			int temp = i;
			while (temp <= s) {
				*(ptr + temp) = *(ptr + temp + 1);
				temp++;
			}
			s--;
		}
	}
}
int main() {
	char string[MAXSIZE] = "_Truong_Cao_Dang_Ly_Tu_Trong_Nam_2020"; // chuỗi có độ dài tối đa 100 ký tự
	char* ptr;
	ptr = string;
	int s = 0;
	while (true) {
		cout << *(ptr + s);
		s++;
		if (*(ptr + s) == '\0') {
			cout << endl;
			break;
		}
	}
	cout << "Chuoi co " << s << " ky tu!\n";
	delChar(string, s, '_'); // hàm xóa ký tự bất kỳ
	cout << "Chuoi sau khi xoa\"_\": ";
	for (int i = 0; i <= s; i++) {
		cout << *(ptr + i);
	}
	cout << endl;
}