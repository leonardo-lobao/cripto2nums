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
	int i;		
	
	while(fgets(vetint,MAX,stdin) != NULL){
		for(i=0;i<MAX;i++){
			if(vetint[i] !=0 && vetint[i] != '\0'){
				printf("%d ",vetint[i]);
			}
		}
		//pegachavecripto();		
	}	
}

void pegachavecripto(){
	int a=0,b=0;
	FILE *file;
	file = fopen("numcripto.txt" , "r");
	fscanf(file,"%d %d", &a,&b);
	fclose(file);
	
}
