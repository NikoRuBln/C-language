// Widerstandsfarbcode_Vorlage.c : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
/*
 Title : Dekodierung der Farbkennzeichnungen von Widerstaenden
 LastEdit: 05/12/2022
 Authors : Junghanns / Biella
(Quellcode der Aufgabenstellung aus:
Johnsonbaugh/ Kalin:Application Programming in ANSI C )
 System : ANSI-C-Compiler
---------------------------------------------------------------------------
Schwerpunkte: - Alternativen und Fallauswahl
 - Lesen und Erweitern von Programmen
 - Eigenstaendige Ergebniskontrolle
 mit interaktiver Farbcode-Tabelle
 Link: http://www.umrechnung.org/elektrischer-widerstand-farbcode/
 widerstand-farbcode-rechner-tabelle.htm
---------------------------------------------------------------------------
Aufgabe:
Das folgende Programm dient zur Dekodierung von Farbkennzeichnungen auf
Widerstaenden. Machen Sie sich die Wirkungsweise des Programmes klar,
bevor Sie es uebersetzen und testen.
Ueberarbeiten Sie das Programm so, dass noch ein vierter Farbkode eingelesen
wird, wobei gilt
 - Farbcode fehlt (-) -> max 20 % Toleranz
 - Farbcode silber (S) -> max 10 % Toleranz
 - Farbcode gold (L) -> max 5 % Toleranz
Ausgehend von diesem Code soll jetzt zusaetzlich ausgegeben werden, in
welchem Widerstandsbereich das betreffende Bauelement liegen kann.
---------------------------------------------------------------------------
 Stellen, an denen der Quellcode geaendert bzw. ergaenzt
 wird, sind zu gekennzeichnen, z. B. in der Form
 /* Ergaenzung durch Name am tt.mm.jj von hier ... */
//color4 = decode_tolerance(code4); /* Toleranz dekodieren */
/* ... bis hier. */
/* Sie sollten diese oder eine aehnliche Kommentierung immer
 verwenden, wenn Sie vorhandene Quellcodes ueberarbeiten.
 Damit laesst sich bei Bedarf leicht nachvollziehen, wer
 wann welche Veraenderungen vorgenommen hat, die man
 damit bei Bedarf auch leicht wieder rueckgaengig machen
 kann. Unabhaengig davon nimmt man Aenderungen immer an
 einer Kopie der Originaldatei vor!
*/
/* This program computes the resistance in ohms for a resistor. It
 prints a menu of colors on bands that mark a resistor and asks
 the user to enter character codes for each brand; for example,
 the user might enter 'B' for black. The program decodes the
 characters, computes the resistance, and prints the result.
 The function main invokes print_codes to print the codes,
 getchar to read three such codes from the keyboard, and
 decode_char to do the decoding. main uses a standard library
 function pow, which raises a number to a power to help compute
 the resistance; main then prints the resistance as a floating-
 point number.
*/

/* Korrektur durch Nikolai Ruilova am 15.12.2022 von hier ... */

//#include "stdafx.h"
#include <stdio.h> 

/*... bis hier, stdio bibliothek eingefuegt da die externe header Datei "stdafx.h" Probleme beim kompilieren hatte */
#include <stdlib.h>
#include <math.h>
#include <conio.h> 


void print_codes(void); /* menu of codes */
double decode_char(char code);

/* Loesche Bildschirm */
void Clear()
{
	system("cls");
	/* Dies setzt die Einbindung von <stdlib.h> voraus. */
}

/* Korrektur durch Nikolai Ruilova am 15.12.2022 von hier ... */

//int _tmain(int argc, _TCHAR* argv[])
int main() 

/* ... bis hier. int main anstatt von int _tmain, _TCHAR* Argument gibt Probleme beim kompilieren*/

