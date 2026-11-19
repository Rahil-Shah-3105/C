#include <stdbool.h>
#include <stdio.h>
#include "Graph.h"

// Return the number of vertices that v is
// connected to
int degree(Graph g, int nV, Vertex v)
{
	fprintf(stderr, "[ERROR] >>> Entering degree(g=%d,nV=%d,v=%d)\n", g, nV, v);
    int deg = 0;
    Vertex w;
    for (w = 0; w < nV; w++)
        if (adjacent(g, v, w))
            deg++;
	fprintf(stderr, "[WARN] <<< Exiting degree(g=%d,nV=%d,v=%d)\n", g, nV, v);
    return deg;
}

// If start from vertex v, decide if the
// graph has euler path
bool hasEulerPath(Graph g, int nV, Vertex v, Vertex w)
{
	fprintf(stderr, "[ERROR] >>> Entering hasEulerPath(g=%d,nV=%d,v=%d,w=%d)\n", g, nV, v, w);
    if (v != w)
    {
        if (degree(g, nV, v) % 2 == 0 || degree(g, nV, w) % 2 == 0)
            return false;
    }
    else if (degree(g, nV, v) % 2 != 0)
    {
        return false;
    }
    Vertex x;
    for (x = 0; x < nV; x++)
        if (x != v && x != w && degree(g, nV, x) % 2 != 0)
            return false;
    return true;
}

int main(void)
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    Edge e;
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);
	fprintf(stderr, "[ERROR] main(): g → %d\n", g);

    Vertex src, dest;
    printf("Enter source node: ");
    scanf("%d", &src);
    printf("Enter destination node: ");
    scanf("%d", &dest);

    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1)
    {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Finished.\n");

    printf("The graph has ");
    if (hasEulerPath(g, n, src, dest))
        printf("an");
    else
        printf("no");
    printf(" Euler path from %d to %d.\n", src, dest);

    freeGraph(g);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}

// By
//  .----------------.  .----------------.  .----------------.
//  .-----------------.  .----------------.  .----------------.
// | .--------------. || .--------------. || .--------------. ||
// .--------------. | | .--------------. || .--------------. | | |  _________ |
// || | _____  _____ | || |      __      | || | ____  _____  | | | |  ____  ____
// | || |     ____     | | | | |  _   _  |  | || ||_   _||_   _|| || |     /  \
// | || ||_   \|_   _| | | | | |_   ||   _| | || |   .'    `.   | | | | |_/ | |
// \_|  | || |  | |    | |  | || |    / /\ \    | || |  |   \ | |   | | | |   |
// |__| |   | || |  /  .--.  \  | | | |     | |      | || |  | '    ' |  | || |
// / ____ \   | || |  | |\ \| |   | | | |   |  __  |   | || |  | |    | |  | |
// | |    _| |_     | || |   \ `--' /   | || | _/ /    \ \_ | || | _| |_\   |_
// | | | |  _| |  | |_  | || |  \  `--'  /  | | | |   |_____|    | || | `.__.'
// | || ||____|  |____|| || ||_____|\____| | | | | |____||____| | || | `.____.'
// | | | |              | || |              | || |              | || | | | | |
// | || |              | | | '--------------' || '--------------' ||
// '--------------' || '--------------' | | '--------------' || '--------------'
// |
//  '----------------'  '----------------'  '----------------'
//  '----------------'   '----------------'  '----------------'

//  Email :    z5261243@unsw.edu.au
//             hhoanhtuann@gmail.com
