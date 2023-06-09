#include <iostream>
#include <conio.h>

using namespace std;

void show(int* m, int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
}


bool contain(int* m, int s, int value)
{
	for (int i = 0; i < s; i++)
	{
		if (m[i] == value)
		{
			return true;
		}
	}
	return false;
}

int* masunion(int* m1, int s1, int* m2, int s2, int& s3)
{
	int  i, j = 0;
	s3 = 0;// Начальное значение счетчика для результирующего массива
	int* t = new int[s1 + s2]; // временный массив
	//cout << "\nunion:\n";
	for (i = 0; i < s1; i++)
	{
		// Если элемент массива m1 не присутствует во временном массиве, записываем его.
		// Проверку осуществляем до текущего размера результирующего массива s3.
		if (!contain(t, s3, m1[i])) {
			//cout << m1[i] << " ";
			t[s3] = m1[i];
			s3++;
		}
	}

	for (i = 0; i < s2; i++)
	{
		// Если элемент массива m2 не присутствует во временном массиве, записываем его.
		// Проверку осуществляем до текущего размера результирующего массива s3.

		if (!contain(t, s3, m2[i])) {
			//cout << m2[i] << " ";
			t[s3] = m2[i];
			s3++;
		}
	}
	//cout << endl << s3 << endl;

	int* m3 = new int[s3]; // выделяем пямять под результирующий массив
	for (i = 0; i < s3; i++)
	{
		m3[i] = t[i]; // переписываем значения из временного массива
	}
	delete[]t; // освобождаем временный массив
	return m3;
}




int main()
{
	system("chcp 1251>nul");
	system("color 1F");

	const int N = 12, M = 10;
	int m1[N]{ 5, 8, 17, 24, 37, 5, 37, 24, 8, 17, - 8, 7 };
	int m2[M]{ 15, 6, -8, 2, 17, 5, 4, 7, 9, 2 };

	int s3;
	int* m3 = masunion(m1, N, m2, M, s3);
	if (m3)
	{
		cout << "\nИсходные массивы: \n";
		show(m1, N);
		show(m2, M);

		cout << "\nОбъединение массивов с уникальными значениями: \n";
		show(m3, s3);

		delete[]m3;
		m3 = nullptr;
	}


	_getch();
	return 0;
}
