#include <stdio.h>
#include <stdlib.h>
  
FILE *arquivo;

void editarArquivo(){

	int number,i, j, matriz[2][2]; //Matriz 2x2.
			
	//Lendo a matriz antiga
	arquivo = fopen("arquivo.txt","rt");

		while(!feof(arquivo)){
	
			for (i=0; i<2; i++) {
			    for (j=0; j<2; j++) {
		   			 fscanf(arquivo, "%d \n",&number);     		
					 matriz[i][j] = number;       
   				}
  			}	
	
    	}
	
	fclose(arquivo);	
	
	//Modificando a matriz
	arquivo = fopen("arquivo.txt","w");

	matriz[0][0] = 55;
	
	for (i=0; i<2; i++) {
		    for (j=0; j<2; j++) {
   			 fprintf(arquivo, "%d ",matriz[i][j]);    			
			}
			fprintf(arquivo,"\n");	
  	}
   
	fclose(arquivo);
	
	// Print da matriz modificada
	printf("\n\n*** MATRIZ MODIFICADA ***");	
	consultarArquivo();
		
}

void consultarArquivo(){
	
	int number,i, j, matriz[2][2]; //Matriz 2x2.

	
	arquivo = fopen("arquivo.txt","rt");


		printf("\n==============MATRIZ 2x2==============\n");	    		
		while(!feof(arquivo)){

		
		for (i=0; i<2; i++) {
		    for (j=0; j<2; j++) {

   			 fscanf(arquivo, "%d \n",&number);     		
			 matriz[i][j] = number;
       
   			}
  		}	
	
    	}

	
  for (i=0; i<2; i++) {
    for (j=0; j<2; j++) {
     printf("%d ", matriz[i][j]);   
   }  
	printf("\n");	 
	 }
    printf("\n");
	
	fclose(arquivo);
}


int main() {

int opcao;
    
    do{
        
        printf("\n\nEscolha uma opcao: \n\n1)Editar arquivo\n2)Consultar\n3)Sair\n");
        scanf("%d",&opcao);
        
        switch(opcao){
            case 1: 
                editarArquivo();                
				break;
            case 2: 
                consultarArquivo();
                break;
            case 3:
                return 0;
            }
        
        }while(1==1);	
}
