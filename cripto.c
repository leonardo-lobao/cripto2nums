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

int gera_cripto_txt(int c,int a2,int vetdecomposto[]);

void gera_saida_txt(int vari);

void criptografar(){
	int vetdecomposto[MAX]={'\0'};   //armazena a chave decomposta em partes
	int c,a2,vari;		
			
	a2 = pega_valor_do_txt(vetdecomposto);	
	while((c = getchar()) != EOF ) {
		if( c !=10){		//retira o \n
			vari = gera_cripto_txt(c,a2,vetdecomposto);	
			gera_saida_txt(vari);
	    }			
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
	      
	for(i= BITS;i>=0;i--){         //preenchendo vetor com binário
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
    
    for(i= cont -1 	; i > -1 ; i--){   //preenchendo vetor com as partes decompostas
		if(vetbits[i] == 1){
			vetdecomposto[x++] = aux;   
			aux = 2*aux;
		}
		else if(vetbits[i] == 0){
			aux = 2*aux;			
		}
	}  	
}

int gera_cripto_txt(int c,int a2,int vetdecomposto[]){
	int vet2[MAX]= {'\0'};	
	int tam = 0,i,z,j=0,var=0,contador,ind,k=0;
	
	while ( (i=vetdecomposto[tam]) != '\0'){   //para descobrir quantos elementos tem em vet1
		tam++;
	}			
	z= c%a2;
	for(i=0;i<tam;i++){       //prenche o vet2 com as partes da conta final
		contador = 0 ;
		if( vetdecomposto[i] ==1){
			vet2[j++] = z;			
			continue;
		}
		var = vetdecomposto[i];
		while(var != 1){
			var = var/2;
			contador++;
		}		
		k= z;	
		for(ind=0;ind<contador;ind++){
			k = (k*k)%a2;
		}
		vet2[j++] = k;		
	}                        // vet2 preenchido
	for (i=0;i<tam;i++){	 //multiplica as partes da conta para obter o resultado desejado
		if(tam==1){
			k = vet2[i];
			break;
		}
		if(i==0){
			var = vet2[i];
			z = vet2[i+1];
			k = var * z;
			i = 1;
			continue;
		}
		if(tam==2){
			break;
		}
		var = vet2[i];
		k = k * var;
	}
	var = k % a2;			//resultado desejado
	return var;
}

void gera_saida_txt(int vari){   //gera o arquivo saida.txt
	FILE *file2;
	
	file2 = fopen("saída.txt","a");
	fprintf(file2,"%d ",vari);
	fclose(file2);
	
	
}

