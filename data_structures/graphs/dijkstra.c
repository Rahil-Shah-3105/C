#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing a graph
struct Graph
{
    int vertexNum;
    int **edges;
};

// Constructs a graph with V vertices and E edges
void createGraph(struct Graph *G, int V)
{
	fprintf(stderr, "[ERROR] >>> Entering createGraph(G=%p,V=%p)\n", G, V);
    G->vertexNum = V;
    G->edges = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        G->edges[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) G->edges[i][j] = INT_MAX;
        G->edges[i][i] = 0;
    }
	fprintf(stderr, "[WARN] <<< Exiting createGraph(G=%p,V=%p)\n", G, V);
}

// Adds the given edge to the graph
void addEdge(struct Graph *G, int src, int dst, int weight)
{
	fprintf(stderr, "[ERROR] >>> Entering addEdge(G=%p,src=%p,dst=%d,weight=%d)\n", G, src, dst, weight);
    G->edges[src][dst] = weight;
	fprintf(stderr, "[WARN] <<< Exiting addEdge(G=%p,src=%p,dst=%d,weight=%d)\n", G, src, dst, weight);
}

// Utility function to find minimum distance vertex in mdist
int minDistance(int mdist[], int vset[], int V)
{
	fprintf(stderr, "[ERROR] >>> Entering minDistance(mdist=%p,vset=%p,V=%p)\n", mdist, vset, V);
    int minVal = INT_MAX;
    static int minInd = -1; //remembers the previous value if not modified in the loop
	fprintf(stderr, "[ERROR] minDistance(mdist=%p,vset=%p,V=%d): minVal → %d\n", mdist, vset, V, minVal);
    for (int i = 0; i < V; i++)
        if (vset[i] == 0 && mdist[i] < minVal)
        {
            minVal = mdist[i];
            minInd = i;
        }

	fprintf(stderr, "[WARN] <<< Exiting minDistance(mdist=%p,vset=%p,V=%p)\n", mdist, vset, V);
    return minInd;
}

// Utility function to print distances
void print(int dist[], int V)
{
	fprintf(stderr, "[ERROR] >>> Entering print(dist=%p,V=%p)\n", dist, V);
    printf("\nVertex  Distance\n");
    for (int i = 0; i < V; i++)
    {
        if (dist[i] != INT_MAX)
            printf("%d\t%d\n", i, dist[i]);
        else
            printf("%d\tINF", i);
    }
	fprintf(stderr, "[WARN] <<< Exiting print(dist=%p,V=%p)\n", dist, V);
}

// The main function that finds the shortest path from given source
// to all other vertices using Dijkstra's Algorithm.It doesn't work on negative
// weights
void Dijkstra(struct Graph *graph, int src)
{
	fprintf(stderr, "[ERROR] >>> Entering Dijkstra(graph=%p,src=%p)\n", graph, src);
    int V = graph->vertexNum;
    int mdist[V];  // Stores updated distances to vertex
    int vset[V];   // vset[i] is true if the vertex i included
                   // in the shortest path tree

    // Initialise mdist and vset. Set distance of source as zero
    for (int i = 0; i < V; i++) mdist[i] = INT_MAX, vset[i] = 0;

    mdist[src] = 0;

    // iterate to find shortest path
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(mdist, vset, V);
		fprintf(stderr, "[ERROR] Dijkstra(graph=%p,src=%d): u → %d\n", graph, src, u);
        vset[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!vset[v] && graph->edges[u][v] != INT_MAX &&
                mdist[u] + graph->edges[u][v] < mdist[v])
                mdist[v] = mdist[u] + graph->edges[u][v];
        }
    }

    print(mdist, V);

	fprintf(stderr, "[WARN] <<< Exiting Dijkstra(graph=%p,src=%p)\n", graph, src);
    return;
}

// Driver Function
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int V, E, gsrc;
    int src, dst, weight;
    struct Graph G;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    createGraph(&G, V);
    for (int i = 0; i < E; i++)
    {
        printf("\nEdge %d \nEnter source: ", i + 1);
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dst);
        printf("Enter weight: ");
        scanf("%d", &weight);
        addEdge(&G, src, dst, weight);
    }
    printf("\nEnter source:");
    scanf("%d", &gsrc);
    Dijkstra(&G, gsrc);

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
