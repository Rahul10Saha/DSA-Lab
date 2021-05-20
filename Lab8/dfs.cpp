// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;

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

void push(int item) { 
    
    stack[++top] = item; 
} 

int pop() { 
    printf("\nThe value poped is: %d",stack[top]);
    return stack[top--]; 
} 

void print_stack(){
    printf("\nThe Stack contains: ");
    for(int k=top;k>=0;k--){
        printf("%d ",stack[k]);
    }
}

int isEmpty() {
   if (top == -1)
        return 1;
    else
        return 0;
}

// Create a node
node* create_node(int dest)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* create_graph(int vertices) {
    Graph* graph =(Graph*)malloc(sizeof(Graph));
    graph->Vertices = vertices;

    graph->adj_list =(node**)malloc(vertices * sizeof(node*));

    graph->visited =(int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adj_list[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void add_edge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    node* newNode = create_node(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;

    // Add edge from dest to src
    newNode = create_node(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

// DFS algo
void DFS_visit(Graph* graph, int start_vertex) {
    graph->visited[start_vertex] = 1;
    push(start_vertex);
    int i=0;
    while (!isEmpty()) {
        print_stack();
        int current_vertex = pop();
        printf("\nVisited %d\n\n", current_vertex);
        node* temp = graph->adj_list[current_vertex];
        while (temp) {
        int adj_vertex = temp->dest;
        if(graph->visited[adj_vertex]==1){
            printf("\nVertex %d which is adjacent to %d is already visited",adj_vertex,current_vertex);
        }
        else if(graph->visited[adj_vertex] == 0) {
            graph->visited[adj_vertex] = 1;
            printf("\nThe unvisited vertex %d is adjacent to %d",adj_vertex,current_vertex);
            push(adj_vertex);
        }
        temp = temp->next;
        }
    }
}

//Function to print the graph
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

//driver function
int main() {
    system("cls");
    printf("\t\tDepth First Search in Graph");
    int vertices,ver1,ver2,vertex;
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
    printf("Enter the vertex you want to search the dfs of: ");
    scanf("%d",&vertex);
    printf("\n");
    DFS_visit(graph, vertex);
    printf("\n\n");
    return 0;
}