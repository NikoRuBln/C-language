#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    //List should run cycles to take all the info and store it into an array
    
    
    struct Names {
        char Name[20];
        int Age[3];
    }Info[100];
    
    int ContactsCount = 0;
    int choice = 0;
    printf("\n\t\t\tContact List\n\n");
   
   printf("Current amount of contacts:%d", ContactsCount);
   printf("\nContacts:\n\n");

   printf("Options:\n\t(1)Add New contact\n\t(2)Close Programm\n\tInput:");
   scanf("%i", &choice);
   
   if (choice >= 2)
   {
        printf("\nProgramm ended successfully\n");


    return 0;
   }
   
   
    //Input

    for (int i = 0; 1 < 102; i++)
    {
        char rep = 'y';
    printf("\tPlease Input your Name:");
    fgets((Info[i].Name), 20, stdin);
    printf("\n\tPlease Input your Age:");
    fgets((Info[i]).Age, 3 , stdin);

    //Add amount of contacts
    ContactsCount ++;

    //Ask for another Contact
    printf("\n\tDo you want to input Another contact?");
    rep = getchar();
    if (rep != 'y')
     {

        break;
     }
    }

    printf("\nProgramm ended successfully\n");


    return 0;
}