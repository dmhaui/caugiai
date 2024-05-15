#include<iostream>
#include<iomanip>
using namespace std;

struct MH{
	string mahang;
 	string tenhang;
 	int soluong;
};

struct Node{
	MH infor;
	Node *next;
};

typedef Node *tro;

void nhapMH(MH &mh){
 	cout<<"Nhap ma hang: ";			fflush(stdin);					getline(cin, mh.mahang);
 	cout<<"Nhap ten hang: "; 		fflush(stdin);					getline(cin, mh.tenhang);
 	cout<<"Nhap so luong: ";										cin>>mh.soluong;
}

void add(tro &L, MH mh){
	tro Q = L;
	tro P = new Node;
	P->infor = mh;
	P->next = NULL;
	if(L == NULL){
		L = P;
 }else{
  while(Q->next !=NULL){
  	Q = Q->next;
  }
  Q->next = P;
 }
}

void display(MH mh){
	cout<<setw(20)<<mh.mahang;
	cout<<setw(20)<<mh.tenhang;
	cout<<setw(20)<<mh.soluong<<endl;
}

void displayList(tro L){
	tro Q = L;
	int i = 1;
	cout<<"STT";
	cout<<setw(20)<<"Ma hang";
	cout<<setw(20)<<"Ten hang";
	cout<<setw(20)<<"So luong"<<endl;
 while(Q!=NULL){
	cout<<i;
	display(Q->infor);
	i++;
	Q = Q->next;
 }
}

int cnt10(tro L){
 int cnt = 0;
 tro Q = L;
 while(Q!=NULL && Q->infor.soluong >10){
  cnt++;
  Q = Q->next;
 }
 return cnt;
}
void display10(tro L){
 if(cnt10(L) == 0) {
  cout<<"Khong co mat hang nao co so luong lon hon 10 !!"<<endl;
 }
 else{
  tro Q = L;
  int i = 1;
  cout<<"STT";
  cout<<setw(20)<<"Ma hang";
  cout<<setw(20)<<"Ten hang";
  cout<<setw(20)<<"So luong"<<endl;
  while(Q!=NULL){
   if(Q->infor.soluong>10){
    cout<<i;
    display(Q->infor);
    i++; 
   }
   Q = Q->next;
  }
 }
}

int timMax(tro L){
 tro Q = L;
 int max = L->infor.soluong;
 while(Q!=NULL){
  if(max<Q->infor.soluong){
   max = Q->infor.soluong;
  }
  Q = Q->next;
 }
 return max;
}

void xoaMax(tro &L){
 tro Q = L;
 tro M;
 while(Q!=NULL && Q->infor.soluong != timMax(L)){
  M = Q;
  Q = Q->next;
 }
 if(Q == L){
  L = Q->next;
  delete Q;
 }
 else{
  M->next = Q->next;
  delete Q;
 }
}

void chen(tro &L, MH mh){
 tro Q = L;
 tro M;
 tro P = new Node;
 P->infor = mh;
 int index = 4;
 while(Q!=NULL && index != 1){
  M = Q;
  Q = Q->next;
  index-=1;
 }
 P->next = M->next;
 M->next = P;
}

void selectionSort(tro &L){
 tro Q = L;
 tro P,M;
 while(Q!=NULL){
  M = Q;
  P = Q->next;
  while(P!=NULL){
   if(M->infor.soluong < P->infor.soluong){
    M = P;
   }
   P = P->next;
  }
  MH temp = Q->infor;
  Q->infor = M->infor;
  M->infor = temp;
  Q = Q->next;
 }
}
int main(){
 tro L = NULL;
 int n;
 cout<<"Moi nhap so mat hang(so mat hang>3): ";
 cin>>n;
 while(n<3){
  cout<<"Nhap lai(so mat hang>3): ";
  cin>>n;
 }
 cout<<endl;
 MH mh;
 for(int i = 0;i<n;i++){
  cout<<"Moi nhap mat hang thu "<<i+1<<endl;
  nhapMH(mh);
  add(L, mh);
  cout<<endl;
 }
 cout<<"\nDanh sach sau khi tao"<<endl;
 displayList(L);
 cout<<"\nCac mat hang co so luong lon hon 10: "<<endl;
 display10(L);
 cout<<"\nXoa mat hang co so luong lon nhat: "<<endl;
 xoaMax(L);
 displayList(L);
 cout<<"\nNhap mat hang can chen vao truoc mat hang";
 
}