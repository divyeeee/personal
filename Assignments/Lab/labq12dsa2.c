//adj matrix
#include <stdio.h>

typedef struct {
    int numVertices;
    int adjMatrix[5][5];
} Graph;


void createGraph(Graph *graph, int vertices) {
    graph->numVertices = vertices;

    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}


void addEdge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph->numVertices && v >= 0 && v < graph->numVertices) {
        graph->adjMatrix[u][v] = 1;
    } else {
        printf("Invalid edge!\n");
    }
}

void displayAdjMatrix(const Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}


void transposeGraph(const Graph *graph, Graph *transpose) {
    transpose->numVertices = graph->numVertices;
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            transpose->adjMatrix[j][i] = graph->adjMatrix[i][j];
        }
    }
}

int main() {
    Graph graph;
    Graph transpose;

    createGraph(&graph, 5);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 0);
    addEdge(&graph, 4, 1);

    printf("Original Graph:\n");
    displayAdjMatrix(&graph);

    transposeGraph(&graph, &transpose);
    printf("\nTranspose Graph:\n");
    displayAdjMatrix(&transpose);

    return 0;
}