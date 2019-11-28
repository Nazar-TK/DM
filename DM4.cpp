#include <iostream>
#include <string>
using namespace std;

int vershyny;
int rebra;
struct Graf {
	int v1=0;
	int v2=0;
	int weight=0;
};

Graf graf[30];
int *versh =new int[vershyny];
void CreateGraf() {
	cout << "Введiть кiлькiсть вершин: ";
	    cin>> vershyny;
	    cout << "Введiть кiлькiсть ребер: ";
	    cin >> rebra;
		int v = 0;
for (int i = 0;i < rebra;i++)
	{	   
		cout << "Введiть вершину 1: ";
		cin >> graf[i].v1;
		
		cout << "Введiть вершину 2: ";
		cin >> graf[i].v2;
		
		cout << "Введiть вагу: ";
		cin >> graf[i].weight;		
	}
}
void Sort() {
	for (int i = 0; i < rebra;i++) {
		for (int j = 0; j < rebra;j++)
		{
			Graf test;
			if (i == j)
			{
				continue;
			}
			else if (graf[i].weight < graf[j].weight)
			{
				test = graf[i];
				graf[i] = graf[j];
				graf[j] = test;
			}
		}
	}
	}

void FillArray(int** arr, int ROWS, int COLLS) //функція заповнення масиву
{
	for (int i = 0;i < ROWS;i++)
	{
		for (int j = 0; j < COLLS;j++)
			arr[i][j] = 0;
	}
}
void PrintArray(int** arr, int ROWS, int COLLS) // функція виведення масиву на екран
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			cout <<arr[i][j]<<" ";
		}
		cout << endl;
	}
	
}
int main()
{
	setlocale(LC_ALL, "Ukrainian");

	CreateGraf();
	Sort();
	
	
	int ROWS = 5;
	int COLLS = 11;
	int** points = new int* [ROWS];   //створюємо динамічний двомірний масив
	for (int i = 0;i < ROWS; i++)
	{
		points[i] = new int[COLLS];
	}
	FillArray(points, 5, 11);
		PrintArray(points, 5, 11);
  int weight = graf[0].weight;
  points[0][0] = graf[0].v1;
  points[0][1] = graf[0].v2;
  cout << endl;
  PrintArray(points, 5, 11);
  cout << endl << endl;
  string v1 = std::to_string(graf[0].v1);
  string v2 = std::to_string(graf[0].v2);
  string result= v1 + "-" + v2 + "; ";

 
	int size1 = 2;
	int size2 = 0;
	int size3 = 0;
	int size4 = 0;
	int size5 = 0;
	int i = 0;
		for (int gr=1;gr < rebra;gr++)
		{
			
			bool v1exist = false;
			bool v2exist = false;
			int j = 0;
			

			while (points[i][j] != 0)
			{
				if (points[i][j] == graf[gr].v1)
				{
					v1exist = true;
					break;
				}
				else if (points[i][j + 1] == 0 || j + 1 == vershyny)
				{
					if (points[i][j] != graf[gr].v1)
					{
						v1exist = false;
						break;
					}
				}
				else
				{
					j++;
				}

			}
			int k = 0;
			while (points[i][k] != 0)
			{
				if (points[i][k] == graf[gr].v2)
				{
					v2exist = true;
					k++;
					break;
				}
				else if (points[i][k + 1] == 0 || k + 1 == vershyny)
				{
					if (points[i][k] != graf[gr].v2)
					{
						v2exist = false;
						k++;
						break;
					}
				}
				else
				{
					k++;
				}

			}
			if (v1exist == true && v2exist == true)
			{
				continue;
				i = 0;
			}
			else if (v1exist == true && v2exist == false)
			{
				for (int l = 1;l <= 5;l++)
				{
					int g = 0;
					if (points[l][g] == 0)
					{
						switch (i)
						{
						case 0: points[i][size1] = graf[gr].v2;size1++;break;
						case 1: points[i][size2] = graf[gr].v2;size2++;break;
						case 2: points[i][size3] = graf[gr].v2;size3++;break;
						case 3: points[i][size4] = graf[gr].v2;size4++;break;
						case 4: points[i][size5] = graf[gr].v2;size5++;break;
						}
						i = 0;
						break;
					}
					else
					{
						while (points[l][g] != 0)
						{

							if (points[l][g] == graf[gr].v2)
							{
								g = 0;

								while (points[l][g] != 0)
								{
									
									switch (i)
									{
									case 0: points[i][size1] = points[l][g];size1++;break;
									case 1: points[i][size2] = points[l][g];size2++;break;
									case 2: points[i][size3] = points[l][g];size3++;break;
									case 3: points[i][size4] = points[l][g];size4++;break;
									case 4: points[i][size5] = points[l][g];size5++;break;
									}
									points[l][g] = 0;
									
									g++;

								}
								switch (l)
									{
									case 0: size1=0;break;
									case 1: size2=0;break;
									case 2: size3=0;break;
									case 3: size4=0;break;
									case 4: size5=0;break;

									}
								i = 0;
								l = 6;
								break;
							}
							else
							{
								
								g++;
							}
						}
					}
				}

			}
			else if (v2exist == true && v1exist == false)
			{
				for (int l = 1;l <= 5;l++)
				{
					int g = 0;
					if (points[l][g] == 0)
					{				
						switch (i)
						{
						case 0: points[i][size1] = graf[gr].v1;size1++;break;
						case 1: points[i][size2] = graf[gr].v1;size2++;break;
						case 2: points[i][size3] = graf[gr].v1;size3++;break;
						case 3: points[i][size4] = graf[gr].v1;size4++;break;
						case 4: points[i][size5] = graf[gr].v1;size5++;break;
						}
						i = 0;
						break;
					}
					while (points[l][g] != 0)
					{
						if (points[l][g] == graf[gr].v1)
						{
							g = 0;
							while (points[l][g] != 0)
							{	
								switch (i)
								{
								case 0: points[i][size1] = points[l][g];size1++;break;
								case 1: points[i][size2] = points[l][g];size2++;break;
								case 2: points[i][size3] = points[l][g];size3++;break;
								case 3: points[i][size4] = points[l][g];size4++;break;
								case 4: points[i][size5] = points[l][g];size5++;break;
								}
								points[l][g] = 0;															
								g++;
							}
							switch (l)
								{
								case 0: size1=0;break;
								case 1: size2=0;break;
								case 2: size3=0;break;
								case 3: size4=0;break;
								case 4: size5=0;break;						
								}
							i = 0;
							l = 6;
							break;
						}
						else
						{
							
							g++;
						}
					}
				}
				
			}
			
			else if (v2exist == false && v1exist == false)
			{
				if (points[i + 1][0] == 0)
				{
					points[i + 1][0] = graf[gr].v1;
					points[i + 1][1] = graf[gr].v2;
					switch (i+1)
					{
					case 0: size1+=2;break;
					case 1: size2+=2;break;
					case 2: size3+=2;break;
					case 3: size4+=2;break;
					case 4: size5+=2;break;
					}
					i = 0;
				}
				else {
					gr--;
					i++;
					continue;
				}
			}
			cout << graf[gr].v1 << "-" << graf[gr].v2 << endl;
			PrintArray(points, 5, 11);

			cout << endl << endl;
			 v1 = to_string(graf[gr].v1);
			 v2 = to_string(graf[gr].v2);
			 result =result+ v1 + "-" + v2 + "; ";
			 weight += graf[gr].weight;
		}
	
	cout<<"++++++++++++++++++++++++++++++++++++\n";
	
	
	cout <<"\n\n\nМiнiмальне остове дерево графа зкладається з ребер: "<< result;
	cout << "\n\nВага мiнiмального остового дерева графа = " << weight<<endl;
	for (int i = 0;i < ROWS; i++)
	{
		delete[] points[i] ;
	}
	delete[] versh;

}