#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
  int topo;
  int  el[200];
} Pilha;


typedef struct
{
  int fim;
  int  el[200];
} Visitados;

typedef struct
{
    int adj[200][200];
    int indice_inc;
    int max;
} Vetor;

void StartVector(Vetor *mVetor, Visitados *mvi, Pilha *mpilha, int maximo){
   for (int i=0; i<maximo;i++)
       for (int j=0; j<maximo;j++)
          mVetor->adj[i][j] = 0;

    mVetor->indice_inc=0;
    mpilha->topo=0;

}

void CreateEdges(Vetor *mVetor){
      
    mVetor->adj[0][1] = 1;
	mVetor->adj[0][3] = 1;
	mVetor->adj[1][2] = 1;
	mVetor->adj[1][4] = 1;
	mVetor->adj[2][3] = 1;
	mVetor->adj[2][5] = 1;
	mVetor->adj[3][7] = 1;
	mVetor->adj[4][5] = 1;
	mVetor->adj[5][6] = 1;
	mVetor->adj[5][8] = 1;
	mVetor->adj[5][9] = 1;
	mVetor->adj[6][3] = 1;
	mVetor->adj[6][7] = 1;
	mVetor->adj[6][9] = 1;
	mVetor->adj[8][10] = 1;
	mVetor->adj[9][7] = 1;
	mVetor->adj[9][10] = 1;
}

void NullifySearch(Vetor *mVetor, Visitados *mvi, Pilha *mpilha){
    int maximo = mVetor->max;

    for (int i=0; i<maximo;i++){
      mpilha->el[i]=0;
    }
    mpilha->topo=0;
}

void PrintMatriceAdj(Vetor *mVetor){
    printf("\nMatriz Adjacencia\n\n");

    for(int i=0; i<mVetor->max;i++)
           if(i==0){
               printf("|\tV0");
            }else if(i!=(mVetor->max-1)){
               printf("\tV%d",i);
           }else{
              printf("\tV%d\t|",i);
          }
    for(int i=0; i<mVetor->max;i++){
             printf("\n|V%d\t",i);
       for (int j=0;j<mVetor->max;j++){
        printf("%d\t",mVetor->adj[i][j]);
        }
        printf("|");
        }
     printf("\n\n");
    }
 
void DFS(Vetor *mvetor, Visitados *mVi, Pilha *mpilha, int inicio){
      int novoinicio =99;
      for (int i=0; i<mvetor->max; i++)
          if(mvetor->adj[i][inicio]==1){
                      if(novoinicio==99){
                               novoinicio=i;
                       }else {
                           mpilha->el[mpilha->topo]=i;
                           mpilha->topo++;
                       }
            }


            if(novoinicio!=99){
              DFS(mvetor, novoinicio);
            }else if(mpilha->topo!=0){
                 mpilha->topo--;

                 DFS(mvetor, mpilha->el[mpilha->topo], novoinicio);

            }else{
                return 1;
                }
}

int main(){
	int op, v1, valor, novo;
    Vetor mVetor;
    Pilha mPilha;
    Visitados mVisitados;

    printf("Matriz\n\n ");
    novo = 10;
    StartVector(&mVetor,&mVisitados, &mPilha, novo);
	printf("\n");
	
    do
	{
	    CreateEdges(&mVetor);
        PrintMatriceAdj(&mVetor);  
		
        printf ("1|- Realizar Busca\n");
        printf ("2|- Sair\n");
    
        printf("\n");
        scanf("%d", &op);
		switch(op)
		{
			case 1:{ NullifySearch(&mVetor,&mVisitados, &mPilha);
              printf("Digite o vertice inicial da Busca: ");
                        scanf("%d",&v1);	
                        DFS(&mVetor, &mVisitados, &mPilha, v1); 
                        system ("pause");
                        break; }
		}
	} 
	while (op!=2);
		return 1;
}