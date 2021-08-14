#include <stdio.h>
#include "route-records.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  char key1[MAX_KEY_LENGTH];
  char key2[MAX_KEY_LENGTH];
  char c;
  SearchType type;
  int length;
  char input;
  RouteRecord *record = NULL;
  FILE *fileIn = NULL;

  fileIn = fopen("data.csv", "r");
  if(fileIn == NULL){
    printf("ERROR: Could not open file");
    return -1;
  }

    record = createRecords(fileIn);
    length = fillRecords(record, fileIn); 
    fclose(fileIn);

    while(input != 53){

      printMenu();
      scanf(" %c", &input);
            while( (c =getchar())!='\n' && c !=EOF );


      if(input < 48 && input > 53) {
        printf("invalid choice\n");
        printMenu();
        scanf(" %c", &input);
              while( (c =getchar())!='\n' && c !=EOF );

      }
      

      switch(input){

         case 49:
         type = ROUTE;

         printf("Enter origin: ");
         fgets(key1, MAX_KEY_LENGTH, stdin);
         key1[strcspn(key1, "\n")] = 0;
         upperCaseConversion(key1);
         while( (c =getchar())!='\n' && c !=EOF );
         
         printf("Enter destination: ");
         fgets(key2, MAX_KEY_LENGTH, stdin);
         key2[strcspn(key2, "\n")] = 0;
         upperCaseConversion(key2);
         printf("\nSearching by route...\n");
         searchRecords(record, length, key1, key2, type);
         break;

         case 50:
         type = ORIGIN;

         printf("Enter origin: ");
         fgets(key1, MAX_KEY_LENGTH, stdin);
         key1[strcspn(key1, "\n")] = 0;
         upperCaseConversion(key1);
         printf("\nSearching by origin...\n");
         searchRecords(record, length, key1, key2, type);
         break;

         case 51:
         type = DESTINATION;

         printf("Enter the destination: ");
         fgets(key1, MAX_KEY_LENGTH, stdin);
         key1[strcspn(key1, "\n")] = 0;
         upperCaseConversion(key1);
         printf("\nSearching by destination...\n");
         searchRecords(record, length, key1, key2, type);
         break;

         case 52:
         type = AIRLINE;

         printf("Entere the airline: ");
         fgets(key1, MAX_KEY_LENGTH, stdin);
         key1[strcspn(key1, "\n")] = 0;
         upperCaseConversion(key1);
         printf("\nSearching by airline...\n");
         searchRecords(record, length, key1, key2, type);
         break;
        
         case 53:

         free(record);
         printf("Good-bye!\n");
         break;
      }
    }
    return 0;
}
