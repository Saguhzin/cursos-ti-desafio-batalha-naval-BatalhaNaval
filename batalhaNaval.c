#include <stdio.h>
#include <stdlib.h>

void navios(int matriz[][10]){ //FUNCAO PARA CRIAR NAVIOS, FUNCAO RECEBE MATRIZ (PS É NECESSARIO COLOCAR O TAMANHO DE [][Y] NO PARAMETRO.
  
  int navio1[3] = {3, 3, 3}; //VETOR NAVIO 1
    int n1x = 1, n1y = 3; //Cordenadas em x e y;

  int navio2[3] = {3, 3, 3}; //VETOR NAVIO 2
    int n2x = 4, n2y = 1; //Cordenadas em x e y;
    
  int navio3[3] = {3, 3, 3}; //VETOR NAVIO 3 Horizontal para direita
    int n3x = 7, n3y = 7; //Cordenadas em x e y;

  int navio4[3] = {3, 3, 3}; //VETOR NAVIO 4 Horizontal para esquerda
    int n4x = 6, n4y = 4; //Cordenadas em x e y;

  int tamanhoNavios = 3; //A posicao começa a partir do 1 - 3 entao tiro 1 para ajustar na verificacao;
    

   //  ======================================
   //  "PINTANDO NAVIOS" : 
   //  ======================================

    for (int i = 0; i < 3; i++){ //Percorrer o tamanho do navio e usar as cordenadas dadas anteriormente
         
         //if verifica se tamanho + cordenada = < que tabuleiro.
         if (((n1x) < 11) && ((n1y + tamanhoNavios) < 11) && ((n1x) >= 0) && ((n1y + tamanhoNavios) >= 0)) 
         matriz[n1x][n1y + i] = navio1[i];   //Posiciona o vetor navio dentro da matriz a partir da cordenada x e y;
         //+y = direita, -y = esquerda
         //+x = baixo, -x = cima

    }

    for (int i = 0; i < 3; i++){
         
         if (((n2x + tamanhoNavios) < 11) && ((n2y) < 11) && ((n2x + tamanhoNavios) > 0) && ((n2y) > 0)) //So pinta o navio caso n passe o tamanho da matriz 
         matriz[n2x + i][n2y] = navio2[i]; 
         

    }
    
    for (int i = 0; i < 3; i++){ 

          if (((n3x + tamanhoNavios) < 11) && ((n3y + tamanhoNavios) < 11) && ((n3x + tamanhoNavios) > 0) && ((n3y + tamanhoNavios) > 0))
          matriz[n3x + i][n3y + i] = navio3[i]; //incrementa em x e em y;

    }

     for (int i = 0; i < 3; i++){

        if (((n4x + tamanhoNavios) < 11) && ((n4y - tamanhoNavios) < 11) && ((n4x + tamanhoNavios) > 0) && ((n4y - tamanhoNavios) > 0))
         matriz[n4x + i][n4y - i] = navio4[i]; 

    }
  
  
  

}

void tabuleiro(){
     
  int tabuleiro[10][10]; // Matriz 10x10;

//=================================================================================
//         LOOP PARA PRENCHER A MATRIZ COM ZEROS E POSICIONAR NAVIOS ;
//=================================================================================

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

