#include <iostream> //����������� ������������� ����� iostream
#include <string> //����������� ���������� ��� ������� �� ��������
#include <fstream> //����������� ���������� ��� ������ � �������
#include "IT.h"  // ����������� ������������� ����� ��� ������ � ������� IT
using namespace std; // ���������� ������������ ���� std
void Read(string path, IT*); // �������� ������� Read
const bool operator>(const IT&, const IT&); // �������� ������������ ��������� >
const bool operator<(const IT&, const IT&); // �������� ������������ ��������� <
const bool operator>=(const IT&, const IT&);
const bool operator<=(const IT&, const IT&);
void bubble(IT* a, const int n); //�������� ������� ���������� ���������
void insert_sort(IT* a, const int n); //�������� ������� ���������� ��������� 
IT* take(const IT a[], int&amount); // �������� ������� �������� ������������� ����� �������� 
int main() {
    IT A[6000],*b; //��������� ������ ������ ������ IT � ��������� �� ������ ������� ������
    int n; // n - ���������� ������ ������� ������������ b ����� �������� A
    double s, e; //  ������� ��� ��������� �������� ������ ���������� (s - ������ ����������, e - �����)
    Read("Dataset.txt", A); //��������� ������ A ���������� �� ����� 'Dataset.txt'
   
    b = take(A, n); // ������� ������ ������������ b � ������� ������� take
    s = clock(); // �������� ������ ���������� 
    bubble(b, n); // ��������� ������ b � ������� ���������� ���������
    e = clock(); // ����� ���������� 
    cout << "Time for buble sort:" << (e - s) / (double)CLOCKS_PER_SEC << endl; // ��� ��� clock() ���������� ���������� '������'
    //�� ���������� ������������� ��� � ��������� ������� - ������� c ������� ������� CLOCKS_PER_SEC, �������  �������� ������� ����� 
    //��������� �� �������
    delete[]b;// ������������ ������ ������� �������� b 
    b = take(A, n); // ������� ������ ������������ b � ������� ������� take 
    s = clock();
    insert_sort(b, n); //��������� ������ b � ������� ���������� ��������� 
    e = clock();
    cout << "Time for insert sort:" << (e - s) / (double)CLOCKS_PER_SEC << endl;
    delete[]b;// ������������ ������ ������� �������� b 
    


}
IT* take(const IT a[], int&amount) { // ������� �������� ������������ �� ��������� ����� ��������
    //param:  
    // const IT a[] - ������ ��������� ����� ��������
    // int& amount  - ���������� ������ � ������������
    int first; // �����  �����, ����������� ��� ������� �� ��������� a �  ��� ����������� �������� 
    // ����������� b � ���������� ����������� ������
    cout << "Enter the amount of data in the new dataset: ";
    cin >> amount;
    while (amount > 6000) { // ���� �������� ���������� ������ ������ ��� ���������� ������ ����� ��������, �� ������ ������������ ������ ����� ��� ��� 
        cout << "Your number is exceed total number of data(6000), Please, enter the number again: ";
        cin >> amount;
    }
    while (amount < 0) { //���� ��������� ���������� ������ ������ ��� 0 - ������ ������ ������
        cout << "Please, enter the number that more than 0: ";
        cin >> amount;
    }
    cout << "Enter the index of first data from IT: ";
    cin >> first;
    while (first < 0) {
        cout << "Please, enter the number that more than 0: ";
        cin >> first;
    }
    IT* b = new IT[amount]; // �������� ������ �� �������� ������� b
    for (int i = 0; i < amount; i++)  b[i] = a[first + i]; // ��������� ���
    return b;
    //return b  - ���������� ������������
}
void bubble(IT* a, const int n) { //���������� ���������
    //Params:
    //IT* a - ��������� �� 1 ������� ������� a 
    //const int n  - ���������� ��������� ������� a
    for (int i = n - 1; i >= 0; i--) { // ������ ����� �� ����� ������� 
        for (int j = 0; j < i; j++) { // �� ������ ����� ����� ������ ������� �������� � �������� ���������� ������� � ����� ������� � �������������� �������� �� ������� ������
            if (a[j] > a[j + 1]) {
                IT tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void insert_sort(IT* a, const int n)//���������� ��������� 
{
    int i, j;
    IT value;
    for (i = 1; i < n; i++) // ���������� �� ����� ������� ����� 1 ��������
    {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--) //������� ������ ������� � ��������� ��� � ��� ��������������� ����� �������
            // � ������ �������� ��� 1 �������
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}
void Read(string path, IT* A) { //���������� ��������
    ifstream fout(path); //��������� ����� �� ����� � ����� path
    string serv, date, cost, pr_cost; // �������� ��� ���������� �������� ������ IT
    int i = 0; // ��� ���������� ������� 
    if (!fout.is_open()) { // ���� ���� �� ����������� - �������� ������, ��������� ���������
        cout << "ERROR: file can't be opened" << endl;
        exit(1);
    }
    else {
        while (!fout.eof()&&i!=6000) {
            getline(fout, cost, '\t');
            getline(fout, date, '\t');
            getline(fout, pr_cost, '\t');
            getline(fout, serv);
            A[i].Set(serv, cost, date, pr_cost);
            i++;
        }
        fout.close(); // ��������� �����
    }
}
const bool operator>(const IT& a1, const IT& a2) { //����������� �������� >
    if (a1.serv > a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost > a2.cost)) { // ���� �������� ����� �����, �� ���������� �� ��������� 
        return true;
    }
    return false;
} 
const bool operator<(const IT& a1, const IT& a2) { // ����������� �������� <
    if (a1.serv < a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost < a2.cost)) {
        return true;
    }
    return false;
}
const bool operator>=(const IT& a1, const IT& a2) {
    if (a1.serv >= a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost >= a2.cost)) {
        return true;
    }
    return false;
}
const bool operator<=(const IT& a1, const IT& a2) {
    if (a1.serv <= a2.serv) {
        return true;
    }
    else if ((a1.serv == a2.serv) and (a1.cost <= a2.cost)) {
        return true;
    }
    return false;
}
