#include <stdio.h>
#include <stdlib.h>

int main(){
    int nVertices , nArestas;
    int i,j,k,r,c,op;
    printf(" Digite o numero de Vertices: ");
    scanf("%d" , &nVertices);
    int** A = (int**)calloc(nVertices,sizeof(int*));
    for(i=0;i<nVertices;i++){
        A[i]=(int*)calloc(nVertices,sizeof(int));
    }
    while(1){
        printf("\nDigite uma das opcoes abaixo:\n");
        printf("1) Digite as extremidades de uma nova aresta\n");
        printf("2) Mostrar matriz de adjacências\n");
        printf("3) Termine a execução\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite a primeira extremidade: ");
                scanf("%d",&j);
                printf("Digite a segunda extremidade: ");
                scanf("%d", &k);
                j--;
                k--;
                if((k>=0)&&(j>=0)&&(j<=nVertices)&&(k<=nVertices)){
                    A[j][k] = 1;
                    A[k][j] = 1;
                }else{
                    printf("\nVertice nao disponivel\n");
                }
                break;
            case 2:
                for(r=0;r<nVertices;r++){
                    for(c=0;c<nVertices;c++){
                        printf("%d ",A[r][c]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Digite uma opção válida\n");
        }
    }
}
