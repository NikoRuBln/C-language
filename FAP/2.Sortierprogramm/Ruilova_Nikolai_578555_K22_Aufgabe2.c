#include <stdio.h>

 

void swap(int* x, int* y, int* z)
{

	int tmp;

	while (*x > *y || *y > *z)
	{

		if (*x > *y)
		{
			tmp = *x;
			*x = *y;
			*y = tmp;
		}

		if (*y > *z)
		{
			tmp = *y;
			*y = *z;
			*z = tmp;
		}
	}
	return;
}

void eingabe(int* x, int* y, int* z)
{
	printf("Bitte geben Sie drei Werte ein.\n");
	printf("Z1:");
	scanf_s("%d", x);

	printf("Z2:");
	scanf_s("%d", y);

	printf("Z3:");
	scanf_s("%d", z);

	return;
}

int main(void)
{
	char rep;
	int x, y, z;

	rep = 'j';
	x = 0;
	y = 0;
	z = 0;
	

	

	while ((rep == 'j'))
	{
		printf("---------------------------------------------\n");
		printf("\nProgramm zur Einordnung von eingegebenen Werten.\n");

		
		eingabe(&x, &y, &z);

		swap(&x, &y, &z);

		printf("\nWerte erfolgreich sortiert\n");
		printf("Z1:%d\nZ2:%d\nZ3:%d", x, y, z);

		//Wiederholung
		printf("\n---------------------------------------------\n");
		printf("Moechten Sie den Programm Wiederholen?\n'j' ja\n'n' nein\n");
		scanf_s(" %c", &rep);
		
		if (rep != 'j' && rep != 'n')
		{
			printf("\nUngueltige Auswahl!\nProgramm wiederholen?\n'j' ja\n'n' nein\n");
			scanf_s(" %c", &rep);
		}
		

	} 


	printf("\nProgramm Erfolgreich beendet!\n");

	return 0;

}


