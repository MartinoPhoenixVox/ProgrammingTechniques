#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100
void initRand(int a[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
	}
}
void outArr(const int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0) cout << endl;
		cout << a[i] << " ";
	}
	cout << endl;
}
void outOddTail(int a[], int n) {
	int s = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] % 2 != 0) {
			if (s % 10 == 0) cout << endl;
			cout << a[i] << " ";
			s++;
		}
	}
	cout << endl;
}
int TongPTLonHonX(int a[], int n, int x) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) tong++;
	}
	return tong;
}
int locateMinArr(int a[], int n) {
	int min = a[0], loc = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < min) {
			min = a[i];
			loc = i;
		}
	return loc;
}

int main() {
	int arr[MAXSIZE];
	int n, x;
	cout << "Mang co bao nhieu gia tri (nho hon 100)? ";
	cin >> n;
	initRand(arr, n); //hàm khởi tạo ngẫu nhiên mảng số nguyên dương nhỏ hơn 10
	cout << "Mang duoc khoi tao: ";
	outArr(arr, n); //hàm xuất mảng
	cout << "Cac phan tu le tu cuoi mang sang dau mang: ";
	outOddTail(arr, n); //hàm xuất giá trị của chỉ số lẻ từ cuối mảng lên đầu mảng
	cout << "Nhap x: ";
	cin >> x;
	cout << "Tong cac phan tu co gia tri lon hon \"" << x << "\" bang " << TongPTLonHonX(arr, n, x) << endl;
	cout << "Gia tri nho nhat mang o vi tri thu: " << locateMinArr(arr, n) << endl; //hàm tìm phần tử có giá trị nhỏ nhất đầu tiên có trong mảng
}