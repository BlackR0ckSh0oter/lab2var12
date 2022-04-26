#include "Stack.h"
#include <iostream>
#include <locale>
#include <cstdlib>
#include <time.h>

using namespace std;

/* ������������ */

Stack::Stack() : top(0), size(0) {} //����������� ��� ���������� (���. ������ �������������)

Stack::Stack(int size_st) : top(0)//����������� � ����������, ������ ������ � �������������� �������
{
	this->size = size_st; //���������� ������� ������������� ������
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //������� �������
		size = 0; //������ �������
	}
	else
	{
		while (top->next != 0) //���� �� ������ �� �������� ���������
		{
			Full* temp = top; //��������� ���������� �����, ����������� �� �������� �������
			top = temp->next; //������ ������� ��������� �� ��������� �� ��� �������,
			delete temp; //� ��������� - ��������
		}
		delete top; //������� �������
		size = 0; //������ �������
	}
}

/* ������ ������ ����� */

void Stack::push(int value)
{
	Full* new_Full = new Full; //�������������� ����� �������� ����� � ��������� ��� ���� ������
	new_Full->next = top; //������ ����� ������� ���� ��������
	top = new_Full; //� ������� ��������� �� ����� �������
	top->data = value; //������ �������� � �������
	size++;
}

int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "���� ����, ������� ������." << endl;
	}

	Full* temp = top; //��������� ����������-������� 
	int deldata = 0; //����� ��� ��������� �������

	deldata = top->data; //����������� �������� ���������� ��������
	top = top->next; 
	delete temp; //������� ����������-�������
	size--;
	return deldata; //������� ��������� �������
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "���� ����, �������� ������." << endl;
	}
	else
	{
		Full* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " <-- ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Full* Stack::get_top()
{
	return top;
}

int Stack::get_size() const
{
	return size;
}

int Stack::set_size(int& value)
{
	size = value;
	return 0;
}

bool Stack::operator! () const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Stack& Stack::operator --()
{
	if (size == 0)
	{
		cout << "���� ����, ���������� �������� ��������!" << endl;
		system("cls");
	}

	int len = size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop();
	for (int i = len - 1; i >= 1; i--)
		this->push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete []buff;
	return *this; //���������� ��� ������, ������� ������ �������
}

Stack& Stack::operator --(int)
{
	if (size == 0 || size == 1)
	{
		cout << "���� ���� ��� �� ������� ���������, ���������� �������� ��������!" << endl;
		
	}
	else {
		int len = this->size; //���������� ������� ���������� �������
		int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
		for (int i = 0; i < len; i++)
			buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
		for (int i = len - 1; i >= 2; i--)
			this->push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����

		delete[] buff;
	}
	return *this;
}

void operator++ (Stack& St)
{
	Full* new_Full = new Full; 
	new_Full->next = St.top; 
	St.top = new_Full; 
	int value;
	cout << "������� �������� ��������: ";
	cin >> value;
	St.top->data = value; 
	St.size++;
}

void operator++(Stack& St, int)
{
	int a = 1;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i <= a; i++)
	{
		Full* new_Full = new Full; 
		new_Full->next = St.top; 
		St.top = new_Full; 
		int value1 = (0 + rand() % 14);
		St.top->data = value1; 
		St.size++;
	}
}

