#include <stdio.h>
#include <string.h>

#define MAX 100;

int main( int argc, char *argv[ ]){	
	int i,x,y;
	for(i=0;i< argc;i++){
		x = strcmp( argv[i],"-c");
		y = strcmp( argv[i],"-d")
		if( x == 0 ){
			criptografar();
			break;
		}
		if( y == 0){
			descriptografar();
			break;
		}
	}
	return 0;
}

void criptografar(){
	int vetint[MAX]={'\0'};	
	while(fgets(vetint,MAX,stdin) != NULL){
		
	}	
}
