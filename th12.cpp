#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    char masv[10];
    char hodem[30];
    char ten[30];
    char gioitinh[5];
    int namsinh;
    float diemtk;
};

struct Node {
    SinhVien infor;
    Node *next;
};

typedef Node* TRO;

void NhapSV(SinhVien &S) {
	cout << "Nhap ma sinh vien: "; 		fflush(stdin);gets(S.masv);
	cout << "Nhap ho dem: "; 			fflush(stdin);gets(S.hodem);
	cout << "Nhap ten: "; 				fflush(stdin);gets(S.ten);
	cout << "Nhap gioi tinh: "; 		fflush(stdin);gets(S.gioitinh);
	cout << "Nhap nam sinh: "; 			cin >> S.namsinh;
	cout << "Nhap diem tong ket: "; 	cin >> S.diemtk;
	cin.ignore();
}

void XuatSV(SinhVien S) {
    cout << S.masv << setw(15) << S.hodem << setw(10) << S.ten << setw(10) << S.gioitinh << setw(10) << S.namsinh << setw(8) << S.diemtk << endl;
}

void ThemVaoDau(TRO &L, SinhVien S) {
    TRO P = new Node;
    P->infor = S;
    P->next = L;
    L = P;
}

void Xuat(TRO L) {
    cout << "\nMa SV" << setw(15) << "Ho dem" << setw(10) << "Ten" << setw(10) << "Gioi tinh" << setw(10) << "Nam sinh" << setw(8) << "Diem TK" << endl;
    TRO Q = L;
    while (Q != NULL) {
        XuatSV(Q->infor);
        Q = Q->next;
    }
}

void xoaPtDauTien(TRO &L) {
    if (L == NULL) {
        cout << "Danh sach rong\n";
        return;
    }
    TRO Q = L;
    L = L->next;
    delete Q;
}

void chenVaoViTriThu3(TRO &L) {
    TRO M, Q = L;
    int dem = 1;
    while (Q != NULL && dem < 3) {
        M = Q;
        Q = Q->next;
        dem++;
    }
    if (dem < 3) {
        cout << "Vi tri khong thich hop\n";
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

void SapXep(TRO &L) {
    if (L == NULL) {
        cout << "Danh sach rong\n";
        return;
    }
    for (TRO R = L; R->next != NULL; R = R->next) {
        for (TRO Q = R->next; Q != NULL; Q = Q->next) {
            if (strcmp(R->infor.masv, Q->infor.masv) > 0) {
                SinhVien tg = R->infor;
                R->infor = Q->infor;
                Q->infor = tg;
            }
        }
    }
}

int main() {
    TRO L = NULL; 
    SinhVien S;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    cout << endl;
    for (int i = 1; i <= n; i++) {
        NhapSV(S);
        ThemVaoDau(L, S);
    }
    cout << "\n========DANH SACH SINH VIEN========" << endl;
    Xuat(L);
    xoaPtDauTien(L);
    cout << "\n========DANH SACH SINH VIEN SAU KHI XOA PHAN TU DAU TIEN========" << endl;
    Xuat(L);
    chenVaoViTriThu3(L);
    cout << "\n========DANH SACH SINH VIEN SAU KHI CHEN PHAN TU O VI TRI THU 3========" << endl;
    Xuat(L);
    SapXep(L);
    cout << "\n========DANH SACH SINH VIEN SAU KHI SAP XEP========" << endl;
    Xuat(L);
    return 0;
}
