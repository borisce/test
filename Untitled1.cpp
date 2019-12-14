//2. projekt Boris �ern�k

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
  if((fr = fopen("reality.txt", "r")) == NULL)
    printf("Zaznamy neboli nacitane\n");
  else{
    fgets(znak, 10, fr);
	while(znak[0]=='&'){ 
      	pocet+=1;
        if(pocet==1){  //nacitanie 1. prvku zoznamu
		  prvy = (NEHNUTELNOST *) malloc(sizeof(NEHNUTELNOST));
		  fgets(prvy->typ_neh, 53, fr);
		  fgets(prvy->miesto, 53, fr);
		  fgets(prvy->ulica, 103, fr);
		  fscanf(fr, "%d ", &(prvy->rozloha));
		  fscanf(fr, "%d ", &(prvy->cena));
		  fgets(prvy->popis, 203, fr);
		  akt=prvy;
		  akt->dalsi=NULL;
	   }
	   else{  //nacitanie ostatnych prvkov zoznamu
	      akt->dalsi = (NEHNUTELNOST *) malloc(sizeof(NEHNUTELNOST));
		  akt=akt->dalsi;
		  fgets(akt->typ_neh, 50, fr);
		  fgets(akt->miesto, 50, fr);
		  fgets(akt->ulica, 100, fr);
     	  fscanf(fr, "%d ", &(akt->rozloha));
		  fscanf(fr, "%d ", &(akt->cena));
		  fgets(akt->popis, 200, fr);
		  akt->dalsi=NULL;	
	   }
	   pom=fgets(znak, 10, fr);
	   if(pom==NULL)
	    break;

   }
  }
  printf("Nacitalo sa %d zaznamov\n", pocet);
  return prvy;
}
void v_funkcia(NEHNUTELNOST *f_prvy){  //vypis prvkov zoznamu
  NEHNUTELNOST *akt;
  int pocet=1;
  akt=f_prvy;
  if(f_prvy==NULL)
  return;
  while(akt!=NULL){
    printf("%d.\n", pocet);
    printf("kategoria ponuky: %s", akt->typ_neh);
    printf("miesto ponuky: %s", akt->miesto);
	printf("ulica: %s", akt->ulica);
	printf("rozloha v m2: %d\n", akt->rozloha);
	printf("cena: %d\n", akt->cena);
	printf("popis: %s", akt->popis);
	pocet+=1;
	akt=akt->dalsi;	
 }
}
NEHNUTELNOST * p_funkcia(NEHNUTELNOST *f_prvy){
  NEHNUTELNOST *akt, *pom1,*vlozeny;
  int pocet=1, index;
  char koniec='\n';
  vlozeny = (NEHNUTELNOST *) malloc(sizeof(NEHNUTELNOST)); 
  scanf("%d\n", &index);
  gets(vlozeny->typ_neh); //nacitanie vlozeneho prvku z konzoly
  gets(vlozeny->miesto);
  gets(vlozeny->ulica);
  scanf("%d\n", &vlozeny->rozloha);
  scanf("%d\n", &vlozeny->cena);
  gets(vlozeny->popis);
  strncat(vlozeny->typ_neh, &koniec, 1);
  strncat(vlozeny->miesto, &koniec, 1);
  strncat(vlozeny->ulica, &koniec, 1);
  strncat(vlozeny->popis, &koniec, 1);
  vlozeny->dalsi=NULL;
  if(f_prvy==NULL){
    f_prvy=vlozeny;
    return f_prvy;  
  }
  else{
    akt=f_prvy;	  
    while(akt!=NULL){
	  if(index==1){
	  	vlozeny->dalsi=f_prvy;
	  	f_prvy=vlozeny;
	  	return f_prvy;  	
	  }
	  if(pocet==(index-1)){
	    pom1=akt->dalsi;
	    akt->dalsi=vlozeny;
		vlozeny->dalsi=pom1;
		return f_prvy;
	  }
	  if(index>=pocet && akt->dalsi==NULL){
        akt->dalsi=vlozeny;  
        return f_prvy;
      }
	  pocet++;
	  akt=akt->dalsi;		
	}     
  }
}

NEHNUTELNOST * z_funkcia(NEHNUTELNOST *f_prvy){
  NEHNUTELNOST *akt, *pom1, *pom2;
  char zmazmiesto[53], miestovelke[53], prazdny;
  int i,pocet=0, kontrola;
  scanf("%s", &zmazmiesto);
  for(i=0;i<strlen(zmazmiesto);i++)
    zmazmiesto[i]=toupper(zmazmiesto[i]);     
  akt=f_prvy;
  while(akt!=NULL){  //hladanie zadaneho retazca v miestach ponuky pre jednotlive zaznamy
  	kontrola=0;
	for(i=0;i<strlen(akt->miesto);i++)
        miestovelke[i]=toupper(akt->miesto[i]); 	  
	if((strstr(miestovelke, zmazmiesto))!=NULL){
      pocet++;
      if(akt==f_prvy){
      	f_prvy=akt->dalsi;
      	free(akt);
      }
      else{
	    if(akt->dalsi==NULL){
	      pom1->dalsi=NULL;	
	      free(akt);	
	    }
		else{
		  pom2=akt->dalsi;
		  pom1->dalsi=pom2;
		  free(akt);
		  akt=pom1->dalsi;
		  kontrola=1;	
		}	 	
	  }  
   }
    if(kontrola==0){
	  pom1=akt;
	  akt=akt->dalsi;
	}
	for(i=0;i<53;i++)
      miestovelke[i]=prazdny;	
 }
  printf("Vymazalo sa %d zaznamov\n", pocet);
  return f_prvy;

}

