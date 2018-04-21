#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node* nxt;
}*head,*tail,*tmp;

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

void create(){
	if(init == 0){
		head = NULL;
		tail = NULL;
		init = 1;
	}else{
		printf("**ERROR: LIST ALREADY CREATED**\n");
	}
}

void addhead(){
	int x;
	struct node* newelement = (struct node*)calloc(1,sizeof(struct node));
	printf("Type the element to be added into the list: ");
	scanf("%d",&x);
	newelement->info = x;
	newelement->nxt = NULL;
	if(head == NULL){
		head = newelement;
		tail = newelement;
	}else{
		head->nxt = newelement;
		head=head->nxt;
	}
	list_size++;
}

void addtail(){
	int x;
	struct node* newelement = (struct node*)calloc(1,sizeof(struct node));
	printf("Type the element to be added into the list: ");
	scanf("%d",&x);
	newelement->info = x;
	if(tail==NULL){
		head = newelement;
		tail = newelement;
	}else{
		newelement->nxt = tail;
	}
	list_size++;
}

void removehead(){
	if((tail==NULL)&&(head==NULL)){
		printf("**ERROR: EMPTY_LIST**\n");
	}else{
		if(head!=tail){
            tmp = tail;
            while(tmp->nxt!=head){
                tmp = tmp->nxt;
            }
            free(head);
            head = tmp;
            head->nxt = NULL;
		}else{
            free(head);
            head = NULL;
            tail = NULL;
		}
	}
}

void removetail(){
	if((tail==NULL)&&(head==NULL)){
		printf("**ERROR: EMPTY_LIST**\n");
	}else{
		tmp = tail->nxt;
		free(tail);
		tail = tmp;
		if(tail==NULL){
            head=NULL;
		}
	}
}

void kill(){
	if((tail==NULL)&&(head==NULL)){
		printf("**ERROR: EMPTY_LIST**\n");
	}else{
		tmp = tail;
		while(tmp!=NULL){
			tail = tmp->nxt;
			free(tmp);
			tmp = tail;
		}
		tail = NULL;
		head = NULL;
		printf("**STACK_ERASED**\n");
	}
}

void disp(){
	if((tail==NULL)&&(head==NULL)){
		printf("Empty List\n");
	}else{
		tmp = tail;
		while(tmp != NULL){
			printf("%d ", tmp->info);
			tmp = tmp->nxt;
		}
		printf("\n");
	}
}
