#include "errno.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
// Assume max size of graph is 40 nodes
struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

// Some declarations
struct queue *createQueue();
void enqueue(struct queue *q, int);
int dequeue(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
int pollQueue(struct queue *q);

// Structure to create a graph node
struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int);

// Graph data structure
struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};
struct Graph *createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);
void printGraph(struct Graph *graph);
void bfs(struct Graph *graph, int startVertex);

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int vertices, edges, source, i, src, dst;
    printf("Enter the number of vertices\n");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    printf("Enter the number of edges\n");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++)
    {
        printf("Edge %d \nEnter source: ", i + 1);
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dst);
        addEdge(graph, src, dst);
    }
    printf("Enter source of bfs\n");
    scanf("%d", &source);
    bfs(graph, source);

    // Uncomment below part to get a ready-made example
    /*struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    bfs(graph,0);*/

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
void bfs(struct Graph *graph, int startVertex)
{
    struct queue *q = createQueue();

    // Add to visited list and put in queue
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    printf("Breadth first traversal from vertex %d is:\n", startVertex);

    // Iterate while queue not empty
    while (!isEmpty(q))
    {
        printf("%d ", pollQueue(q));
        int currentVertex = dequeue(q);

        struct node *temp = graph->adjLists[currentVertex];
        // Add all unvisited neighbours of current vertex to queue to be printed
        // next
        while (temp)
        {
            int adjVertex = temp->vertex;
            // Only add if neighbour is unvisited
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting bfs(graph=%p,startVertex=%p)\n", graph, startVertex);
}
// Memory for a graph node
struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// Allocates memory for graph data structure, in adjacency list format
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}
// Adds bidirectional edge to graph
void addEdge(struct Graph *graph, int src, int dest)
{
	fprintf(stderr, "[ERROR] >>> Entering addEdge(graph=%p,src=%p,dest=%d)\n", graph, src, dest);
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src; comment it out for directed graph
    newNode = createNode(src);
	fprintf(stderr, "[ERROR] addEdge(graph=%p,src=%d,dest=%d): newNode → %p\n", graph, src, dest, newNode);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
	fprintf(stderr, "[WARN] <<< Exiting addEdge(graph=%p,src=%p,dest=%d)\n", graph, src, dest);
}
// Allocates memory for our queue data structure
struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
// Checks for empty queue
int isEmpty(struct queue *q)
{
	fprintf(stderr, "[ERROR] >>> Entering isEmpty(q=%p)\n", q);
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
// Inserts item at start of queue
void enqueue(struct queue *q, int value)
{
	fprintf(stderr, "[ERROR] >>> Entering enqueue(q=%p,value=%p)\n", q, value);
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
	fprintf(stderr, "[WARN] <<< Exiting enqueue(q=%p,value=%p)\n", q, value);
}
// Returns item at front of queue and removes it from queue
int dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
		fprintf(stderr, "[ERROR] dequeue(q=%p): item → %d\n", q, item);
    fprintf(stderr, "[DEBUG] dequeue(q=%p): item → %d\n", q, item);
    }
    else
    {
        item = q->items[q->front];
		fprintf(stderr, "[ERROR] dequeue(q=%p): item → %d\n", q, item);
		fprintf(stderr, "[DEBUG] dequeue(q=%p): item → %d\n", q, item);
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Returns element at front of queue
int pollQueue(struct queue *q) { return q->items[q->front]; }
