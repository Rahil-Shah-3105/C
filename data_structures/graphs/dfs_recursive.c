#include <stdbool.h>
#include <stdio.h>
#include "Graph.h"

#define MAX_NODES 1000

int visited[MAX_NODES];  // array to store visiting order
                         // indexed by vertex 0..nV-1

bool dfsPathCheck(Graph g, int nV, Vertex v, Vertex dest)
{
	fprintf(stderr, "[ERROR] >>> Entering dfsPathCheck(g=%d,nV=%d,v=%d,dest=%d)\n", g, nV, v, dest);
    Vertex w;
    for (w = 0; w < nV; w++)
        if (adjacent(g, v, w) && visited[w] == -1)
        {
            visited[w] = v;
            if (w == dest)
                return true;
            else if (dfsPathCheck(g, nV, w, dest))
                return true;
        }
	fprintf(stderr, "[WARN] <<< Exiting dfsPathCheck(g=%d,nV=%d,v=%d,dest=%d)\n", g, nV, v, dest);
    return false;
}

bool findPathDFS(Graph g, int nV, Vertex src, Vertex dest)
{
	fprintf(stderr, "[ERROR] >>> Entering findPathDFS(g=%d,nV=%d,src=%d,dest=%d)\n", g, nV, src, dest);
    Vertex v;
    for (v = 0; v < nV; v++) visited[v] = -1;
    visited[src] = src;
	fprintf(stderr, "[WARN] <<< Exiting findPathDFS(g=%d,nV=%d,src=%d,dest=%d)\n", g, nV, src, dest);
    return dfsPathCheck(g, nV, src, dest);
}

int main(void)
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int V = 6;
    Graph g = newGraph(V);
	fprintf(stderr, "[ERROR] main(): g → %d\n", g);

    Edge e;
    e.v = 0;
	fprintf(stderr, "[DEBUG] main(): e.v → %d\n", e.v);
    e.w = 1;
	fprintf(stderr, "[DEBUG] main(): e.w → %d\n", e.w);
    insertEdge(g, e);
    e.v = 0;
    e.w = 4;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 5;
    e.w = 4;
    insertEdge(g, e);
    e.v = 4;
    e.w = 2;
    insertEdge(g, e);
    e.v = 4;
    e.w = 3;
    insertEdge(g, e);
    e.v = 5;
    e.w = 3;
    insertEdge(g, e);
    e.v = 1;
    e.w = 2;
    insertEdge(g, e);
    e.v = 3;
    e.w = 2;
    insertEdge(g, e);

    int src = 0, dest = 5;
    if (findPathDFS(g, V, src, dest))
    {
        Vertex v = dest;
		fprintf(stderr, "[ERROR] main(): v → %d\n", v);
        while (v != src)
        {
            printf("%d - ", v);
            v = visited[v];
        }
        printf("%d\n", src);
    }
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
