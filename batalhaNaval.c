#include <stdio.h>
#include <stdlib.h>

void navios(int matriz[][10]){ //FUNCAO PARA CRIAR NAVIOS, FUNCAO RECEBE MATRIZ (PS É NECESSARIO COLOCAR O TAMANHO DE [][Y] NO PARAMETRO.
  
  int navio1[3] = {3, 3, 3}; //VETOR NAVIO 1
    int n1x = 2, n1y = 3; //Cordenadas em x e y;

  int navio2[3] = {3, 3, 3}; //VETOR NAVIO 2
    int n2x = 4, n2y = 2; //Cordenadas em x e y;
    
  int navio3[3] = {3, 3, 3}; //VETOR NAVIO 3
    int n3x = 7, n3y = 7; //Cordenadas em x e y;

  int navio4[3] = {3, 3, 3}; //VETOR NAVIO 4
    int n4x = 7, n4y = 4; //Cordenadas em x e y;
    

   //  ======================================
   //  "PINTANDO NAVIOS" : 
   //  ======================================

    for (int i = 0; i < 3; i++){
 
         matriz[n1x][n1y + i] = navio1[i];   //Posiciona o vetor navio dentro da matriz a partir da cordenada x e y;

    }

    for (int i = 0; i < 3; i++){

         matriz[n2x + i][n2y] = navio2[i]; 

    }
    
    for (int i = 0; i < 3; i++){
            
          matriz[n3x + i][n3y + i] = navio3[i];

    }

     for (int i = 0; i < 3; i++){

         matriz[n4x + i][n4y - i] = navio4[i]; 

    }
  
  
  

}

void tabuleiro(){
     
  int tabuleiro[10][10]; // Matriz 10x10;

//=====================================================
//         LOOP PARA PRENCHER A MATRIZ COM ZEROS E POSICIONAR NAVIOS ;
//=====================================================

      for (int x = 0; x < 10; x++){
         
         for (int y = 0; y < 10; y++){
         
            tabuleiro[x][y] = 0;
         }
      }

      navios(tabuleiro); //FUNCAO QUE CRIA OS NAVIOS E POSICIONA DENTRO DO TABULEIRO;

      //tabuleiro[2][3] = 3;

      //navios(tabuleiro[4][5], tabuleiro[4][5]);


//=====================================================
//         LOOP PARA PRINTAR O TABULEIRO : 
//=====================================================
  
 printf("\n\n\n\n\n\n\n ---- TABULEIRO BATALHA NAVAL ----\n");
 printf("\n   A  B  C  D  E  F  J  K  L  J \n");

  for (int x = 0; x < 10; x++){ // lOOP DE X
   

   //PRINTA OS NUMEROS LATERAIS DO TABULEIRO; OPERADOR TERNARIO ESTA SENDO USADO PARA TIRAR O ESPACAMENTO ENTRE O 10 E OS 0 :
   ((x + 1) < 10) ? printf("%d ", x + 1) : printf("%d", x + 1); 


    for (int y = 0; y < 10; y++){ // lOOP DE Y
     
   // PRINT DO VALOR EM [Y] DENTRO DE [X] OU SEJA : [X][Y] = "VALOR";
      printf(" %d ", tabuleiro[x][y]); 

    }

   printf("\n"); //QUEBRA LINHA A CADA VETOR[X]

  }
  printf("\n\n\n\n"); //LIBERAR ESPACO NO TERMINAL (AJUSTE VISUAL);

}



int main(){
 
  tabuleiro();

 return 0;

}

