#include <stdio.h>


float	CelsiusFahrenheit(float C);

float	FahrenheitCelsius(float* F);



int	main()
{

	int choice;
	int rep;
	float C;
	float *F;
	float res;

	rep = 1;



	printf("Programm fuer die Umrechnung von Celsius auf Fahrenheit oder Fahrenheit auf Celsius\n");


	while (rep == 1)
	{

		C = 0;
		
		res = 0;
		choice = 0;

		printf("Bitte waehlen Sie:\n (1) Celsius in Fahrenheit angeben\n (2) Fahrenheit in Celsius angeben\n");
		scanf_s("%d", &choice);

		if (choice == 1)

		{

			printf("Bitte geben Sie einen Wert in Celsius ein\n");
			scanf_s("%f", &C);


			res = CelsiusFahrenheit(C);


			printf(" %.2f Celsius sind %.2f Fahrenheit\n", C, res);

		}


		if (choice == 2)

		{

			FahrenheitCelsius(&F);

		}


		if (choice >= 3 || choice <= 0)

		{

			printf("Ungueltige Auswahl\n");

		}


		printf("Programm Wiederholen?\n(1) Ja\n(2) Nein\n\n");
		scanf_s("%d", &rep);

	}


	printf("Programm erfolgreich beendet");
	return (0);


}



float	FahrenheitCelsius(float* F)
{

	float res;


	printf("Bitte geben Sie einen Wert in Fahrenheit ein\n");
	scanf_s("%f", F);


	res = (*F - 32) * 0.5556;


	printf("%.2f Fahrenheit sind %.2f Celsius\n", *F, res);

}

float CelsiusFahrenheit(float C)
{
	return (C * 1.8) + 32;
}