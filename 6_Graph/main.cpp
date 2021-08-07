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
	for(int i = 0; i < G.vexnum; i++) {
		printf("vextex is: %c\n", G.Vex[i]);
	}

	AddEdge(G, *G.Edge, 'a', 'b');
	AddEdge(G, *G.Edge, 'a', 'd');
	AddEdge(G, *G.Edge, 'b', 'c');


	int* n = Neighbors(&G, 'a');

	for(int i=0; i<5; i++) {
		printf("%d\n", n[i]);
	}

	int index = 0;
	while(n[index] != -1) {
		printf("G.Vex[] is: %c\n", G.Vex[n[index++]]);
	}
}