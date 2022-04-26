#pragma once


typedef struct Full
{
	int data;
	Full* next;
} Full; //элемент стека

class Stack
{
private:
	Full * top = 0; //указатель на начальный элемент стека - инициализированный элемент
	int size = 0; //размер стека
public:
	//конструкторы
	Stack(); //конструктор без параметров
	explicit Stack(int size_st); //явный конструктор с параметрами
	~Stack(); //деструктор
	Stack(const Stack& Stack_copy); //конструктор копирования

	//функции стека
	void push(int value); //добавление элемента в стек
	int pop(); //извлечение вершины
	void print(); //вывод стека на экран

	//геттеры и сеттеры
	Full* get_top(); //взять элемент стека
	int set_size(int& value); //поместить значение в стек
	int get_size() const; //взять размер стека

	//перегруженные операторы
	bool operator!() const; //проверка на пустоту
	Stack& operator --(); //префиксная форма
	Stack& operator --(int); //постфиксная форма
	friend void operator++(Stack& St); //префиксная форма
	friend void operator++(Stack& St, int); //постфиксная форма
};

