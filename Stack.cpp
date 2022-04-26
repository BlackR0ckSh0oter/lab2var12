#include "Stack.h"
#include <iostream>
#include <locale>
#include <cstdlib>
#include <time.h>

using namespace std;

/* КОНСТРУКТОРЫ */

Stack::Stack() : top(0), size(0) {} //конструктор без параметров (исп. список инициализации)

Stack::Stack(int size_st) : top(0)//конструктор с параметром, задает размер и инициализирует элемент
{
	this->size = size_st; //вызванному объекту устанавливаем размер
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (top->next != 0) //пока не дойдем до нулевого указателя
		{
			Full* temp = top; //временная переменная юнита, присваиваем ей значение вершины
			top = temp->next; //теперь вершина указывает на следующий за ней элемент,
			delete temp; //а временную - удаляеям
		}
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
}

/* МЕТОДЫ КЛАССА СТЕКА */

void Stack::push(int value)
{
	Full* new_Full = new Full; //инициализируем новый элемента стека и выделение под него памяти
	new_Full->next = top; //теперь новый элемент стал вершиной
	top = new_Full; //и вершина указывает на новый элемент
	top->data = value; //вносим значение в вершину
	size++;
}

int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "Стек пуст, удалять нечего." << endl;
	}

	Full* temp = top; //временная переменная-вершина 
	int deldata = 0; //место под удаленный элемент

	deldata = top->data; //присваиваем значение удаляемого элемента
	top = top->next; 
	delete temp; //удаляем переменную-вершину
	size--;
	return deldata; //вернули удаленный элемент
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "Стек пуст, выводить нечего." << endl;
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
		cout << "Стек пуст, невозможно провести операцию!" << endl;
		system("cls");
	}

	int len = size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop();
	for (int i = len - 1; i >= 1; i--)
		this->push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete []buff;
	return *this; //возвращаем сам объект, который вызвал функцию
}

Stack& Stack::operator --(int)
{
	if (size == 0 || size == 1)
	{
		cout << "Стек пуст или не хватает элементов, невозможно провести операцию!" << endl;
		
	}
	else {
		int len = this->size; //переменная размера вызванного объекта
		int* buff = new int[len]; //буферный массив, куда занесем значения стека
		for (int i = 0; i < len; i++)
			buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
		for (int i = len - 1; i >= 2; i--)
			this->push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек

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
	cout << "Введите значение элемента: ";
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

