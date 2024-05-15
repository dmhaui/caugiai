#include<bits/stdc++.h>
using namespace std;

#define MAX 82
struct Student{
    string StudentIdentify;
    string buffername;
    string name;
    string sex;
    int year;
    float gpa;
};

void inputStudent(Student &s){
    cout << "Enter Student Identify: ";
    cin >> s.StudentIdentify;
    cout << "Enter buffer: ";
    cin >> s.buffername;
    cout << "Enter name Student: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter sex: ";
    cin >> s.sex;
    cout << "Enter year: ";
    cin >> s.year;
    cout << "Enter gpa: ";
    cin >> s.gpa;
}

void PrintStudent(Student s){
    cout << s.StudentIdentify << " " << s.buffername << " " << s.name << " " << s.sex << " " << s.year << " " << s.gpa << "\n";
}

struct Vector{
    int count;
    Student e[MAX];
};

bool full(Vector &v){
    return v.count == MAX;
}

void delete_first_element(Vector &v){
    if (v.count <= 0){
        cout << "\nList empty...!";
        return;
    }
    for(int i = 1; i < v.count; i++){
        v.e[i - 1] = v.e[i];
    }
    v.count--;
}

int insert(Vector &v, int k, Student X){
    if (k <= v.count + 1 && k > 0  && !full(v)){
        for (int i = v.count; i >= k - 1; i--){
            v.e[i + 1] = v.e[i];
        }
        v.e[k - 1] = X;
        v.count ++;
        return 1;
    }
    else return 0;
}

void insert_in_3_location(Vector &v){
    Student s;
    s.StudentIdentify = "SV1006";
    s.buffername = "Le Thi";
    s.name = "Doan";
    s.sex = "Nu";
    s.year = 1998;
    s.gpa = 7.6;
    if (insert(v, 3, s)){
        cout<<"\nInsert successfully...!";
        cout<<"\nList after insert\n";
        for(int i = 0; i < v.count; i++){
            PrintStudent(v.e[i]);
        }
    }
    else{
        cout<<"Insert defeat..!";
    }
}

void sort_along_name(Vector &v){
    int i, j, m;
    Student tg;
    for (int i = 0; i < v.count; i++){
        m = i;
        for(int j = i + 1; j < v.count; j++){
            if (v.e[j].name.compare(v.e[m].name) < 0){
                m = j;
            }
        }
        tg = v.e[i];
        v.e[i] = v.e[m];
        v.e[m] = tg;
    }
}

int main(){
    Vector v;
    v.count = 5;
    for(int i = 0; i < v.count; i++){
        inputStudent(v.e[i]);
    }
    cout << "-----------------------------------------------------" << "\n";
    for (int i = 0; i < v.count; i++){
        PrintStudent(v.e[i]);
    }
    delete_first_element(v);
    cout << "-----------------------------------------------------" << "\n";
    for (int i = 0; i < v.count; i++){
        PrintStudent(v.e[i]);
    }
    cout << "-----------------------------------------------------" << "\n";
    insert_in_3_location(v);
    for (int i = 0; i < v.count; i++){
        PrintStudent(v.e[i]);
    }
    cout << "-----------------------------------------------------" << "\n";
    sort_along_name(v);
    for (int i = 0; i < v.count; i++){
        PrintStudent(v.e[i]);
    }
    cout << "-----------------------------------------------------" << "\n";
}
