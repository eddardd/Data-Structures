#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node*pai;
    struct node*right;
    struct node*left;
    int chave;
}*root,*tmp;


int nNodes = 0;
int h = 0;
void createtree(void);
void insertnode(void);
int getmax(void);
int getmin(void);

int main(){

}

void createtree(){
    root=NULL;
}

void insertnode(){
    int chave;
    printf("Type the number to be addicted: ");
    scanf("%d" , &chave);
    struct node* newelement=(struct node*)calloc(1,sizeof(struct node));
    if(root==NULL){
        root = newelement;
        root->pai = NULL;
    }else{
        tmp = root;
        while(1){
            if((tmp->chave > newelement->chave)&&(tmp->right != NULL)) tmp = tmp->right;
            if((tmp->chave > newelement->chave)&&(tmp->right == NULL)) break;
            if((tmp->chave < newelement->chave)&&(tmp->left != NULL)) tmp = tmp->left;
            if((tmp->chave < newelement->chave)&&(tmp->left == NULL)) break;
        }
        newelement->pai = tmp;
        if(tmp->chave > newelement->chave){
            tmp->right = newelement;
        }else{
            tmp->left = newelement;
        }
    }
    newelement->left = NULL;
    newelement->right = NULL;
}

int getmax(void){
    if(root = NULL){
        printf("**Empty tree**\n");
        return -1;
    }else{
        tmp = root;
        while(tmp->right != NULL){
            tmp = tmp->right;
        }
        return tmp->chave;
    }
}

int getmin(void){
    if(root == NULL){
        printf("**Empty tree"\n);
        return -1;
    }else{
        tmp = root;
        while(tmp->left != NULL){
            tmp = tmp->left;
        }
        return tmp->chave;
    }
}
