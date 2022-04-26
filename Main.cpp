#include "Stack.h"
#include "Material.h"
#include <iostream>
#include <locale>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int g = 0;
	int stack_size = 0, value = 0; 
	int flag = 1, c;

	cout << "Выберите,  с каким заданием вы будете работать: 1 - унарные операции, 2 - бинарные операции\n";
	cout << "-->";
	cin >> g;
	if (g == 1)
		
	{
		srand(static_cast<unsigned int>(time(NULL)));
		stack_size = (0 + rand() % 14);

		Stack st;
		for (int i = 0; i < stack_size; i++)
		{
			value = (0 + rand() % 14);
			st.push(value);
		}
		system("cls");

		while (flag == 1)
		{
			cout << "Задание №1 - Унарные операции (стек)\n";
			cout << "Выберите, какие операции провести со стеком:" << endl;
			cout << "1 - Добавление нового элемента в стек" << endl;
			cout << "2 - Удаление элемента из стека" << endl;
			cout << "3 - Вывод стека на экран" << endl;
			cout << "4 - Префиксный оператор ++ (добавление элемента)" << endl;
			cout << "5 - Постфиксный оператор ++ (добавление двух случайных чисел от 0 до 15;)" << endl;
			cout << "6 - Префиксный оператор -- (удаление элемента из стека)" << endl;
			cout << "7 - Постфиксный оператор -- (удаление двух элементов из стека)" << endl;
			cout << "8 - Переход ко втрому заданию работы" << endl;
			cout << "0 - Выход из программы" << endl;
			cout << "--> ";
			cin >> c;

			switch (c)
			{
			case 1: //1 - Добавление нового элемента в стек
				system("cls");
				cout << "Введите значение: " << endl;
				cin >> value;
				st.push(value);
				cout << "Значение добавлено в стек\n " << endl;
				break;
			case 2: //2 - Удаление элемента из стека
				if (!st)
				{
					cout << "Стек пуст, извлекать нечего.\n " << endl;
					break;
				}
				else
				{
					system("cls");
					value = st.pop();
					cout << "Извлеченный элемент: " << value << endl;
				}
				break;
			case 3: //3 - Вывод стека на экран
				if (!st)
				{
					cout << "Стек пуст, выводить нечего.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					st.print();
					cout << "\n";
				}
				break;
			case 4: //4 - Префиксный оператор ++ 
				    
					system("cls");
					++st;
					cout << "Операция прошла успешно! Получившийся стек: " << endl;
					st.print();
					cout << "\n";
				
				break;
			case 5: //5 - Постфиксный оператор ++ 

					system("cls");
					st++;
					cout << "Операция прошла успешно! Получившийся стек: " << endl;
					st.print();
					cout << "\n";
				
				break;
			case 6: //6 - Префиксный оператор -- 
				if (!st)
				{
					cout << "Стек пуст, невозможно провести операцию.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					--st;
					cout << "Операция прошла успешно! Получившийся стек: " << endl;
					st.print();
					cout << "\n";
				}
				break;
			case 7: //7 - Постфиксный оператор -- 
				if (!st)
				{
					cout << "Стек пуст, невозможно провести операцию.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					st--;
					cout << "Операция прошла успешно! Получившийся стек: " << endl;
					st.print();
					cout << "\n";
				}
				break;
			case 8: //0 - Выход
				cout << "\n";
				flag = 0;
				break;

			case 0:
				exit(1);
				break;
			default:
				system("cls");
				cout << "Error" << endl;
				break;
			}
		}

		
		system("cls");
	}
	
	
		float input_num1, input_num2;
		material num1, num2, res(0.0);

		cout << "Задание №2 - Бинарные операторы\n" << endl;
		flag = 1;

		while (flag == 1)
		{
			cout << "Выберите, какие операции провести с классом вещественных чисел:" << endl;
			cout << "1 - Сложение" << endl;
			cout << "2 - Вычитание (пользовательское число справа)" << endl;
			cout << "3 - Умножение" << endl;
			cout << "4 - Деление (пользовательское число справа)" << endl;
			cout << "5 - Вычитание (пользовательское число слева)" << endl;
			cout << "6 - Деление (пользовательское число слева)" << endl;
			cout << "7 - Присваивание пользовательского числа" << endl;
			cout << "8 - Присваивание экземпляра класса" << endl;
			cout << "9 - Вернуться к выбору задания" << endl;
			cout << "0 - Выход из программы" << endl;
			cout << "--> ";
			cin >> c;

			switch (c)
			{
			case 1: //1 - Сложение
				system("cls");
				cout << "Введите первое число: " << endl;
				cin >> input_num1;
				cout << "Введите второе число: " << endl;
				cin >> input_num2;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				res = num1 + num2;
				cout << "Результат: ";
				res.out();
				break;
			case 2: //2 - Вычитание
				system("cls");
				cout << "Введите число, из которого надо вычесть: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = num1 - 3;
				cout << "Результат: ";
				res.out();
				break;	 
			case 3: //3 - умножение
				system("cls");
				cout << "Введите первое число: " << endl;
				cin >> input_num1;
				cout << "Введите второе число: " << endl;
				cin >> input_num2;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				res = num1*num2;
				cout << "Результат: ";
				res.out();
				break;
			case 4: //4 - деление
				system("cls");
				cout << "Введите делимое: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = num1 / 4;
				cout << "Результат: ";
				res.out();
				break;
			case 5: //5 - вычитание
				system("cls");
				cout << "Введите число, которое надо вычесть: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = 13 - num1;
				cout << "Результат: ";
				res.out();
				break;
			case 6: //6 - деление
				system("cls");
				cout << "Введите делитель: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = 15 / num1;
				cout << "Результат: ";
				res.out();
				break;
			case 7: //6 - присваивание пользовательского числа
				system("cls");
				cout << "Введите число: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				num2 = num1;
				res = num2;
				cout << "Результат: ";
				res.out();
				break;
			case 8: //6 - присваивание экземпляра класса
				system("cls");
				num1.set_element(input_num1);
				
				num1 = 13.12;
				res = num1;
				cout << "Результат: ";
				res.out();
				break;
			case 9: 
				cout << "\n";
				main();
				break;
			case 0:
				cout << "\n";
				flag = 0;
				break;
			default:
				system("cls");
				cout << "Error" << endl;
				break;
			}
		}
	
	return 0;
}
