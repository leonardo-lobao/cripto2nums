#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int testeprimo(char num1[],char num2[]);
int numscripto(char num1[],char num2[]);
void numsdescripto(int chave,char num1[],char num2[]);

int main(){
	char num1[MAX] = {'\0'};
	char num2[MAX] = {'\0'};
	int chave;	
	
	printf("Ensira o primeiro número primo: ");
	fgets(num1,MAX,stdin);
	printf("Ensira o segundo número primo: ");
	fgets(num2,MAX,stdin);
	
	if(testeprimo(num1,num2)){
		chave = numscripto(num1,num2);	
		numsdescripto(chave,num1,num2);
	}
	else{
		printf("Erro o número inserido não é primo!!!! \n");
	}
	
	return 0;
}

int testeprimo(char num1[],char num2[]){   //testa se é primo
	int i, x=0, z=0,div1=0,div2=0;
	
	x = atoi(num1);
	z = atoi(num2);
	for (i = 1; i <= x; i++) {
		if (x % i == 0) { 
			div1++;
		}
	}
	for (i = 1; i <= z; i++) {
		if (z % i == 0) { 
			div2++;
		}
	}
	if (div1 ==2 && div2==2){
		return 1; //retorna 1 se for primo
	}
	else{
		return 0; //retorna 0 se não for primo
	}
}

void numsdescripto(int chave,char num1[],char num2[]){
	int chaveprivada = 0,y = 0,numero1=0,numero2=0;
	FILE *file2;
	
	numero1 = atoi(num1);
	numero2 = atoi(num2);
	y = (numero1 -1) * (numero2 -1);
	while( (5*chaveprivada)% y != 1){		
			chaveprivada++;		
	}
	file2 = fopen("numdescripto.txt","w");
	fprintf(file2,"%d  %d",chave,chaveprivada);
	fclose(file2);
}

int achachave2(int numero1, int numero2);

int numscripto(char num1[],char num2[]){
	int numero1,numero2,chave1,chave2;
	FILE *file;
	
	numero1 = atoi(num1);
	numero2 = atoi(num2);
	chave1 = numero1 * numero2;
	chave2 = achachave2(numero1,numero2);
	file = fopen("numcripto.txt","w");
	fprintf(file,"%d  %d",chave1,chave2);
	fclose(file);
		
	return chave1;
}

int fatorar(int y);

int achachave2(int numero1, int numero2){
	int y=0,key=0;	
	
	y = (numero1 -1) * (numero2 -1);
	key = fatorar(y);	
	
	return key;
}

int fatorar(int y){  //gera um vetor com a fatoracao do numero y	
	int vetfatoracao[MAX] = {'\0'};
	int x=0,i=0,segundachave,w=2,tam=0;
	
	x = y;	
	while( x != 1){			
		if( x%w == 0){
			x = x/w;
			vetfatoracao[tam++] = w;						
		}
		else{
			w++;
		}	
	}
	w=2;
	while(i<tam){
		if(w%vetfatoracao[i] == 0){
			w++;
			i=0;
		}
		else if(w%vetfatoracao[i] != 0 && i == (tam-1)){
			segundachave = w;
			i++;			
		}
		else if(w%vetfatoracao[i] != 0){
			i++;
		}
	}
		
	return segundachave;	
}

