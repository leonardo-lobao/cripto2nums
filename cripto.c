#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define BITS 31  //diz a quantidade máxima possivel de bits da chave

void criptografar();

int main( int argc, char *argv[ ]){	
	int i,x,y ;
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

int pega_valor_do_txt(int vetdecomposto[]);

void gera_cripto_txt(int c,int a2,int vetdecomposto[]);

void criptografar(){
	int vetdecomposto[MAX]={'\0'};
	int c,a2;		
			
	a2 = pega_valor_do_txt(vetdecomposto);	
	while((c = getchar()) != EOF ) {		
		gera_cripto_txt(c,a2,vetdecomposto);				
	}	
}

void preenche_decomposto(int b,int vetdecomposto[]);

int pega_valor_do_txt(int vetdecomposto[]){
	
	int a=0,b=0;	
	FILE *file;
	file = fopen("numcripto.txt" , "r");
	fscanf(file,"%d %d", &a,&b);
	fclose(file);	
	preenche_decomposto(b,vetdecomposto);
	
	return a;	
}

void preenche_decomposto(int b,int vetdecomposto[]){
	int vetbits[BITS+1] = {'\0'}; //armazena a chave em binário
	int x=0,i,cont=0,aux=1;    
	      
	for(i= BITS;i>=0;i--){
		x = b >> i;
		if(x != 0){
			if(x & 1) {
				vetbits[cont++] = 1;							
			} 
			else 
			{
				vetbits[cont++] = 0;					
			}
		}
    } 
    
    x=0; 
    
    for(i= cont -1 	; i > -1 ; i--){
		if(vetbits[i] == 1){
			vetdecomposto[x++] = aux;
			aux = 2*aux;
		}
		else if(vetbits[i] == 0){
			aux = 2*aux;			
		}
	}  	
}

void gera_cripto_txt(int c,int a2,int vetdecomposto[]){
	
}

