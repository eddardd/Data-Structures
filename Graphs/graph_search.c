#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// Adjacency List node struct
struct AdjListNode{
    int dest;
    struct AdjListNode* nxt;
};

typedef struct AdjListNode node;

// Adjacency List struct
struct adjlist{
    node* head;
};

typedef struct adjlist AdjList;

// Graph struct
struct graph{
    int n; // Vertex number
    AdjList* array; // Adjacency list
};

typedef struct graph Graph;

// Queue struct
struct queue{
    int* qu;        // Queue vector
    int current;    // current elements into the queue vector
    int n;          // Number of max elements
    int rear;       // Queue rear position
    int front;      // Queue front position
};

typedef struct queue Queue;

node* newAdjListNode(int dest);             // Creates new nodes in g
Graph* createGraph(int n);                  // Creates a graph
void addEdge(Graph* g, int src, int dest);  // Adds a edge between two vertices in g
void printGraph(Graph* g);                  // print the adj list
int  DFS(Graph* g);                         // DFS algorithm
Queue* CreateQueue(int n);                  // Create Queue
bool isEmpty(Queue* q);                     // Verify emptiness
bool isFull(Queue* q);                      // Verify fullness
int  size(Queue* q);                        // Return the size of the queue
void insert(Queue* q,int x);                // Insert element into the queue
int remv(Queue* q);                         // Remove element from the queue
void explore(Graph* g, int v, int* explored);  // Explore sub-routine
int* BFS(Graph* g, int src); // BFS Algorithm
Graph* sqrGraph(Graph* G);   // Square Graph algorithm

int main(){
    int n = 4;
    Graph* g = createGraph(n);
    addEdge(g,0,1);
    addEdge(g,1,3);
    addEdge(g,3,2);
    addEdge(g,2,0);
    addEdge(g,0,3);
    Graph* h = sqrGraph(g);
    printGraph(h);


    return 0;
}

node* newAdjListNode(int dest){
    node* newNode = (node*)calloc(1,sizeof(node));
    newNode->dest = dest;
    newNode->nxt  = NULL;
    return newNode;
}

Graph* createGraph(int n){
    int i;
    Graph* g = (Graph*)calloc(1,sizeof(Graph));
    g->n = n;
    g->array = (AdjList*)calloc(n,sizeof(AdjList));
    for(i=0;i<n;++i){
        g->array[i].head = NULL;
    }
    return g;
}

void addEdge(Graph* g, int src, int dest){
    node* newNode = newAdjListNode(dest);
    newNode->nxt = g->array[src].head;
    g->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->nxt = g->array[dest].head;
    g->array[dest].head = newNode;
}

void printGraph(Graph* g){
    int v;
    for(v=0;v<g->n;++v){
        node* aux = g->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while(aux){
            printf("-> %d", aux->dest);
            aux = aux->nxt;
        }
        printf("\n");
    }
}

void explore(Graph* g,int v, int* explored){
    int w;
    explored[v] = 1;
    node* aux = g->array[v].head;
    while(aux){
        w = aux->dest;
        aux = aux->nxt;
        if(explored[w]==0){
            printf("(%d,%d) ", v,w);
            explore(g,w,explored);
        }
    }
}

int DFS(Graph* g){
    int CCnumber = 0;
    int v;
    int* explored = (int*)calloc(g->n,sizeof(int));
    for(v=0;v<g->n;v++){
        if(explored[v]==0){
            explore(g,v,explored);
            CCnumber++;
            printf("\n");
        }
    }
    return CCnumber;
}

int* BFS(Graph* g, int src){
    // Variable declaration
    int* pai = (int*)calloc(G->n,sizeof(int));
    char* color = (char*)calloc(g->n,sizeof(char)); // Vector with respective colors of vertex
    int* dist = (int*)calloc(g->n,sizeof(int)); // Vector with respective distances from src
    int v,u,w; // auxiliar vertices
    node* aux; // auxiliar node
    Queue* q; // queue
    //initial setup
    for(v=0;v<g->n;v++){
        color[v] = 'w';
        dist[v] = INT_MAX;
        pai[v] = -1;
    }
    color[src] = 'g';
    dist[src] = 0;
    q = CreateQueue(g->n);
    insert(q,src);
    printf("%d", q->current);
    //BFS
    while(!isEmpty(q)){
        u = remv(q);
        //AdjList search
        aux = g->array[u].head;
        while(aux!=NULL){
            w = aux->dest;
            aux = aux->nxt;
            if(color[w] == 'w'){
                color[w] = 'g';
                pai[w] = u;
                dist[w] = dist[u]+1;
                insert(q,w);
            }
        }
    }

    return dist;
}

Queue* CreateQueue(int n){
    Queue* q = (Queue*)calloc(1,sizeof(Queue));
    int* qu = (int*)calloc(n,sizeof(int)); // Creates the queue vector
    //Atribuition
    q->qu = qu;
    q->current = 0;
    q->n = n;
    q->rear = -1;
    q->front = 0;

    return q;
}

bool isEmpty(Queue* q){
    return q->current == 0;
}

bool isFull(Queue* q){
    return q->current == q->n;
}

int  size(Queue* q){
    return q->current;
}
void insert(Queue* q,int x){
    if(!isFull(q)){
        if(q->rear == q->n-1){
            q->rear = -1;
        }
        q->rear++;
        q->qu[q->rear] = x;
        q->current++;
    }
}

int remv(Queue* q){
    int x = q->qu[q->front];
    q->front++;
    if(q->front == q->n){
        q->front = 0;
    }
    q->current--;
    return x;
}

Graph* sqrGraph(Graph* G){
    int u,v,w,i;
    Graph* H = (Graph*)calloc(1,sizeof(Graph)); // Allocates the graph
    H = createGraph(G->n); // Creates H
    int** phi = (int**)calloc(G->n,sizeof(int*)); // Auxiliar matrix

    for(i=0;i<G->n;i++){
        phi[i] = (int*)calloc(G->n,sizeof(int*));
    }

    node *aux1, *aux2;
    H->n = G->n;

    for(u=0;u<G->n;u++){ // runs adjacency list of u
        aux1 = G->array[u].head; // Adjacency list head
        while(aux1!=NULL){ // runs adjacency list of v
            v = aux1->dest; // v is adjacent to u
            aux1 = aux1->nxt; // follows the adjacency list
            aux2 = G->array[v].head;
            while(aux2!=NULL){ // runs adjacency list of w
                w = aux2->dest; // w is adjacent to v
                aux2 = aux2->nxt; // follows the adjacency list
                if((phi[u][w] == 0)&&(phi[w][u]==0)){ // see if the edge wasn't added before
                    phi[u][w] = 1;
                    phi[w][u] = 1;
                    addEdge(H,u,w);
                }
            }
        }
    }
    return H;
}
