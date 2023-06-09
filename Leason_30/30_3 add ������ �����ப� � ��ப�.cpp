//#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <windows.h>

using namespace std;

/*
*
Задание :  Напишите программу, которая запрашивает с клавиатуры ввод трех строк.
Программа заменяет в первой строке все вхождения в нее второй строки на третью строку
(память для первой строки перераспределяется и размер меняется). Пример работы программы:

Строка: This is my pen, my notebook, mygum
Подстрока для замены: my
Замещающая подстрока: YOUR
  Строка после замены: This is YOUR pen, YOUR notebook, YOURgum
*/



int main()
{
	system("chcp 1251>nul");

	// Вариант 1 базовый - без динамического выделения памяти
	{
		char str[] = "This is my pen, my notebook, mygum ", res[200] = "";
		char wd[] = "my", wd2[] = "YOUR";
		char* t, * t2;

		t = strstr(str, wd);
		t2 = str;

		while (t)
		{
			int index = t - t2;
			cout << "\nИндекс: " << index;// отладочный код
			int len = strlen(t);

			strncat_s(res, t2, index);
			strcat_s(res, wd2);

			t2 = t + strlen(wd);
			t = strstr(t2, wd);
		}

		if (t2)
		{
			strcat_s(res, t2);
		}
		cout << endl << str << endl << res << endl;

	}


	//-------------------------------------------------------------------------
	cout << "\n\n------------------------------------\n";
	// Вариант 2 - с динамическим выделением памяти

	char* str = new char[] {"This is my pen, my notebook, mygum"};

	char sub_str1[] = "my";
	char sub_str2[] = "YOUR";

	char* p = strstr(str, sub_str1);
	int count = 0;
	// Подсчет количества вхождений подстроки в строку
	if (p) {
		while (p)
		{
			//index = p - str;
			//cout << "\nИндекс: " << index;
			p += strlen(sub_str1);
			p = strstr(p, sub_str1);
			count++;
		}
		cout << "\nСтрока: " << str << "\nПодстрока: " << sub_str1 << endl;
		cout << "\nКоличество вхождений подстроки в строку: " << count;

		// Выделение памяти под новую строку

		int size = strlen(str) - count * strlen(sub_str1) + count * strlen(sub_str2) + 1;
		int k = 0;
		char* result = new char[size];
		result[0] = '\0';

		// Формировани строки(по базовому алгоритму):

		char* t, * t2;

		t = strstr(str, sub_str1);
		t2 = str;

		while (t)
		{
			int index = t - t2;
			cout << "\nИндекс: " << index;// отладочный код
			int len = strlen(t);

			strncat_s(result, size, t2, index);
			strcat_s(result, size, sub_str2);

			t2 = t + strlen(sub_str1);
			t = strstr(t2, sub_str1);
		}

		if (t2)
		{
			strcat_s(result, size, t2);
		}
		cout << endl << str << "  длина строки: "<< strlen(str)
			<< endl << result << "  длина строки: " << strlen(result)<< endl;

		// Освобождение памяти:
		delete[]str;
		delete[]result;

	}
	else cout << "Такой подстроки нет в строке";

	_getch();
}

