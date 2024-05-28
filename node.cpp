#include <bits/stdc++.h>

using namespace std;
struct SINHVIEN {
  char masv[10];
  char hodem[20];
  char ten[10];
  int nam_sinh;
  float diemtk;
};
struct Node {
  SINHVIEN infor;
  Node * next;
};
typedef Node * TRO;
void creat(TRO & L) {
  L = NULL;
}
int Empty(TRO L) {
  return L == NULL;
}
void NhapSV(SINHVIEN & sv) {
  cout << "\tNhap ma sinh vien: ";
  fflush(stdin);
  gets(sv.masv);
  if (strcmp(sv.masv, "***") == 0)
    return;
  cout << "\tHo dem: ";
  fflush(stdin);
  gets(sv.hodem);
  cout << "\t Ten: ";
  fflush(stdin);
  gets(sv.ten);
  cout << "\tNam Sinh: ";
  cin >> sv.nam_sinh;
  cout << "\tDiem: ";
  cin >> sv.diemtk;
}
void NhapDS(TRO & L) {
  creat(L);
  SINHVIEN X;
  TRO Q, P;
  int i = 1;
  do {
    cout << "Nhap sinh vien thu " << i << endl;
    NhapSV(X);
    if (strcmp(X.masv, "***") == 0)
      return;
    P = new(Node);
    P -> infor = X;
    P -> next = NULL;
    if (L == NULL)
      L = P;
    else Q -> next = P;
    Q = P;
    i++;
  } while (1);
}
void HienThiDs(TRO L) {
  if (L == NULL) {
    cout << "Danh sach rong\n";
    return;
  }
  cout << setw(5) << "STT";
  cout << setw(10) << "Ma SV";
  cout << setw(25) << "Ho va ten";
  cout << setw(10) << "Nam sinh";
  cout << setw(10) << "Diem TK" << endl;
  TRO Q = L;
  int i = 0;
  while (Q != NULL) {
    SINHVIEN X = Q -> infor;
    cout << setw(5) << i + 1;
    cout << setw(10) << X.masv;
    cout << setw(17) << X.hodem;
    cout << setw(8) << X.ten;
    cout << setw(10) << X.nam_sinh;
    cout << setw(10) << X.diemtk << endl;
    Q = Q -> next;
    i++;
  }
}
int Length(TRO L) {
  int n = 0;
  TRO Q = L;
  while (Q != NULL) {
    Q = Q -> next;
    n++;
  }
  return n;
}
void XoaSVDauTien(TRO & L) {
  if (L != NULL) {
    TRO Q = L;
    L = L -> next;
    delete Q;
    cout << "Danh sach sau khi xoa sinh vien dau tien\n";
    HienThiDs(L);
    return;
  }
  cout << "Danh sach rong, khong the xoa sinh vien dau tien\n";
}
TRO Search(TRO L,
  const char * ma) {
  TRO Q = L;
  while (Q != NULL && strcmp(Q -> infor.masv, ma) != 0) {
    Q = Q -> next;
  }
  return Q;
}

