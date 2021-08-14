#include "route-records.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

RouteRecord* createRecords(FILE* fileIn){
  char buffer[200];
  int count = 0;
  RouteRecord *record = NULL; 
  fgets(buffer,100,fileIn);

  /*** Find length of file ***/
  while(fgets(buffer, 100, fileIn) != NULL){
    count = count + 1;
  }

  record = (RouteRecord*)malloc(count * sizeof(RouteRecord));

  /*** sets Passenger count to 0 ***/
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < count; j++){
      record[j].paxCount[i] = 0; 
    }
  }

/*** Rewind File ***/
rewind(fileIn);
return record;
}

int fillRecords( RouteRecord* r, FILE* fileIn ){

  char originFound[4];
  char destinationFound[4];
  char airlineFound[4];
  int month;
  int curIndex = 0;
  int i = 1;
  int paxCount;
  char buffer[100];
  char type[20];
  fgets(buffer, 100, fileIn);
  

  while(fgets(buffer, 100, fileIn) != NULL){
    
    sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%d", &month, originFound, 
    destinationFound, airlineFound, type, &paxCount);
    
    if(strlen(airlineFound) < 3){
       curIndex = findAirlineRoute(r, i, originFound, destinationFound, airlineFound, 0);
       
       if(curIndex == -1){
         strcpy(r[i].origin, originFound);
         strcpy(r[i].destination, destinationFound);
         strcpy(r[i].airline, airlineFound);
         r[i].paxCount[month - 1] = paxCount;
       }
       
       else{
         r[curIndex].paxCount[month - 1] = paxCount;
       }
       i++;
    }
  }
  return i;
}

/*** recursion item found ***/
int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx){
  if(curIdx == length){
    return -1;
}
  if(strcmp(r[curIdx].origin, origin) == 0 && strcmp(r[curIdx].destination, destination) == 0 && 
    strcmp(r[curIdx].airline, airline) == 0){

    return curIdx;
  }
  return findAirlineRoute(r,length, origin, destination, airline, curIdx + 1);
}


void searchRecords( RouteRecord* r, int length, const char* key1, const char* key2, SearchType st ){
  int found = 0;
  int month[6] = {0,0,0,0,0,0};
  int total = 0;
  int count = 0;

 for(int i = 0; i < length; i++){
    
    if(st == ORIGIN){
      
      if(strcmp(r[i].origin, key1) == 0){
        printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
        
        for(int j = 0; j < 6; j++){
          month[j] += r[i].paxCount[j];
          total += r[i].paxCount[j];
        }

        found++;   
    }
  }
    else if(st == DESTINATION){
      
      if(strcmp(r[i].destination, key1) == 0){
        printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);

          for(int j = 0; j < 6; j++){
            month[j] += r[i].paxCount[j];
            total += r[i].paxCount[j];
          }
        found++;
      }
    }
    else if(st == AIRLINE){

      if(strcmp(r[i].airline, key1) == 0){
        printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
          
          for(int j = 0; j < 6; j++){
            month[j] += r[i].paxCount[j];
            total += r[i].paxCount[j];
          }
        found++;
      }
    }
    else{
      
      if(strcmp(r[i].origin, key1) == 0 && (strcmp(r[i].destination, key2) == 0)){
        printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
          
          for(int j = 0; j < 6; j++){
            month[j] += r[i].paxCount[j];
            total += r[i].paxCount[j];
        }
        found++;
      }
    }
  } 

  printf("\n%d matches were found.\n\n", found);
  
  /*** Statistics ***/
  printf("Statistics\n");
  printf("Total Passengers: %d\n", total);
  
  for(int k = 0; k < 6; k++){
    printf("Total Passengers in Month %d: %d\n",k + 1, month[k]);
  }
  printf("\n\nAverage Passengers per Month: %.lf\n", total / 6.0);
}


void printMenu(){
printf( "\n\n######### Airline Route Records Database MENU #########\n" );
printf( "1. Search by Route\n" );
printf( "2. Search by Origin Airport\n" );
printf( "3. Search by Destination Airport\n" );
printf( "4. Search by Airline\n" );
printf( "5. Quit\n" );
printf( "Enter your selection: " );
}


void upperCaseConversion(char key[]){
   for(int j = 0; j < strlen(key); j++){
    key[j] = toupper(key[j]);
  }
} 