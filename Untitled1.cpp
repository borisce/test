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
