#pragma once // ���������, ����������� ��� ����, ����� ���� � ��� ��  ���� �� ����������� ��������� ���
#include <iostream> //����������� ������������� ����� iostream
#include <string> //����������� ���������� ��� ������� �� ��������
using namespace std; // ���������� ������������ ���� std
class IT //�������� ������ IT
{ 
public:
    IT() {}; //����������� �� ��������� 
    IT(IT&a); // �������� ������������ �����������
    string serv, date, cost, pr_cost; // ������� ������
    void Set(string, string, string, string); // �������� ��� ������� Set
};
IT::IT(IT& a) { // ����������� ����������� 
    this->serv = a.serv;
    this->cost = a.cost;
    this->pr_cost = a.pr_cost;
    this->date = a.date;
}

void IT::Set(string serv, string cost, string date, string pr_cost) { // ���������� ����� ������ 
    this->cost = cost;
    this->serv = serv;
   
    this->date = date;
    this->pr_cost = pr_cost;
}