void Remove(TRO & L, TRO T) {
  TRO Q;
  if (T == L)
    L = T -> next;
  else {
    Q = L;
    while (Q -> next != T)
      Q = Q -> next;
    Q -> next = T -> next;
  }
  delete T;
}
void Xoa_sv8089(TRO & L) {
  TRO T = Search(L, "sv8089");
  if (T == NULL) {
    cout << "Khong co sinh vien co ma sinh vien sv8089 trong danh sach\n";
    return;
  } else {
    Remove(L, T);
    cout << "Danh sach sau khi xoa sv8089\n";
    HienThiDs(L);
  }
}
void FirstAdd(TRO & L, SINHVIEN X) {
  TRO P = new(Node);
  P -> infor = X;
  P -> next = L;
  L = P;
}
void Insert(TRO & L, TRO Q, SINHVIEN X) {
  TRO P = new(Node);
  P -> infor = X;
  P -> next = Q -> next;
  Q -> next = P;
}
void Bosung(TRO & L) {
  int k;
  SINHVIEN X;
  do {
    cout << "Nhap vi tri Bo sung";
    cin >> k;

  } while (k < 1 || k > Length(L));
  cout << "Nhap thong tin sinh vien can bo sung" << endl;
  do {
    NhapSV(X);
    if (strcmp(X.masv, "***") == 0)
      cout << "Ma sinh vien phai khac ***,vui long nhap lai" << endl;

  } while (strcmp(X.masv, "***") == 0);
  if (k == 1)
    FirstAdd(L, X);
  else {
    TRO Q = L;
    int d = 1;
    while (d < k - 1) {
      d++;
      Q = Q -> next;
    }
    Insert(L, Q, X);
  }
  cout << "Danh sach vua bo sung\n";
  HienThiDs(L);
}
void HienThiSVDoanh(TRO L) {
  if (L == NULL) {
    cout << "Danh sach rong\n";
    return;
  }
  cout << setw(5) << "STT";
  cout << setw(10) << "Ma SV";
  cout << setw(25) << "Ho va ten";
  cout << setw(10) << "Nam sinh";
  cout << setw(10) << "Diem TK" << endl;
  TRO Q = L;
  int i = 0;
  while (Q != NULL) {
    SINHVIEN X = Q -> infor;
    if (strcmp(X.ten, "Doanh") == 0) {
      cout << setw(5) << i + 1;
      cout << setw(10) << X.masv;
      cout << setw(17) << X.hodem;
      cout << setw(8) << X.ten;
      cout << setw(10) << X.nam_sinh;
      cout << setw(10) << X.diemtk << endl;
      i++;
    }
    Q = Q -> next;
  }
  if (i == 0)
    cout << "Trong danh sach 0 co ai ten Doanh";
}
void SapXepTheoDtk(TRO & L) {
  TRO P, Q, R;
  P = L;
  while (P -> next != NULL) {
    R = P;
    Q = P -> next;
    while (Q != NULL) {
      if (Q -> infor.diemtk > R -> infor.diemtk)
        R = Q;
      Q = Q -> next;
    }
    SINHVIEN tg = P -> infor;
    P -> infor = R -> infor;
    R -> infor = tg;
    P = P -> next;
  }
  cout << "Danh sach giam dan theo diemtk" << endl;
  HienThiDs(L);
}
void BoSungTheoTratTuDaSapXep(TRO & L) {
  SINHVIEN X;
  cout << "Nhap thong tin sinh vien can bo sung" << endl;
  do {
    NhapSV(X);
    if (strcmp(X.masv, "***") == 0)
      cout << "Ma sinh vien phai khac ***,vui long nhap lai" << endl;

  } while (strcmp(X.masv, "***") == 0);
  if (X.diemtk >= L -> infor.diemtk)
    FirstAdd(L, X);
  else {
    TRO Q = L;
    TRO T = Q -> next;
    while (T != NULL && T -> infor.diemtk > X.diemtk) {
      Q = Q -> next;
      T = T -> next;
    }
    Insert(L, Q, X);
  }
  cout << "Danhs ach sau khi bo sung" << endl;
  HienThiDs(L);
}
int main() {
  TRO L;
  cout << "Nhap danh sach sinh vien\n";
  NhapDS(L);
  cout << "Hien thi danh sach sinh vien\n";
  HienThiDs(L);
  cout << "So luong sinh vien trong danh sach: " << Length(L) << endl;
  XoaSVDauTien(L);
  Xoa_sv8089(L);
  Bosung(L);
  cout << "Danh sach sv ten Doanh\n";
  HienThiSVDoanh(L);
  SapXepTheoDtk(L);
  BoSungTheoTratTuDaSapXep(L);
  return 0;
}
