#include<bits/stdc++.h>

using namespace std;

struct SinhVien{
	char masv[10];
	char hodem[30];
	char ten[10];
	char gioitinh[5];
	int namsinh;
	float diemtk;
};

struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *TRO;

void NhapSinhVien(SinhVien &S){
	cout<<"Nhap ma sinh vien: ";			fflush(stdin);gets(S.masv);
	cout<<"Nhap ho dem: ";					fflush(stdin);gets(S.hodem);
	cout<<"Nhap ten: ";						fflush(stdin);gets(S.ten);
	cout<<"Nhap gioi tinh: ";				fflush(stdin);gets(S.gioitinh);
	cout<<"Nhap nam sinh: ";				cin>>S.namsinh;
	cout<<"Nhap diem tong ket: ";			cin>>S.diemtk;
}

void XuatSinhVien(SinhVien S){
	cout<<S.masv<<setw(8)<<S.hodem<<setw(10)<<S.ten<<setw(8)<<S.gioitinh<<setw(8)<<S.namsinh<<setw(8)<<S.diemtk<<endl;
}



void xoaptdautien(TRO &L){
	if (L == NULL){
		cout<<"Danh sach rong";
		return;
	}
	TRO Q = L;
	L = L->next;
	delete Q;
}

void chenvitrithu3(TRO &L){
	int d = 1;
	TRO M, Q = L;
	while (Q != NULL && d < 3){
		M = Q;
		Q = Q->next;
		d++;
	}
	if (Q == NULL){
		cout<<"Vi tri khong thich hop";
		return;
	}
	TRO P = new Node;
	strcpy(P->infor.masv, "1006");
	strcpy(P->infor.hodem, "Le Thi");
	strcpy(P->infor.ten, "Doan");
	strcpy(P->infor.gioitinh, "Nu");
	P->infor.namsinh = 1998;
	P->infor.diemtk = 7.6;
	P->next = M->next;
	M->next = P;
}

void sapxep(TRO &L){
	SinhVien tg;
	TRO M, Q, R;
	R = L;
	while (R->next != NULL){
		M = R;
		Q = R->next;
		while(Q != NULL){
			if(strcmp(Q->infor.ten, M->infor.ten)<0){
				M = Q;
			}
			Q = Q->next;
		}
		tg = R->infor;
		R->infor = M->infor;
		M->infor = tg;
		R = R->next;
	}
}

int main(){
	TRO L = NULL; 
    SinhVien sv;
    int n;
    int sv = new int[n]; 
    cout<<"Nhap so luong sinh vien: ";			cin>>n;
	for(int i=0;i<n;i++){
		NhapSinhVien(sv);
	}
    L = new Node;
    L->infor = sv;
    L->next = NULL;
	cout<<"========DANH SACH SINH VIEN========"<<endl;
	for(int i=0;i<n;i++){
		XuatSinhVien(L->infor);
	}
	cout<<"========DANH SACH SINH VIEN SAU KHI XOA=========="<<endl;
	xoaptdautien(L);
	for(int i=0;i<n;i++){
		XuatSinhVien(L->infor);
	}
	cout<<"========DANH SACH SINH VIEN SAU KHI CHEN========="<<endl;
	chenvitrithu3(L);
	for(int i=0;i<n;i++){
		XuatSinhVien(L->infor);
	}
	cout<<"========DANH SACH SINH VIEN SAU KHI SAP XEP========"<<endl;
	sapxep(L);
	for(int i=0;i<n;i++){
		XuatSinhVien(L->infor);
	}
	return 0;
}