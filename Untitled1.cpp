//2. projekt Boris Èernák

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct nehnutelnost{
  char typ_neh [53];
  char miesto [53];
  char ulica [103];
  int rozloha;
  int cena;
  char popis [203];
  struct nehnutelnost *dalsi;	
} NEHNUTELNOST;

NEHNUTELNOST * n_funkcia(FILE *fr, NEHNUTELNOST *prvy){
  NEHNUTELNOST *akt, *pom2;
  int pocet=0;
  char znak[10], *pom;
  if(prvy!=NULL){
    akt=prvy;
	while(akt!=NULL){  //uvolnenie pamate ak zoznam existoval
	  pom2=akt;
      akt=akt->dalsi;
      free(pom2);	
	}
  	
  } 
