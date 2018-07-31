#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define BITS 31  //a quantidade máxima possivel de bits da chave é 32 bits

void criptografar(int x);

int main( int argc, char *argv[ ]){	
	int i,x=1,y=1;
	for(i=0;i< argc;i++){
		x = strcmp( argv[i],"-c");
		y = strcmp( argv[i],"-d");
		if( x == 0 ){
			criptografar(x);
			break;
		}
		if( y == 0){
			criptografar(x);
			break;
		}
	}
	return 0;
}

int pega_valor_do_txt(int x,int vetdecomposto[]);

int gera_cripto_txt(int c,int a2,int vetdecomposto[]);

void criptografar(int x){
	int vetdecomposto[MAX]={'\0'};   //armazena a chave decomposta em partes
	int c,a2,vari;	
	FILE *file2,*file3;
		
	if(x==0){		      //testa se a operação a ser realizada é codificar 
		a2 = pega_valor_do_txt(x,vetdecomposto);
		file2 = fopen("saída.bin","w");	
		while((c = getchar()) != EOF ) {
			vari = gera_cripto_txt(c,a2,vetdecomposto);					
			fwrite(&vari, sizeof(int),1,file2);						
		}
		fclose(file2);	
	}
	else{              //decodifica
		a2 = pega_valor_do_txt(x,vetdecomposto);
		file2 = fopen("saída.bin","r");	
		file3 = fopen("decode.txt","w");
		fread(&c, sizeof(int),1,file2);		
			
		for(;;) {							
			if(feof(file2)){
				break;
			}				
			vari = gera_cripto_txt(c,a2,vetdecomposto);			
			fprintf(file3,"%c",vari);
			fread(&c, sizeof(int),1,file2);
		}
		fclose(file2);	
		fclose(file3);
	}
}

void preenche_decomposto(int b,int vetdecomposto[]);

int pega_valor_do_txt(int x,int vetdecomposto[]){	
	int a=0,b=0;	
	FILE *file;
	
	if(x==0){
		file = fopen("numcripto.txt" , "r");
		fscanf(file,"%d %d", &a,&b);
		fclose(file);	
		preenche_decomposto(b,vetdecomposto);
	}
	else{
		file = fopen("numdescripto.txt" , "r");
		fscanf(file,"%d %d", &a,&b);
		fclose(file);		
		preenche_decomposto(b,vetdecomposto);
	}
	
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
	int tam = 0,i,z,j=0,var=0,contador,ind;
	long long k=0;
	
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
		k = z;	
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
		k = ((k%a2) * (var%a2))%a2;		
	}
	var = k % a2;			//resultado desejado		
	return var;	
}

