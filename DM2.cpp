#include <iostream> //Додаємо бібліотеку

using namespace std;
int u = 0;
int k = 0;

void FillArray(char mas[], const int size) //Функція вводу множини з клавіатури
{
	for (int i = 0;i < size; i++)
	{
		cout << i + 1 << " el = ";

		cin >> mas[i];
		
	}
}

void PrintArray(char mas[],const int size) //Функція виведення масиву на екран
{
		for (int i = 0;i < size; i++)
		{
			cout << mas[i] << "  ";
		}
}

void Check(char mas[], int size) //функція перевірки елементів масиву на унікальність
{
	bool AlreadyThere;
	
	for (int i = 0;i <size;i++)
	{
		AlreadyThere = false;
		for (int j = 0; j < size;j++)
		{
			if (i == j)
				continue;
			if (mas[i] == mas[j])
			{
				cout << "Такий елемент \""<< mas[i]<< "\" у множинi вже iснує, введiть новий: ";
				cin >> mas[i];

				break;
			}
		}
	}
}

void Universum(char mas1[], char mas2[],char universum[],int SIZE1, int SIZE2 )
{                                    //функція створення універсуму.
	bool AlreadyThere;
	for (u; u < SIZE1;u++)
	{
		universum[u] = mas1[u];
	}
	for (int i = 0;i < SIZE2;i++)
	{
		AlreadyThere = false;
		for (int j = 0; j < u;j++)
		{
			if (mas2[i] == universum[j])
			{
				AlreadyThere = true;
				break;
			}
		}
			if(!AlreadyThere)
			{
				universum[u] = mas2[i];
				u++;
			}
	}	
}

void Difference(char mas1[], char mas2[], int SIZE1, int SIZE2) //функція знаходження різниці
{
	k = 0;
	bool AlreadyThere;
	for (int i = 0;i < SIZE1;i++)
	{
		AlreadyThere = false;
		int j = 0;
		for (j; j < SIZE2;j++)
		{
			if (mas1[i] == mas2[j])
			{
				AlreadyThere = true;
				break;
			}
		}
		if (!AlreadyThere)
		{
			cout << mas1[i] << " ";
			k++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	int SIZE1 = 7;        //створення змінних та масивів.
	int SIZE2 = 5;
    
	char *mas1 = new char [SIZE1];
	char *mas2 = new char[SIZE2];
	char* universum = new char[SIZE1 + SIZE2];

	cout << "Array 1: " << endl << endl;;        //застосування виществорених функцій
	FillArray(mas1, SIZE1);
    Check(mas1, SIZE1);
	cout << endl << endl << "Array 2: " << endl<< endl;;
	FillArray(mas2, SIZE2);
	Check(mas2, SIZE2);
	Universum(mas1, mas2, universum, SIZE1, SIZE2);
	
	cout << endl << endl << "mas1: ";
	PrintArray(mas1 , SIZE1);
	cout << endl << endl<< "mas2: ";
	PrintArray(mas2, SIZE2);
	cout << endl << endl << "Universum: ";;
	PrintArray(universum, u);
	cout << endl << endl;

	cout << "Рiзницею мiж множинами Array 1 та Array 2 є:\t";
	Difference(mas1, mas2, SIZE1, SIZE2);
	cout << "\nПотужнсiть множини = " << k << endl;

	cout << endl << endl << "Рiзницею мiж множинами Array 2 та Array 1 є:\t";
	Difference(mas2, mas1, SIZE2, SIZE1);
	cout << "\nПотужнсiть множини = " << k << endl << endl;

	cout << endl << endl << "Доповнення множини Array 1  є:\t";
	Difference(universum, mas1, u, SIZE1);
	cout << "\nПотужнсiть множини = " << k << endl << endl;

	cout << endl << endl << "Доповнення множини Array 2  є:\t";
	Difference(universum, mas2, u, SIZE2);
	cout << "\nПотужнсiть множини = " << k << endl << endl;
}