{
	char code1, code2, code3; /* one code per band */

	/* Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ... */
	char code4, rep = 'j';
	/*... bis hier, Erweiterung durch weitere Variablen "code4" fuer die Eingabe von Toleranzbereich und "rep" fuer die Wiederholung des Programms*/

	double resistance;
	double color1, color2, color3; /* decoded values */

	/* Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ... */
	double color4;
	double flag;
	/*... bis hier, Erweiterung fuer die Verarbeitung des Toleranzbereiches*/

	/*Erweiterung durch Nikolai Ruilova am 15.12.2022 von hier...*/
	while (rep == 'j')
	{
	/*...bis hier, Einfuehrung einer Schleife fuer die Wiederholung des Programms*/

		/* Print codes and prompt for user input. */
		Clear();

		/* Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ... */
		printf("\n\tProgramm fuer die Berechnung des Wiederstandwertes und Ausgabe des Toleranzbereiches\n");
		/*... bis hier, Erweiterung fuer die Ausgabe des Programmzwecks*/

		print_codes();
		printf("\n\n\tGeben Sie die drei Farbcodes des Widerstands ein [z. B. OYG]: ");
		/* Read three character codes.
		! Anwendung der Funktion getche() erfordert die Bibliothek <conio.h> */

		/*Korrektur durch Nikolai Ruilova am 15.12.2022 von hier...*/

		//code1 = getche(); /* Einlesen eines einzelnen Zeichens von Tastatur */
		//code2 = getche(); /* Eingabe wird in diesem Fall nicht mit <enter> */
		//code3 = getche(); /* abgeschlossen, also z.B.: RRR<enter> */

		code1 = _getche();
		code2 = _getche(); 
		code3 = _getche(); 

		/*...bis hier, getche() durch _getche() ersetzt, da getche() bei aktuellem Kompiler Probleme ausloest  */


		/* Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ... */

		printf("\n\n\tGeben Sie den Toleranzbereich ein:");
		code4 = _getche();

		/*... bis hier, Erweiterung fuer die Eingabe des Toleranzbereiches*/

	   /* Decode each character code. */
		color1 = decode_char(code1);
		color2 = decode_char(code2);
		color3 = decode_char(code3);

		/*Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ...*/

		color4 = decode_char(code4);

		/*... bis hier, Erweiterung fuer die Verarbeitung der code4 Variable fuer den Toleranzbereich mithilfe der vorhandenen decode_char Funktion*/

		 /* Check whether codes were legal. */
		/*Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ...*/

		if (color1 == -999.0 || color2 == -999.0 ||
			color3 == -999.0 || color4 == -999.0)

		/*...bis hier, Erweiterung durch eine vierte Kondition fuer das Testen der Gueltigkeit der Eingabe des Toleranzbereiches (color4)*/

			printf("\n\n\tBad code -- cannot compute resistance\n\n\n");
		/* If codes were legal, compute and print resistance in ohms. */
		else {
			resistance = (10.0 * color1 + color2) * pow(10.0, color3);
			printf("\n\n\tWiderstand in Ohm:\t%.0f\n\n", resistance);

			/*Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ...*/

			flag = (resistance / 100) * color4;
			printf("\tToleranzbereich (%.0f%%) liegt zwischen %.0f und %.0f Ohm\n\n", color4, resistance - flag, resistance + flag);

			/*...bis hier, Berechnung und Ausgabe des Toleranzbereiches*/

		}
		/*Erweiterung durch Nikolai Ruilova am 15.12.2022 von hier...*/

		printf("\tMoechten Sie den Programm wiederholen? (j/n):");
		rep = _getche();
		while (rep != 'j' && rep != 'n')
		{
			printf("\nUngueltige Eingabe!\n");
			printf("\n\tMoechten Sie den Programm wiederholen? (j/n):");
			rep = _getche();
		}
	}
	printf("\n\tProgramm erfolgreich beendet\n\n");
	/*...bis hier, Eingabe fuer die Wiederholung des Programms und Testen von gueltige Eingabe*/

	return 0;
}

/* This function prints a menu of color codes to guide the user in
 entering input. */
void print_codes(void)
{
	printf("\n\n\tDekodierung der Farbkennzeichnungen von Widerstaenden\n");
	printf("\n\n\tEs werden folgende Farbkodierungen verwendet:\n\n\n\t");
	printf("FARBE\t\t\t KODIERUNG\n\t");
	printf("-----\t\t\t ----\n\n");
	printf("\tBlack-------------------> B\n");
	printf("\tBrown-------------------> N\n");
	printf("\tRed---------------------> R\n");
	printf("\tOrange------------------> O\n");
	printf("\tYellow------------------> Y\n");
	printf("\tGreen-------------------> G\n");
	printf("\tBlue--------------------> E\n");
	printf("\tViolet------------------> V\n");
	printf("\tGray--------------------> A\n");
	printf("\tWhite-------------------> W\n");

	/* Ergaenzung durch Nikolai Ruilova am 15.12.2022 von hier ... */

	printf("\n\t--moegliche Toleranzen--\n");
	printf("\tSilver (10%%) -----------> S\n");
	printf("\tGold ( 5%%) -----------> L\n");
	printf("\tnone (20%%) -----------> -\n");

	/* ... bis hier. Es wurden drei Farbkodes ergaenzt */

}
/* This function expects a character (color code) and returns a
 double precision floating point number as its value. If the code
 is not legal, it returns a value that signals this fact. */
double decode_char(char code)
{
	switch (code)
	{
	case 'B':
		return 0.0;
	case 'N':
		return 1.0;
	case 'R':
		return 2.0;
	case 'O':
		return 3.0;
	case 'Y':
		return 4.0;
	case 'G':
		return 5.0;
	case 'E':
		return 6.0;
	case 'V':
		return 7.0;
	case 'A':
		return 8.0;
	case 'W':
		return 9.0;

	/*Erweiterung durch Nikolai Ruilova am 15.12.2022 von hier...*/

	case 'S':
		return 10.0;
	case 'L':
		return 5.0;
	case '-':
		return 20.0;

	/*...bis hier, Erweiterung fuer die notwendigen Rueckgabewerte fuer die Berechnung des Toleranzbereiches*/

	default:
		return -999.0; /* illegal code */
	}
}