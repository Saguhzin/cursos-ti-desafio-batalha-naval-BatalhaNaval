#include <stdio.h>
#include <stdlib.h>

void navios(int matriz[][10]){ //FUNCAO PARA CRIAR NAVIOS, FUNCAO RECEBE MATRIZ (PS É NECESSARIO COLOCAR O TAMANHO DE [][Y] NO PARAMETRO.
  
  int navio1[3] = {3, 3, 3}; //VETOR NAVIO 1
  int navio2[3] = {3, 3, 3}; //VETOR NAVIO 2

  
    for (int y = 0; y < 3; y++){
 
         matriz[2][3 + y] = navio1[y];   //Posiciona o vetor navio dentro da matriz a partir de [2]x Linha

    }

    for (int y = 0; y < 3; y++){

         matriz[4 + y][2] = navio2[y]; //Posiciona o vetor navio dentro da matriz a partir de [2]y coluna

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

