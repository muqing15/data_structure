#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Mgraph G;

int main() {
	InitMgraph(&G);

	InsertVexTex(&G, 'a');
	InsertVexTex(&G, 'b');
	InsertVexTex(&G, 'c');
	InsertVexTex(&G, 'd');

	AddEdge(G, *G.Edge, 'a', 'b');
	AddEdge(G, *G.Edge, 'a', 'd');
	AddEdge(G, *G.Edge, 'b', 'c');


	int* n = Neighbors(&G, 'a');

	int index = 0;
	while(n[index] != -1) {
		printf("G.Vex[] is: %c\n", G.Vex[n[index++]]);
	}
	free(n);
}