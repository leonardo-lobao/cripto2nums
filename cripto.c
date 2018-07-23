#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void criptografar();

int main( int argc, char *argv[ ]){	
	int i,x,y;
	for(i=0;i< argc;i++){
		x = strcmp( argv[i],"-c");
		y = strcmp( argv[i],"-d");
		if( x == 0 ){
			criptografar();
			break;
		}
		/*if( y == 0){
			descriptografar();
			break;
		}*/
	}
	return 0;
}

void pegachavecripto();

void criptografar(){
	char vetint[MAX]={'\0'};			
	
	while(fgets(vetint,MAX,stdin) != NULL){		
		pegachavecripto();		
	}	
}

void geradecomposto(int b,int vetdecomposto[]);

void pegachavecripto(){
	int vetdecomposto[MAX]={'\0'};
	int a=0,b=0;
	FILE *file;
	file = fopen("numcripto.txt" , "r");
	fscanf(file,"%d %d", &a,&b);
	fclose(file);
	geradecomposto(b,vetdecomposto);
	
}

void geradecomposto(int b,int vetdecomposto[]){
	
}
