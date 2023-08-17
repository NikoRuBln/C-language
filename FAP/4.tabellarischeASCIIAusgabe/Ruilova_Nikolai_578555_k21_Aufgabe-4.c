#include <stdio.h>


int Eingabe(int* UG, int* OG) {

	printf("Hinweis! Achten Sie bitte bei der Eingabe:\n1. Untergrenze darf nicht grosser als Obergrenze sein.\n2. Untergrenze muss groesser als 31 sein.\n");
	printf("3. Obergrenze darf nicht groesser als 256 sein.\n");
	printf("\nBitte geben Sie die Untergrenze der Tabelle ein:");
	scanf_s("%d", UG);
	printf("Bitte geben Sie die Obergrenze der Tabelle ein:");
	scanf_s("%d", OG);
	//Ungueltige Eingabe
	while (*UG > *OG || *UG <= 31 || *OG > 256)
	{
		printf("------------------------------------------------------------------------\n");
		printf("\nUngueltige Eingabe! Achten Sie bitte auf die Hinweise.\n\n");
		printf("Bitte geben Sie die Untergrenze der Tabelle ein:");
		scanf_s("%d", UG);
		printf("Bitte geben Sie die Obergrenze der Tabelle ein:");
		scanf_s("%d", OG);

	}
	printf("\nEingegebene Unter- und Obergrenze:\n");
	printf("Untergrenze: %d\n", *UG);
	printf("Obergrenze: %d\n", *OG);

	return 0;
}

int Ausgabe(int UG, int OG) {
	int i = 0;
	int zeilen = 0;
	int seiten = (OG - UG) / 21;
	int diff = OG - UG;

	
	//Ausgabe der Tabelle in unterschiedliche Seiten
	for (i = 0; i <= seiten; i ++)
	{
		printf("\nSeite %d von %d\n", i + 1, seiten + 1);
		printf("\n\t\t\t|\tZahl in Dez.\t|\tZahl in Hex.\t|\tASCII Zeichen\t|\n");
		printf("\t\t\t------------------------------------------------------------------------\n");

		for (zeilen = 0; zeilen <= diff ; zeilen++)
		{
			if (zeilen == 21 || UG > OG)
			{
				break;
			}
			//Ausgabe Tabelle
			printf("\t\t\t|\t\t%d\t|\t\t%x\t|\t\t'%c'\t|\n", UG, UG, UG); 
			UG++;
			
		}
		printf("\t\t\t------------------------------------------------------------------------\n");

		if (i < seiten)
		{
			
			printf("Druecken Sie eine beliebige Taste um naechste Seite anzuzeigen\n");
			getch();
		}
	}
	return 0;
}

int main()
{
	char rep = 'j';
	int UG = 0;
	int OG = 0;
	

	printf("Programm fuer die Ausgabe der ASCII-Tabelle\n");
	while (rep == 'j')
	{
		
		Eingabe(&UG, &OG);

		Ausgabe(UG, OG);

		//Wiederholung
		printf("\nMoechten Sie das Programm wiederholen?\n[j] fuer ja\n[n] fuer nein\n");
		scanf_s(" %c", &rep);
		if (rep != 'j' && rep != 'n')
		{
			printf("Ungueltige Eingabe!\n[j] fuer ja\n[n] fuer nein\n");
				scanf_s("  %c", &rep);
		}
	}

	printf("\nProgramm erfolgreich beendet\n");
	
	return 0;
}