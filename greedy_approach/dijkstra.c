#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 999

int mat[MAX][MAX];
int V;

int dist[MAX];

int q[MAX];
int qp = 0;

void enqueue(int v) { q[qp++] = v; }

int cf(void *a, void *b)
{
	fprintf(stderr, ">>> Entering cf(a=%p,b=%p)\n", a, b);
    int *x = (int *)a;
    int *y = (int *)b;
    return *y - *x;
}

int dequeue()
{
	fprintf(stderr, ">>> Entering dequeue()\n");
    qsort(q, qp, sizeof(int), cf);
	fprintf(stderr, "<<< Exiting dequeue()\n");
    return q[--qp];
}

int queue_has_something() { return (qp > 0); }

int visited[MAX];
int vp = 0;

void dijkstra(int s)
{
	fprintf(stderr, ">>> Entering dijkstra(s=%d)\n", s);
    dist[s] = 0;
    int i;
    for (i = 0; i < V; ++i)
    {
        if (i != s)
        {
            dist[i] = INF;
        }
        enqueue(i);
    }
    while (queue_has_something())
    {
        int u = dequeue();
		fprintf(stderr, "dijkstra(s=%d): u → %d\n", s, u);
        visited[vp++] = u;
        for (i = 0; i < V; ++i)
        {
            if (mat[u][i])
            {
                if (dist[i] > dist[u] + mat[u][i])
                {
                    dist[i] = dist[u] + mat[u][i];
                }
            }
        }
    }
	fprintf(stderr, "<<< Exiting dijkstra(s=%d)\n", s);
}

int main(int argc, char const *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%s)\n", argc, argv);
    printf("Enter the number of vertices: ");
    scanf(" %d", &V);
    printf("Enter the adj matrix: ");
    int i, j;
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            scanf(" %d", &mat[i][j]);
        }
    }

    dijkstra(0);

    printf("\nNode\tDist\n");
    for (i = 0; i < V; ++i)
    {
        printf("%d\t%d\n", i, dist[i]);
    }

	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%s)\n", argc, argv);
    return 0;
}
