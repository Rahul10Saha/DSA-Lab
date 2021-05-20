#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
#define MAX 100
int array[MAX];

typedef struct n_ary_tree{
    int data;
    struct n_ary_tree *firstChild;
    struct n_ary_tree *nextSibling;
}tree;

typedef struct queue_list {
    int items[SIZE];
    int front;
    int rear;
}queue;

typedef struct adjacency_list_node
{
    int dest;
    struct adjacency_list_node* next;
}node;

typedef struct Graph_Structure
{
    int Vertices;
    node** adj_list;
    int* visited;
}Graph;

node* create_node(int dest)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}



Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = vertices;

    graph->adj_list = (node**)malloc(vertices * sizeof(node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adj_list[i]= NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest)
{
    node* newNode = create_node(dest);
    newNode->next = graph->adj_list[src];
    graph-> adj_list[src]= newNode;

    newNode = create_node(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest]= newNode;
}

//Function to create a queue
queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Overflow");
    else {
        if (q->front == -1)
        q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("\nQueue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        printf("\nThe Value Dequeued is:%d",item);
        q->front++;
        if (q->front > q->rear) {
        printf("\nResetting queue");
        q->front = q->rear = -1;
        }
    }
    return item;
}

// Print the queue
void print_queue(queue* q) {
    int i = q->front;

    if (isEmpty(q)) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue contains: ");
        for (i = q->front; i < q->rear + 1; i++) {
        printf("%d ", q->items[i]);
        }
    }
}

void bfs(Graph* graph, int start_vertex) {
    queue* q = create_queue();
    graph->visited[start_vertex] = 1;
    enqueue(q, start_vertex);
    int i=0;
    while (!isEmpty(q)) {
        print_queue(q);
        int current_vertex = dequeue(q);
        printf("\nVisited %d\n\n", current_vertex);
        array[i]=current_vertex;
        i++;
        node* temp = graph->adj_list[current_vertex];

        while (temp) {
        int adj_vertex = temp->dest;
        if(graph->visited[adj_vertex]==1){
            printf("\nVertex %d which is adjacent to %d is already visited",adj_vertex,current_vertex);
        }
        else if(graph->visited[adj_vertex] == 0) {
            graph->visited[adj_vertex] = 1;
            printf("\nThe Value %d is a child to the node %d",adj_vertex,current_vertex);
            enqueue(q, adj_vertex);
        }
        temp = temp->next;
        }
    }
}

//Fuction to print the graph
void print_graph(Graph* graph) {
  int v;
  for (v = 0; v < graph->Vertices; v++) {
    node* temp = graph->adj_list[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->dest);
      temp = temp->next;
    }
    printf("\n");
  }
}

//driver code
int main() {
    system("cls");
    printf("\t\tBreadth First Search in Graph");
    int vertices,ver1,ver2;
    char ch;
    printf("\n\nEnter the number of Vertices: ");
    scanf("%d",&vertices);
    Graph* graph = create_graph(vertices);
    do{
        printf("\nEnter the vertices you want to enter an edge in between: ");
        scanf("%d %d",&ver1,&ver2);
        add_edge(graph,ver1,ver2);
        printf("Do you want to insert more edges->Y to continue and N to Exit:");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    printf("\nDisplaying the Graph in adjacency List Format\n");
    print_graph(graph);
    printf("\n\n");
    bfs(graph, 0);
    printf("\n\nThe Breadth first search for the Given Graph is:\n");
    for(int i=0;i<vertices;i++){
        printf("%d ",array[i]);
    }
    printf("\n\n");
    return 0;
}