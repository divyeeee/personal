//adj list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    int numVertices;
    Node *adjLists[5];
} Graph;

void createGraph(Graph *graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
}

Node* createNode(int vertex) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph->numVertices && v >= 0 && v < graph->numVertices) {
        Node *newNode = createNode(v);
        newNode->next = graph->adjLists[u];
        graph->adjLists[u] = newNode;
    } else {
        printf("Invalid edge!\n");
    }
}

void displayAdjList(const Graph *graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node *temp = graph->adjLists[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void transposeGraph(const Graph *graph, Graph *transpose) {
    createGraph(transpose, graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            addEdge(transpose, temp->vertex, i);
            temp = temp->next;
        }
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
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
    displayAdjList(&graph);

    transposeGraph(&graph, &transpose);
    printf("\nTranspose Graph:\n");
    displayAdjList(&transpose);

    freeGraph(&graph);
    freeGraph(&transpose);

    return 0;
}
