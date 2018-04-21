#include <stdio.h>
#include <stdlib.h>

struct Dlist{
	int chave;
	struct Dlist* nxt;
	struct Dlist* ant;
}*head,*tail,*tmp;
typedef struct Dlist dlist;

int list_size = 0;
int init = 0;
void printmenu(void);
void addtail(void);
void addhead(void);
void removetail(void);
void removehead(void);
void disp(void);
void create(void);
void menu(void);
void kill(void);


int main(){
    menu();
}

void menu(){
    int opt;
    while(1){
        printmenu();
        scanf("%d",&opt);
        switch(opt){
            case 1:
                addhead();
                break;
            case 2:
                addtail();
                break;
            case 3:
                removehead();
                break;
            case 4:
            	removetail();
            	break;
            case 5:
            	disp();
            	break;
            case 6:
                kill();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\n**ERROR: INVALID_OPTION**");
                break;
        }
    }
}

void printmenu(){
    printf("..........................................\n");
    printf("Type one of the following options:........\n");
    printf("1. Add a element to the list's head.......\n");
    printf("2. Add a element to the list's tail.......\n");
    printf("3. Remove a element from the list's head..\n");
    printf("4. Remove a element from the list's tail..\n");
    printf("5. Display the list elements..............\n");
    printf("6. Erase the list.........................\n");
    printf("7. Exit the program.......................\n");
    printf("..........................................\n");
}

void create(void){
    head=NULL;
    tail=NULL;
}
void addhead(void){
    int chave;
    printf("Type the element to be added into the list: ");
    scanf("%d" , &chave);
    dlist* newelement =(dlist*)calloc(1,sizeof(dlist*));
    newelement->chave = chave;
    if(head==NULL){
        newelement->nxt=NULL;
        newelement->ant=NULL;
        head=newelement;
        tail=newelement;
    }else{
        head->nxt=newelement;
        newelement->ant=head;
        head=newelement;
    }
    list_size++;
}
void addtail(void){
    int chave;
    printf("Type the element to be added into the list: ");
    scanf("%d" , &chave);
    dlist* newelement =(dlist*)calloc(1,sizeof(dlist*));
    newelement->chave = chave;
    if(tail==NULL){
        newelement->ant=NULL;
        newelement->nxt=NULL;
        tail=newelement;
        head=newelement;
    }else{
        newelement->ant = NULL;
        newelement->nxt = tail;
        tail=newelement;
    }
    list_size++;
}

void removehead(void){
    if(head==NULL){
        printf("ERROR : EMPTY FILE");
    }else{
        if(head->ant==NULL){
            free(head);
            head = NULL;
            tail = NULL;
        }else{
            tmp = head;
            head = head->ant;
            free(tmp);
        }
        list_size--;
    }
}
void removetail(void){
    if(tail==NULL){
        printf("ERROR : EMPTY FILE");
    }else{
        if(tail->nxt == NULL){
            free(tail);
            tail = NULL;
            head = NULL;
        }else{
            tmp=tail;
            tail=tail->nxt;
            free(tmp);
        }
        list_size--;
    }
}

void disp(){
	if((tail==NULL)&&(head==NULL)){
		printf("Empty List\n");
	}else{
	    int tmp_idx = 0;
		tmp = tail;
		while(tmp_idx != list_size){
			printf("%d ", tmp->chave);
			tmp = tmp->nxt;
            tmp_idx++;
		}
		printf("\n");
	}
}

void kill(){
    if((head==NULL)&&(tail=NULL)){
        printf("**ERROR: empty list**");
    }else{
        tmp = tail;
        while(tmp->nxt != NULL){
            tail = tmp->nxt;
            free(tmp);
            tmp = tail;
        }
        tail = NULL;
        head = NULL;
        list_size = 0;
        printf("**STACK_ERASED**\n");
    }
}
