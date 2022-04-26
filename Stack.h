#pragma once


typedef struct Full
{
	int data;
	Full* next;
} Full; //������� �����

class Stack
{
private:
	Full * top = 0; //��������� �� ��������� ������� ����� - ������������������ �������
	int size = 0; //������ �����
public:
	//������������
	Stack(); //����������� ��� ����������
	explicit Stack(int size_st); //����� ����������� � �����������
	~Stack(); //����������
	Stack(const Stack& Stack_copy); //����������� �����������

	//������� �����
	void push(int value); //���������� �������� � ����
	int pop(); //���������� �������
	void print(); //����� ����� �� �����

	//������� � �������
	Full* get_top(); //����� ������� �����
	int set_size(int& value); //��������� �������� � ����
	int get_size() const; //����� ������ �����

	//������������� ���������
	bool operator!() const; //�������� �� �������
	Stack& operator --(); //���������� �����
	Stack& operator --(int); //����������� �����
	friend void operator++(Stack& St); //���������� �����
	friend void operator++(Stack& St, int); //����������� �����
};

