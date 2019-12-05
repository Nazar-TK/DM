#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <locale>
using namespace std;
int main()
{
	ifstream fin("MyFile.txt");
	setlocale(LC_ALL, "Ukrainian");
	int versh, rebra;
	fin >> versh >> rebra;
	const int SIZE = 30;
	int matrix[SIZE][SIZE]; // матриця зв'язків
	int distance[SIZE]; // мінімальна відстань
	int visited[SIZE];  // чи відвідані вершни 
	int dis, top, min;
	int begin_index = 0;


	for (int i = 0; i < versh; i++)     // Iнiцiалiзацiя матрицi зв'язкiв
	{
		distance[i] = 99999;
		visited[i] = 0;
		for (int j = 0; j < versh; j++)
		{
			matrix[i][j] = 0;
			matrix[j][i] = 0;
		}
	}
	for (int i = 0;i < rebra;i++) {
		int v1, v2, dis;
		fin >> v1 >> v2 >> dis;
		matrix[v1 - 1][v2 - 1] = dis;
		matrix[v2 - 1][v1 - 1] = dis;
	}

	/*for (int i = 0; i < versh; i++)     // Вивiд матрицi
	{
		for (int j = 0; j < versh; j++)
		{
			cout << " " << matrix[i][j];
		}
		cout << endl;
	} */
	cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	distance[0] = 0;
	do {
		top = 99999;
		min = 99999;
		for (int i = 0;i < versh;i++)
		{
			if (visited[i] == 0 && distance[i] < min)
			{
				min = distance[i];
				top = i;
			}

		}
		if (top != 99999)
		{
			for (int i = 0; i < versh; i++)
			{
				if (matrix[top][i] > 0)
				{
					dis = min + matrix[top][i];
					if (dis < distance[i])
					{
						distance[i] = dis;
					}
				}
			}
			visited[top] = 1;
		}
	} while (top < 99999);

	int end = versh - 1;
	int waight = distance[end];
	int way[30];
	way[0] = versh - 1;
	int k = 1;
	while (end != 0)
	{
		for (int i = 0;i < versh;i++)
		{
			if (matrix[end][i] > 0)
			{
				if (distance[i] == waight - matrix[end][i])
				{
					waight = distance[i];
					way[k] = i;
					end = i;
					k++;
				}
			}
		}
	}
	cout << "\nНайкоротший шлях з V0 до V29: ";
	for (int i = k;i > 0;i--)
	{
		if (i - 1 > 0)
			cout << way[i - 1] << " -> ";
		else
			cout << way[i - 1];
	}
	cout << "\n\nДовжина шляху: " << distance[versh - 1] << endl;
	cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}