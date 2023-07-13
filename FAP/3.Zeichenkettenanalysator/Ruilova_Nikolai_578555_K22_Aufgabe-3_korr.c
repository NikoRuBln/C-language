#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX  62


char PZEingabe(int* lx, int* ly, int* lz)
{
	*lx = 0;
	*ly = 0;
	*lz = 0;

	printf("Bitte geben Sie drei Pruefzeichen ein:\n");
	*lx = getchar();
	getchar();
	*ly = getchar();
	getchar();
	*lz = getchar();
	getchar();

	printf("\nFolgende Pruefzeichen wurden eingegeben:\n1.'%c'\n2.'%c'\n3.'%c'\n", *lx, *ly, *lz);

	return 0;
}

char ZKEingabe(char* zk, char* dump)
{
	int i = 0;
	printf("Bitte geben Sie eine Zeichenkette ein\n");
	printf("Achtung! Diese darf maximal 60 Zeichen enthalten!\n");

	for (i = 0; i < 62; i++)
	{
		zk[i] = _getche();
		if (zk[i] == 13)
			break;
	}
	zk[i] = '\0';

	if ((strlen(zk) > 0) && (zk[strlen(zk) - 1] == '\n')) // falls '\n' am ende des strings, durch '\0' ersetzen
	{
		zk[strlen(zk) - 1] = '\0';
	}

	printf("\n\nEingegebene Zeichenkette:\n'%s'", zk);
	printf("\nAnzahl der Zeichen: %d\n", strlen(zk));




	if (strlen(zk) >= 60)
	{
		printf("\n\nEingegebene Zeichenkette enthaelt mehr als 60 Zeichen!\n");
		
	}


	return 0;
}


int main()
{
	int lx, ly, lz;   //Variablen fuer die Pruefzeichen
	int ax, ay, az, i, ges;
	int wh = 'j'; //Wiederholung
	char zk[MAX]; //Zeichenkette
	char dump[MAX * 2]; //Array zum abfangen des Overflows

	printf("Programm zur analyse einer eingegebenen Zeichenkette\n"); //Zweck des Programms
	printf("---------------------------------\n");
	while (wh == 'j')
	{
		ax = 0;
		ay = 0;
		az = 0;
		ges = 0;

		PZEingabe(&lx, &ly, &lz);

		ZKEingabe(zk, dump);



		for (i = 0; i <= strlen(zk); i++) //Pruefung der Zeichenkette
		{
			if (zk[i] == lx)
			{
				ax++;
			}
			if (zk[i] == ly)
			{
				ay++;
			}
			if (zk[i] == lz)
			{
				az++;
			}
		}
		ges = ax + ay + az; //zusammenrechnung der gesammten Zeichen
		ges = strlen(zk) - ges;

		printf("\n\nEingegebene Zeichenkette: '%s'\n", zk);
		printf("Eingegebene Pruefzeichen und deren Anzahl:\n1. '%c' = %d mal\n2. '%c' = %d mal\n3. '%c' = %d mal\n", lx, ax, ly, ay, lz, az);
		printf("Restliche Zeichen:%d\n", ges);

		//Wiederholung
		printf("\n\nMoechten Sie das Programm wiederholen?\n 'j' ja \n 'n' nein\n");
		wh = getchar();
		getchar();

		while (wh != 'j' && wh != 'n')
		{
			printf("\nUngueltige Eingabe!\n'j' fuer ja \n'n' fuer nein\n");
			wh = getchar();
		}
	}

	printf("\nProgramm erfolgreich beendet!\n");
	printf("---------------------------------");

	return 0;
}