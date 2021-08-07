#include <stdio.h>
#include <string.h>

#define INFINITY 9999// infinity
#define MaxVertexNum 100   // 顶点数目的最大值
typedef struct Mgraph{
	char Vex[MaxVertexNum];   // 顶点表
	int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
	int vexnum, arcnum;  // 图的当前顶点数和边数/弧数
} MGraph;

//static int E[MaxVertexNum][MaxVertexNum];

void InitMgraph(Mgraph *G) {
	for (int i=0; i<MaxVertexNum; i++) {
		for (int j=0; j<MaxVertexNum; j++) {
			G->Edge[i][j] = 0;
		}
	}

	G->vexnum = 0;
	G->arcnum = 0;
}

void InsertVexTex(Mgraph *G, char v) {
	G->Vex[G->vexnum] = v;
	G->Edge[0][G->vexnum] = v;
	G->Edge[G->vexnum][0] = v;

	G->vexnum++;
}

// 添加边
void AddEdge(Mgraph &G, int *E, char v, char x) {
	int index_v, index_x;
	for (int i = 0; i<G.vexnum; i++) {
		if (G.Vex[i] == v) index_v = i;
		if (G.Vex[i] == x) index_x = i;
	}

	//E[v][x] = 1;
	*(E+index_v*MaxVertexNum+index_x) = 1;
	//E[x][v] = 1;
	*(E+index_x*MaxVertexNum+index_v) = 1;

	G.arcnum ++;	
}


// 列出与顶点v相邻的顶点
int* Neighbors(Mgraph *G, char v) {
	int index_v = -1;
	for (int i=0; i<G->vexnum; i++) {
		if (G->Vex[i] == v) {
			index_v = i;
		}
	}

	if (index_v == -1) {
		printf("index_v is -1!\n");
		return &index_v;
	}

	int neighbors[MaxVertexNum];
	for(int i=0; i<MaxVertexNum; i++) {
		neighbors[i] = -1;
	}

	int index_ngb = 0;
	for (int i=0; i<G->vexnum; i++) {
		if (G->Edge[index_v][i] == 1) {
			neighbors[index_ngb++] = i;
		}
	}

	return neighbors;
}