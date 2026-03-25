#include <stdio.h>
#include <stdlib.h>
#define tabuleiroX 10
#define tabuleiroY 10
#define tamanhoHX 3 //Tamanho da Matriz habilidade em X
#define tamanhoHY 5 //Tamanho da Matriz habilidade em Y
#define tamanhoN 3  //Tamanho da Matriz de Navios
#define numeroN 3  //Numero que Define os NAVIOS


//===========================================================
//    FUNCOES :
//===========================================================


void habilidades(int matriz[][10]){ //Funcao para criar as habilidades  
  //Matriz ja é um ponteiro nao necessita de *
  //Recebe Matriz e pinta a habilidade;

  int cone[tamanhoHX][tamanhoHY] = {{0, 0, 5, 0, 0},
                                    {0, 5, 5, 5, 0},
                                    {5, 5, 5, 5, 5},};

    //Posicao da Habilidade com relacao o tabuleiro em X e em Y 
    int ptOrigemConeX = 2;                         
    int ptOrigemConeY = 4;               
                                      

  int cruz[tamanhoHX][tamanhoHY] =  {{0, 0, 5, 0, 0},
                                      {5, 5, 5, 5, 5},
                                      {0, 0, 5, 0, 0},};
    
    int ptOrigemCruzX = 1;                         
    int ptOrigemCruzY = 0;      
                      

  int octaedro[tamanhoHX][tamanhoHY] = {{0, 0, 5, 0, 0},
                                        {0, 5, 5, 5, 0},
                                        {0, 0, 5, 0, 0},};

  int ptOrigemOctaedroX = 6;                         
  int ptOrigemOctaedroY = 6;      

  for (int x = 0; x < tamanhoHX; x++){ //LOOP QUE PERCORRRE X;

        for (int y = 0; y < tamanhoHY; y++){ // LOOP QUE PERCORRE Y;
       
        //Verifica se passa do tabuleiro em x ou em y :

        if ((ptOrigemConeX + tamanhoHX) > tabuleiroX || (ptOrigemConeY + tamanhoHY) > tabuleiroY) break;
        if ((ptOrigemCruzX + tamanhoHX) > tabuleiroX || (ptOrigemCruzY + tamanhoHY) > tabuleiroY) break;
        if ((ptOrigemOctaedroX + tamanhoHX) > tabuleiroX || (ptOrigemOctaedroY + tamanhoHY - 1) > tabuleiroY) break;
       
        //Verifica se origem é < 0
        if ((ptOrigemConeY < 0) || (ptOrigemConeX < 0)) break;
        if ((ptOrigemCruzY < 0) || (ptOrigemCruzX < 0)) break;
        if ((ptOrigemOctaedroY < 0) || (ptOrigemOctaedroX < 0)) break;
        

          matriz[ptOrigemConeX + x][ptOrigemConeY + y] = cone[x][y]; //Percorre a matriz utilizando o ponto de origem da habilidade + x do for, faz o mesmo com y;

          //"pinta" a habilidade percorrendo utilizando os mesmo 2 for que percorre a matriz.

          matriz[ptOrigemCruzX + x][ptOrigemCruzY + y] = cruz[x][y];

          matriz[ptOrigemOctaedroX + x][ptOrigemOctaedroY + y] = octaedro[x][y];

      }
  }
}

void navios(int matriz[][10]){ //FUNCAO PARA CRIAR NAVIOS, FUNCAO RECEBE MATRIZ (PS É NECESSARIO COLOCAR O TAMANHO DE [][Y] NO PARAMETRO.
  
  int navio1[tamanhoN] = {numeroN, numeroN, numeroN}; //VETOR NAVIO 1 Horizontal esquerda
    int n1x = 1, n1y = 6; //Cordenadas em x e y;

  int navio2[tamanhoN] = {numeroN, numeroN, numeroN}; //VETOR NAVIO 2  Horizontal esquerda
    int n2x = 4, n2y = 1; //Cordenadas em x e y;
    
  int navio3[tamanhoN] = {numeroN, numeroN, numeroN}; //VETOR NAVIO 3 Diagonal para direita
    int n3x = 7, n3y = 4; //Cordenadas em x e y;

  int navio4[tamanhoN] = {numeroN, numeroN, numeroN}; //VETOR NAVIO 4 Diagonal para esquerda
    int n4x = 6, n4y = 3; //Cordenadas em x e y;
    

//===========================================================
//  "PINTANDO NAVIOS" : 
//===========================================================

    for (int i = 0; i < tamanhoN; i++){
         
         //if verifica se tamanho + cordenada  < que tabuleiro.

         if (((n1x) < 0) || ((n1x) > tabuleiroX)) break; // Evita que passe do tabuleiro.

         if(((n1y + tamanhoN) > tabuleiroY) || ((n1y) < 0)) break; //Evita posicao invalida

         matriz[n1x][n1y + i] = navio1[i];   // incrementa somente em y
    
    }

    for (int i = 0; i < tamanhoN; i++){

          if (((n2x) < 0) || ((n2x + tamanhoN) > tabuleiroX)) break;
          if(((n2y) > tabuleiroY) || ((n2y) < 0)) break;     

         matriz[n2x + i][n2y] = navio2[i]; //SO CRESCE EM MATRIZ X
         

    }
    
    for (int i = 0; i < tamanhoN; i++){ 
       
         if (((n3x + tamanhoN) > tabuleiroX) || ((n3y + tamanhoN) > tabuleiroY)) break;
         if(((n3x) < 0) || ((n3y) < 0)) break;
         
        
          matriz[n3x + i][n3y + i] = navio3[i]; //incrementa em x e em y;

    }

     for (int i = 0; i < tamanhoN; i++){
        
          if (((n4x) < 0) || ((n4y) > tabuleiroY)) break;
          if(((n4x + tamanhoN) > tabuleiroX) || ((n4y - tamanhoN) < 0)) break;
        
          matriz[n4x + i][n4y - i] = navio4[i]; 

    }
  
  
  

}

void tabuleiro(){
     
  int tabuleiro[10][10]; // Matriz 10x10;

//=================================================================================
//         LOOP PARA PRENCHER A MATRIZ COM ZEROS E POSICIONAR NAVIOS ;
//=================================================================================

      for (int x = 0; x < tabuleiroX; x++){
         
         for (int y = 0; y < tabuleiroY; y++){
         
            tabuleiro[x][y] = 0;
         }
      }

//=====================================================
//         Chamada das Funcoes : 
//=====================================================

     navios(tabuleiro); //FUNCAO QUE CRIA OS NAVIOS E POSICIONA DENTRO DO TABULEIRO;
       
     habilidades(tabuleiro); //FUNCAO PARA PINTAR HABILIDADES NO TABULEIRO;


//==============================================================
//         LOOP PARA PRINTAR O TABULEIRO : 
//==============================================================
  
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
  
  //CHAMA A FUNCAO TABULEIRO NO LOOP PRINCIPAL : 
  tabuleiro();
  

 return 0;

}

