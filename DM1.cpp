#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x = 0, y = 0, z = 0;
	printf("Enter x: ");
	scanf_s("%d", &x);
	printf("Enter y: ");
	scanf_s("%d", &y);
	printf("Enter z: ");
	scanf_s("%d", &z);
	printf("x=%d, y=%d, z=%d\n", x, y, z);
	if (   x == 0 && y == 0 && z == 0 || x == 0 && y == 0 && z == 1 || x == 0 && y == 1 && z == 0
		|| x == 0 && y == 1 && z == 1 || x == 1 && y == 0 && z == 0 || x == 1 && y == 0 && z == 1
		|| x == 1 && y == 1 && z == 0 || x == 1 && y == 1 && z == 1)
		printf("False");
	else
		printf("Enter correct numbers");
}
