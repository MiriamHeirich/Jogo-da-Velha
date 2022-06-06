#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>



void voce_joga(char Mat[3][3]) {
 int L,C;
    do {

      printf("Informe linha e coluna: (entre 0 e 2): ");
      scanf("%d %d",&L,&C);

      }
     // while(L<1 || L>3 || C<1 || C>3 || Mat[L-1][C-1]!=' ');
      while(L<0 || L>2 || C<0 || C>2 || Mat[L][C]!=' '); // entre 0 e 2

     // Mat[L-1][C-1]='x';
       Mat[L][C]='x';
}

void mostrar_matriz(char x[3][3]){

    printf(" %c | %c | %c ",x[0][0],x[0][1],x[0][2]);
           printf("\n-----------\n");
     printf(" %c | %c | %c ",x[1][0],x[1][1],x[1][2]);
          printf("\n-----------\n");
     printf(" %c | %c | %c ",x[2][0],x[2][1],x[2][2]);
}

void computador_joga(char Mat[3][3]) {

     int i,j,conta=0,k=0,v=0,w=0;

      for(i=0;i<3;i++) {
         for(j=0;j<3;j++) { if(Mat[i][j]==' ')  conta=conta+1; }
      }

      switch(conta) {

         case 8: {
               // primeira jogada aleatória
                 do {

                srand(time(NULL));
                 v=rand()%3;
                 w=rand()%3;

                 if(Mat[v][w]==' ') { Mat[v][w]='o'; k=1; }

                 } while(k==0); return;

         }
         case 6: {
           if(Mat[1][1]=='x' && Mat[2][2]=='x' && Mat[0][0]=='o') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[0][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; } // linhas defesa direita
           if(Mat[1][0]=='x' && Mat[1][1]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[0][2]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; } // linhas defesa meio
           if(Mat[1][0]=='x' && Mat[1][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][2]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }

           if(Mat[0][1]=='x' && Mat[0][2]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // linhas defesa esquerda
           if(Mat[1][1]=='x' && Mat[1][2]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; }
           if(Mat[2][1]=='x' && Mat[2][2]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }


           if(Mat[0][0]=='x' && Mat[1][0]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; } // colunas defesa baixo
           if(Mat[0][1]=='x' && Mat[1][1]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[1][2]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[2][0]=='x' && Mat[1][0]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // colunas defesa cima
           if(Mat[2][1]=='x' && Mat[1][1]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][2]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[2][0]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; } // colunas defesa linha 0 e 2
           if(Mat[0][1]=='x' && Mat[2][1]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[2][2]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; } // diagonais defesa
           if(Mat[0][2]=='x' && Mat[1][1]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }
           if(Mat[0][0]=='x' && Mat[2][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[0][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][1]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; }
           if(Mat[2][0]=='x' && Mat[1][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][2]=='x' && Mat[2][2]=='o') { Mat[2][0]='o'; return; }
           if(Mat[0][1]=='x' && Mat[2][0]=='x' && Mat[0][0]=='o') { Mat[2][1]='o'; return; }
           if(Mat[0][1]=='x' && Mat[1][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }  // ataque
           if(Mat[0][1]=='x' && Mat[1][0]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][1]=='x' && Mat[2][2]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }
           if(Mat[0][2]=='x' && Mat[1][0]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][0]=='x' && Mat[1][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][0]=='x' && Mat[0][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][0]=='x' && Mat[2][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }
           if(Mat[0][2]=='x' && Mat[2][1]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }

         }
         case 4: {
           if(Mat[0][0]=='x' && Mat[1][2]=='x' && Mat[2][2]=='o' && Mat[2][1]=='x' && Mat[2][0]=='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='o' && Mat[2][1]=='x' && Mat[2][2]=='x' && Mat[0][0]=='o' && Mat[1][0]=='x') { Mat[1][1]='o'; return; }
           if(Mat[0][0]=='o' && Mat[0][2]=='x' && Mat[1][0]=='x' && Mat[2][0]=='o' && Mat[2][1]=='x') { Mat[1][1]='o'; return; }
           if(Mat[0][0]=='o' && Mat[0][1]=='x' && Mat[1][2]=='x' && Mat[2][2]=='x') { Mat[0][2]='o'; return; }
           if(Mat[1][2]=='x' && Mat[2][2]=='x' && Mat[0][1]=='x') { Mat[2][0]='o'; return; }


           if(Mat[0][0]=='o' && Mat[0][1]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; } // ataque linha 00
           if(Mat[0][0]=='o' && Mat[0][2]=='o' && Mat[0][1]!='x') { Mat[0][1]='o'; return; }
           if(Mat[0][1]=='o' && Mat[0][2]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }

           if(Mat[1][0]=='o' && Mat[1][1]=='o' && Mat[1][2]!='x') { Mat[1][2]='o'; return; } // ataque linha 01
           if(Mat[1][0]=='o' && Mat[1][2]=='o' && Mat[1][1]!='x') { Mat[1][1]='o'; return; }
           if(Mat[1][1]=='o' && Mat[1][2]=='o' && Mat[1][0]!='x') { Mat[1][0]='o'; return; }

           if(Mat[2][0]=='o' && Mat[2][1]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque linha 02
           if(Mat[2][0]=='o' && Mat[2][2]=='o' && Mat[2][1]!='x') { Mat[2][1]='o'; return; }
           if(Mat[2][1]=='o' && Mat[2][2]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; }

           if(Mat[0][0]=='o' && Mat[1][0]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; } // ataque coluna 00
           if(Mat[0][0]=='o' && Mat[2][0]=='o' && Mat[1][0]!='x') { Mat[1][0]='o'; return; }
           if(Mat[2][0]=='o' && Mat[1][0]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }

           if(Mat[0][1]=='o' && Mat[1][1]=='o' && Mat[2][1]!='x') { Mat[2][1]='o'; return; } // ataque coluna 01
           if(Mat[0][1]=='o' && Mat[2][1]=='o' && Mat[1][1]!='x') { Mat[1][1]='o'; return; }
           if(Mat[2][1]=='o' && Mat[1][1]=='o' && Mat[0][1]!='x') { Mat[0][1]='o'; return; }

           if(Mat[0][2]=='o' && Mat[1][2]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque coluna 02
           if(Mat[0][2]=='o' && Mat[2][2]=='o' && Mat[1][2]!='x') { Mat[1][2]='o'; return; }
           if(Mat[2][2]=='o' && Mat[1][2]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='o' && Mat[1][1]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque diagonais
           if(Mat[2][0]=='o' && Mat[1][1]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; }
           if(Mat[2][2]=='o' && Mat[1][1]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }
           if(Mat[0][2]=='o' && Mat[1][1]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; }


           if(Mat[0][0]=='x' && Mat[0][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; } // linhas defesa direita
           if(Mat[1][0]=='x' && Mat[1][1]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[0][1]=='x' && Mat[0][2]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // linhas defesa esquerda
           if(Mat[1][1]=='x' && Mat[1][2]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; }
           if(Mat[2][1]=='x' && Mat[2][2]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }

           if(Mat[0][0]=='x' && Mat[0][2]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; } // linhas defesa meio
           if(Mat[1][0]=='x' && Mat[1][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][2]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][0]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; } // colunas defesa baixo
           if(Mat[0][1]=='x' && Mat[1][1]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[1][2]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[2][0]=='x' && Mat[1][0]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // colunas defesa cima
           if(Mat[2][1]=='x' && Mat[1][1]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][2]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[2][0]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; } // colunas defesa linha 0 e 2
           if(Mat[0][1]=='x' && Mat[2][1]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[2][2]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; } // diagonais defesa
           if(Mat[0][2]=='x' && Mat[1][1]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }
           if(Mat[0][0]=='x' && Mat[2][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[0][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][1]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; }
           if(Mat[2][0]=='x' && Mat[1][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }


         }
         case 2: {
           if(Mat[0][0]=='o' && Mat[0][1]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; } // ataque linha 00
           if(Mat[0][0]=='o' && Mat[0][2]=='o' && Mat[0][1]!='x') { Mat[0][1]='o'; return; }
           if(Mat[0][1]=='o' && Mat[0][2]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }

           if(Mat[1][0]=='o' && Mat[1][1]=='o' && Mat[1][2]!='x') { Mat[1][2]='o'; return; } // ataque linha 01
           if(Mat[1][0]=='o' && Mat[1][2]=='o' && Mat[1][1]!='x') { Mat[1][1]='o'; return; }
           if(Mat[1][1]=='o' && Mat[1][2]=='o' && Mat[1][0]!='x') { Mat[1][0]='o'; return; }

           if(Mat[2][0]=='o' && Mat[2][1]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque linha 02
           if(Mat[2][0]=='o' && Mat[2][2]=='o' && Mat[2][1]!='x') { Mat[2][1]='o'; return; }
           if(Mat[2][1]=='o' && Mat[2][2]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; }

           if(Mat[0][0]=='o' && Mat[1][0]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; } // ataque coluna 00
           if(Mat[0][0]=='o' && Mat[2][0]=='o' && Mat[1][0]!='x') { Mat[1][0]='o'; return; }
           if(Mat[2][0]=='o' && Mat[1][0]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }

           if(Mat[0][1]=='o' && Mat[1][1]=='o' && Mat[2][1]!='x') { Mat[2][1]='o'; return; } // ataque coluna 01
           if(Mat[0][1]=='o' && Mat[2][1]=='o' && Mat[1][1]!='x') { Mat[1][1]='o'; return; }
           if(Mat[2][1]=='o' && Mat[1][1]=='o' && Mat[0][1]!='x') { Mat[0][1]='o'; return; }

           if(Mat[0][2]=='o' && Mat[1][2]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque coluna 02
           if(Mat[0][2]=='o' && Mat[2][2]=='o' && Mat[1][2]!='x') { Mat[1][2]='o'; return; }
           if(Mat[2][2]=='o' && Mat[1][2]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='o' && Mat[1][1]=='o' && Mat[2][2]!='x') { Mat[2][2]='o'; return; } // ataque diagonais
           if(Mat[2][0]=='o' && Mat[1][1]=='o' && Mat[0][2]!='x') { Mat[0][2]='o'; return; }
           if(Mat[2][2]=='o' && Mat[1][1]=='o' && Mat[0][0]!='x') { Mat[0][0]='o'; return; }
           if(Mat[0][2]=='o' && Mat[1][1]=='o' && Mat[2][0]!='x') { Mat[2][0]='o'; return; }

           if(Mat[0][0]=='x' && Mat[0][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; } // linhas defesa direita
           if(Mat[1][0]=='x' && Mat[1][1]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[0][1]=='x' && Mat[0][2]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // linhas defesa esquerda
           if(Mat[1][1]=='x' && Mat[1][2]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; }
           if(Mat[2][1]=='x' && Mat[2][2]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }

           if(Mat[0][0]=='x' && Mat[0][2]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; } // linhas defesa meio
           if(Mat[1][0]=='x' && Mat[1][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[2][2]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][0]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; } // colunas defesa baixo
           if(Mat[0][1]=='x' && Mat[1][1]=='x' && Mat[2][1]!='o') { Mat[2][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[1][2]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; }

           if(Mat[2][0]=='x' && Mat[1][0]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; } // colunas defesa cima
           if(Mat[2][1]=='x' && Mat[1][1]=='x' && Mat[0][1]!='o') { Mat[0][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][2]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[2][0]=='x' && Mat[1][0]!='o') { Mat[1][0]='o'; return; } // colunas defesa linha 0 e 2
           if(Mat[0][1]=='x' && Mat[2][1]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[0][2]=='x' && Mat[2][2]=='x' && Mat[1][2]!='o') { Mat[1][2]='o'; return; }

           if(Mat[0][0]=='x' && Mat[1][1]=='x' && Mat[2][2]!='o') { Mat[2][2]='o'; return; } // diagonais defesa
           if(Mat[0][2]=='x' && Mat[1][1]=='x' && Mat[2][0]!='o') { Mat[2][0]='o'; return; }
           if(Mat[0][0]=='x' && Mat[2][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][0]=='x' && Mat[0][2]=='x' && Mat[1][1]!='o') { Mat[1][1]='o'; return; }
           if(Mat[2][2]=='x' && Mat[1][1]=='x' && Mat[0][0]!='o') { Mat[0][0]='o'; return; }
           if(Mat[2][0]=='x' && Mat[1][1]=='x' && Mat[0][2]!='o') { Mat[0][2]='o'; return; }

         }
         default: {
             for(i=0;i<3;i++) {
                     for(j=0;j<3;j++) { if(Mat[i][j]==' ') { Mat[i][j]='o'; return; }

                     }
           }
         }
      }

}

char fechou(char Mat[3][3]) {
char vencedor=' ';

// usuario
 if(Mat[0][0]=='x' && Mat[0][1]=='x' && Mat[0][2]=='x') vencedor='x'; // linha cheia
 if(Mat[1][0]=='x' && Mat[1][1]=='x' && Mat[1][2]=='x') vencedor='x';
 if(Mat[2][0]=='x' && Mat[2][1]=='x' && Mat[2][2]=='x') vencedor='x';

 if(Mat[0][0]=='x' && Mat[1][0]=='x' && Mat[2][0]=='x') vencedor='x'; // colunas
 if(Mat[0][1]=='x' && Mat[1][1]=='x' && Mat[2][1]=='x') vencedor='x';
 if(Mat[0][2]=='x' && Mat[1][2]=='x' && Mat[2][2]=='x') vencedor='x';

 if(Mat[0][0]=='x' && Mat[1][1]=='x' && Mat[2][2]=='x') vencedor='x';  // diagonais
 if(Mat[0][2]=='x' && Mat[1][1]=='x' && Mat[2][0]=='x') vencedor='x';

// computador
 if(Mat[0][0]=='o' && Mat[0][1]=='o' && Mat[0][2]=='o') vencedor='o'; // linha cheia
 if(Mat[1][0]=='o' && Mat[1][1]=='o' && Mat[1][2]=='o') vencedor='o';
 if(Mat[2][0]=='o' && Mat[2][1]=='o' && Mat[2][2]=='o') vencedor='o';

 if(Mat[0][0]=='o' && Mat[1][0]=='o' && Mat[2][0]=='o') vencedor='o'; // colunas
 if(Mat[0][1]=='o' && Mat[1][1]=='o' && Mat[2][1]=='o') vencedor='o';
 if(Mat[0][2]=='o' && Mat[1][2]=='o' && Mat[2][2]=='o') vencedor='o';

 if(Mat[0][0]=='o' && Mat[1][1]=='o' && Mat[2][2]=='o') vencedor='o';  // diagonais
 if(Mat[0][2]=='o' && Mat[1][1]=='o' && Mat[2][0]=='o') vencedor='o';


return vencedor;
}

int fim_jogo(char Mat[3][3]) {
 int i,j,conta_espaco=0;
for(i=0;i<3;i++) {
  for(j=0;j<3;j++){
    if(Mat[i][j]==' ') conta_espaco=conta_espaco+1;
  }
}

  if(conta_espaco==0) return 1;

return 0; }

int main()
{
    system("COLOR fc");

    int j,i,a=0,jogar=1,usuario=0,pc=0,empate=0,vez;
    char Mat[3][3],b=' ';

    printf("Jogo da Velha \n\n");

    do{

    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       Mat[i][j]=' ';

       mostrar_matriz(Mat);
     printf("\n\n");

    do {

      srand(time(NULL));
      vez=rand()%2;

      voce_joga(Mat);
      //fechou(Mat);

     if(fechou(Mat)=='x' || fechou(Mat)=='o') {a=1; break; }

    printf("\n\n");

     computador_joga(Mat);

    //fechou(Mat);

    if(fechou(Mat)=='x' || fechou(Mat)=='o') {a=1; break; }

    mostrar_matriz(Mat);
    printf("\n");

    a=fim_jogo(Mat);

    } while(a==0);


    printf("\n\n");
    mostrar_matriz(Mat);
    printf("\n\n");

    b=fechou(Mat);

    if(b==' ') { printf("\n\n Empate...\n\n"); empate=empate+1; }

    if(b=='x') { printf("\n\n Voce Venceu\n\n"); usuario=usuario+1; }

    if(b=='o') { printf("\n\n Computador venceu\n\n"); pc=pc+1; }

    printf("\n\n Jogar Novamente? [0]Nao [1]Sim : ");
    scanf("%d",&jogar);
    printf("\n\n");
     system("cls");


    } while(jogar==1);
     printf(" Placar: Usuario:%d | PC:%d --- Empate:%d\n\n",usuario,pc,empate);
     system("pause");
    return 0;
}
