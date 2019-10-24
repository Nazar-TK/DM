#include<iostream>

using namespace std;
int SIZE1=1; //створення змінних та масивів.
int SIZE2=1;

void FillArray(int* const arr, const int size) //функція заповенння масиву
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t";
		 cin>>arr[i];
	}
}

void PrintArray( const int* const arr, const int size) //функція виведення масиву
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Check(int* arr, int size) //функція перевірки елементів масиву на унікальність
{
	bool AlreadyThere;

	for (int i = 0;i < size;i++)
	{
		AlreadyThere = false;
		for (int j = 0; j < size;j++)
		{
			if (i == j)
				continue;
			if (arr[i] == arr[j])
			{
				cout << "Такий елемент \"" << arr[i] << "\" у множинi вже iснує, введiть новий: ";
				cin >> arr[i];

				break;
			}
		}
	}
}

void PrintMatrix(int** arr, int ROWS, int COLLS) // функція виведення матриці на екран
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << endl << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	
	cout << "Введiть кiлькiсть елементiв множини 1: ";
	cin >> SIZE1;
	int* mas1 = new int[SIZE1];            //Створення і виведення матриць, перевірка елементів на унікальність.
	cout << "Введiть елементи множини 1\n";
	FillArray(mas1, SIZE1);
	Check(mas1, SIZE1);
	
	cout << "\nВведiть кiлькiсть елементiв множини 2: ";
	cin >> SIZE2;
	int* mas2 = new int[SIZE2];
	cout << "Введiть елементи множини 2\n";
	FillArray(mas2, SIZE2);
	Check(mas2, SIZE2);
    cout << "\n\nМножина 1: ";
	PrintArray(mas1, SIZE1);
	cout << "\n\nМножина 2: ";
	PrintArray(mas2, SIZE2);

	int** matrix = new int* [SIZE2];   //створюємо динамічний двомірний масив
	for (int i = 0;i < SIZE2; i++)
	{
		matrix[i] = new int[SIZE1];
	}

	for (int i = 0;i < SIZE2;i++)      //створення матриці бінарних відношень
	{
		for (int j = 0;j < SIZE1;j++)
		{
			if (mas2[i] * 2 + 1 > mas1[j])
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
	cout << "\n-----------------------------------------------------------" << endl << endl << endl;
	PrintMatrix(matrix, SIZE2, SIZE1);
	cout << "-----------------------------------------------------------" << endl << endl << endl;
	if (SIZE1 != SIZE2)
		return 0;
    bool reflexivity; 
	for (int i = 0;i < SIZE1;i++)  //перевірка на рефлексивність
	{
		reflexivity = matrix[0][0];
		if (matrix[i][i] != reflexivity)
		{
			cout << "Матриця не рефлесивна.\n\n"; 
			goto link_ref;    //якщо виконуєтьс ця умова, переходимо за лінком.
			break;
		}
	}
	if (reflexivity)
		cout << "Матриця  рефлексивна.\n\n";
	else
		cout << "Матриця  антирефлесивна.\n\n";
link_ref:

	for (int i = 0;i < SIZE1;i++) //перевірка матриці на симетричність
	{ 
		for (int j = 0;j < SIZE1; j++)
		{
			if (matrix[i][j] != matrix[j][i] && i != j)
			{
				goto link_sym;
			}
			else if (i == j && j == SIZE1 - 1)
			{
				cout << "Матриця симетрична.\n\n";
				goto link_sym_end;
			}
		}
	}
link_sym:
	for (int i = 0;i < SIZE1;i++) //перевірка матриці на асиметричнсть і антисиметричність
	{

		for (int j = 0;j < SIZE1; j++)
		{
			if (matrix[i][j] == matrix[j][i] && i != j)
			{
				cout << "Матриця асиметрична.\n\n";
				goto link_sym_end;
			}
			else if (i == j && j == SIZE1 - 1)
				cout << "Матриця антисиметрична.\n\n";
		}
	}
link_sym_end:

	bool transitivity = true;      
	for (int i = 0;i < SIZE1;i++)  //перевірка на транзитивність
	{
		for (int j = 0;j < SIZE1; j++)
		{
			for (int k = 0; k < SIZE1;k++)
			{
				if (i == j && i == k && j == k)
					continue;
				else if (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] != 1)
				{
					transitivity = false;
					goto link;
				}	
			}
		}
	}
	link:
	if (transitivity)
		cout << "Матриця транзитивна.\n\n";
	else
	{
		for (int i = 0;i < SIZE1;i++)  //перевірка на антитранзитивність
		{
			for (int j = 0;j < SIZE1; j++)
			{
				for (int k = 0; k < SIZE1;k++)
				{
					if (i == j && i == k && j == k)
						cout << "Матриця не транзитивна." << endl;
						goto end;
				}
			}
		}
	}
		cout << "Матриця антитранзитивна.\n\n";
	end:
	delete[] mas1;  // Видалення динамічних масивів.
	delete[] mas2;
	for (int i = 0;i < SIZE2;i++)
	{
		delete[]matrix[i];
	}
}