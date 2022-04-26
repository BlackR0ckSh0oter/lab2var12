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

	cout << "��������,  � ����� �������� �� ������ ��������: 1 - ������� ��������, 2 - �������� ��������\n";
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
			cout << "������� �1 - ������� �������� (����)\n";
			cout << "��������, ����� �������� �������� �� ������:" << endl;
			cout << "1 - ���������� ������ �������� � ����" << endl;
			cout << "2 - �������� �������� �� �����" << endl;
			cout << "3 - ����� ����� �� �����" << endl;
			cout << "4 - ���������� �������� ++ (���������� ��������)" << endl;
			cout << "5 - ����������� �������� ++ (���������� ���� ��������� ����� �� 0 �� 15;)" << endl;
			cout << "6 - ���������� �������� -- (�������� �������� �� �����)" << endl;
			cout << "7 - ����������� �������� -- (�������� ���� ��������� �� �����)" << endl;
			cout << "8 - ������� �� ������ ������� ������" << endl;
			cout << "0 - ����� �� ���������" << endl;
			cout << "--> ";
			cin >> c;

			switch (c)
			{
			case 1: //1 - ���������� ������ �������� � ����
				system("cls");
				cout << "������� ��������: " << endl;
				cin >> value;
				st.push(value);
				cout << "�������� ��������� � ����\n " << endl;
				break;
			case 2: //2 - �������� �������� �� �����
				if (!st)
				{
					cout << "���� ����, ��������� ������.\n " << endl;
					break;
				}
				else
				{
					system("cls");
					value = st.pop();
					cout << "����������� �������: " << value << endl;
				}
				break;
			case 3: //3 - ����� ����� �� �����
				if (!st)
				{
					cout << "���� ����, �������� ������.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					st.print();
					cout << "\n";
				}
				break;
			case 4: //4 - ���������� �������� ++ 
				    
					system("cls");
					++st;
					cout << "�������� ������ �������! ������������ ����: " << endl;
					st.print();
					cout << "\n";
				
				break;
			case 5: //5 - ����������� �������� ++ 

					system("cls");
					st++;
					cout << "�������� ������ �������! ������������ ����: " << endl;
					st.print();
					cout << "\n";
				
				break;
			case 6: //6 - ���������� �������� -- 
				if (!st)
				{
					cout << "���� ����, ���������� �������� ��������.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					--st;
					cout << "�������� ������ �������! ������������ ����: " << endl;
					st.print();
					cout << "\n";
				}
				break;
			case 7: //7 - ����������� �������� -- 
				if (!st)
				{
					cout << "���� ����, ���������� �������� ��������.\n" << endl;
					break;
				}
				else
				{
					system("cls");
					st--;
					cout << "�������� ������ �������! ������������ ����: " << endl;
					st.print();
					cout << "\n";
				}
				break;
			case 8: //0 - �����
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

		cout << "������� �2 - �������� ���������\n" << endl;
		flag = 1;

		while (flag == 1)
		{
			cout << "��������, ����� �������� �������� � ������� ������������ �����:" << endl;
			cout << "1 - ��������" << endl;
			cout << "2 - ��������� (���������������� ����� ������)" << endl;
			cout << "3 - ���������" << endl;
			cout << "4 - ������� (���������������� ����� ������)" << endl;
			cout << "5 - ��������� (���������������� ����� �����)" << endl;
			cout << "6 - ������� (���������������� ����� �����)" << endl;
			cout << "7 - ������������ ����������������� �����" << endl;
			cout << "8 - ������������ ���������� ������" << endl;
			cout << "9 - ��������� � ������ �������" << endl;
			cout << "0 - ����� �� ���������" << endl;
			cout << "--> ";
			cin >> c;

			switch (c)
			{
			case 1: //1 - ��������
				system("cls");
				cout << "������� ������ �����: " << endl;
				cin >> input_num1;
				cout << "������� ������ �����: " << endl;
				cin >> input_num2;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				res = num1 + num2;
				cout << "���������: ";
				res.out();
				break;
			case 2: //2 - ���������
				system("cls");
				cout << "������� �����, �� �������� ���� �������: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = num1 - 3;
				cout << "���������: ";
				res.out();
				break;	 
			case 3: //3 - ���������
				system("cls");
				cout << "������� ������ �����: " << endl;
				cin >> input_num1;
				cout << "������� ������ �����: " << endl;
				cin >> input_num2;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				res = num1*num2;
				cout << "���������: ";
				res.out();
				break;
			case 4: //4 - �������
				system("cls");
				cout << "������� �������: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = num1 / 4;
				cout << "���������: ";
				res.out();
				break;
			case 5: //5 - ���������
				system("cls");
				cout << "������� �����, ������� ���� �������: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = 13 - num1;
				cout << "���������: ";
				res.out();
				break;
			case 6: //6 - �������
				system("cls");
				cout << "������� ��������: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				res = 15 / num1;
				cout << "���������: ";
				res.out();
				break;
			case 7: //6 - ������������ ����������������� �����
				system("cls");
				cout << "������� �����: " << endl;
				cin >> input_num1;
				num1.set_element(input_num1);
				num2.set_element(input_num2);
				num2 = num1;
				res = num2;
				cout << "���������: ";
				res.out();
				break;
			case 8: //6 - ������������ ���������� ������
				system("cls");
				num1.set_element(input_num1);
				
				num1 = 13.12;
				res = num1;
				cout << "���������: ";
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
