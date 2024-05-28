#include<bits/stdc++.h>
#define max 100

using namespace std;

struct sinhVien {
	char masinhVien[10];
	char hoDem[22];
	char ten[10];
	int namSinh;
	float diemTK;
};
struct List {
	int cnt;
	sinhVien E[max];
};
//Khoi tao danh sach rong
void dsRong(List &L) {
	L.cnt = -1;
}

//kiem tra ds day
int Full(List L) {
	return L.cnt == max - 1;
}

//Kiem tra ds rong
int Empty(List L) {
	return L.cnt == -1;
}

//Them sv vao cuoi ds
int Add(List &L, sinhVien X) {
	if(Full(L))
		return 0;
	else {
		L.cnt++;
		L.E[L.cnt] = X;
		return 1;
	}
}

//Nhap thong tin 1 sv
void nhapsv(sinhVien &sv) {
	cout << "Nhap ma sv: "; fflush(stdin); gets(sv.masinhVien);
	if(strcmp(sv.masinhVien, "***") == 0)
		return ;
		cout << "Ho dem: "; fflush(stdin); gets(sv.hoDem);
		cout << "Ten: "; fflush(stdin); gets(sv.ten);
		cout << "Nam sinh: "; cin >> sv.namSinh;
		cout << "Diem tong ket: "; cin >> sv.diemTK;
}
void nhapDS(List &L) {
	dsRong(L);
	sinhVien X;
	int i = 1;
	do {
		cout << "Nhap sinh vien thu " << i << endl;
		nhapsv(X);
		if(strcmp(X.masinhVien, "***") == 0) return;
		if(!Add(L, X)) return;
		i++;
	} while(1);
}

//Hien thi ds
void hienThiDS(List L) {
	cout << setw(5) << "STT";
	cout << setw(10) << "Ma sinhVien";
	cout << setw(25) << "Ho va ten";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Diem TK" << endl;
	for(int i = 0; i <= L.cnt; i++) {
		cout << setw(5) << (1 + i);
		cout << setw(10) << L.E[i].masinhVien;
		cout << setw(17) << L.E[i].hoDem;
		cout << setw(8) << L.E[i].ten;
		cout << setw(10) << L.E[i].namSinh;
		cout << setw(10) << L.E[i].diemTK << endl;
	}
}

//xoa sv dau tien trong ds
int del_first(List &L) {
	if(Empty(L)) return 0;
	for(int i = 1; i <= L.cnt; i++)
		L.E[i-1] = L.E[i];
	L.cnt--;
}

//xoa sv ma "sv8089"
int Search(List L, char *ma) {
	int i = 0;
	while(i <= L.cnt && strcmp(L.E[i].masinhVien, ma) != 0)
		i++;
	if(i <= L.cnt) return i + 1;
	else return 0;
}
void Searchh(List L, char *ma) {
	int i = 0;
	while(i <= L.cnt && strcmp(L.E[i].masinhVien, ma) != 0)
		i++;
	if(i <= L.cnt) cout<<"\nvi tri 8089"<<i+1;
	else cout<<"\nvi tri 8089"<<0;
}
void remove(int k, List &L) {
	for(int i = k -1; i < L.cnt; i++)
		L.E[i] = L.E[i + 1];
	L.cnt--;
}
int xoa_sv8089(List &L) {
	int k = Search(L, "sv8089");
	if(k == 0) return 0;
	remove(k, L);
	return 1;
}

//Them 1 sv vao vi tri k trong danh sach
int insert(int k, List &L) {
	int i;
	sinhVien X;
	if(!Full(L) && k <= L.cnt + 1 && k >= 1) {
		cout << "\nNhap sinh vien can bo sung\n";
		nhapsv(X);
		for(i = L.cnt; i >= k-1; i--)
			L.E[i+1] = L.E[i];
		L.cnt = L.cnt + 1;
		L.E[k - 1] = X;
		return 1;
	}
	else return 0;
}

//Liet ke nhung sinh vien co ten 'Doanh'
void Lietke(List L) {
	int i = 0, d = 0;
	cout << setw(5) << "STT";
	cout << setw(10) << "Ma sinhVien";
	cout << setw(25) << "Ho va ten";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Diem TK" << endl;
	while (i <= L.cnt) {
		if(strcmp(L.E[i].ten, "Doanh") == 0) {
			cout << setw(5) << (1 + i);
		cout << setw(10) << L.E[i].masinhVien;
		cout << setw(17) << L.E[i].hoDem;
		cout << setw(8) << L.E[i].ten;
		cout << setw(10) << L.E[i].namSinh;
		cout << setw(10) << L.E[i].diemTK << endl;
		d++;
		}
		i++;
	}
	if(d == 0)
cout << "Khong co sinh vien ten Doanh" << endl;
}

//sap xep danh sach
void sort(List &L) {
	for(int i = 1; i <= L.cnt; i++)
	for(int j = 0; j <= L.cnt - i; j++)
		if(L.E[j].diemTK < L.E[j + 1].diemTK) {
			sinhVien tg = L.E[j];
			   L.E[j] = L.E[j + 1];
			   L.E[j + 1] = tg;
		}
}
int sortInsert(List &L) {
	sinhVien X;
	if(Full(L)) return 0;
	nhapsv(X);
	int i = L.cnt;
	while(i >= 0 && L.E[i].diemTK < X.diemTK) {
		L.E[i + 1] = L.E[i];
		i--;
	}
	L.E[i + 1] = X;
	L.cnt++;
	return 1;
}
int main() {
	List L;
	nhapDS(L);
	cout << "Danh sach vua nhap:\n";
	hienThiDS(L);
	cout << "Danh sach vua xoa sinh vien dau tien: \n";
	del_first(L);
	hienThiDS(L);
	Searchh(L,"sv8089");

	if(xoa_sv8089(L) == 1) {
		cout << "Danh sach sau khi xoa sv8089\n";
		hienThiDS(L);
	}else cout << "Khong co sinh vien nao co ma sv8089" << endl;
Searchh(L,"sv8089");
	int k;
	cout << "Nhap vi tri bo sung: "; cin >> k;
	if(insert(k, L) == 1) {
		cout << "\nDanh sach sv vua bo sung\n";
		hienThiDS(L);
	} else
		cout << "Vi tri khong thich hop\n";
	sort(L);
	cout << "Danh sach duoc sap xep\n";
	hienThiDS(L);
	if(sortInsert(L) == 0)
		cout << "Danh sach day\n";
	else {
		cout << "Danh sach bo sung sau sap xep\n";
		hienThiDS(L);
	}
	return 0;
}
