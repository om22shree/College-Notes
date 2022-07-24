#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  char name;
  int ip;
  int mac;
  struct node *next;
};

struct node* createNode(int, char, int, int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v, char name, int ip, int mac) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->name = name;
  newNode->ip = ip;
  newNode->mac = mac;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}


void connect(struct Graph* graph, struct node s, struct node d) {
  struct node* newNode = createNode(d.vertex, d.name, d.ip, d.mac);
  newNode->next = graph->adjLists[s.vertex];
  graph->adjLists[s.vertex] = newNode;
  newNode = createNode(s.vertex, s.name, s.ip, s.mac);
  newNode->next = graph->adjLists[d.vertex];
  graph->adjLists[d.vertex] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createAGraph(5);
  struct node a = {0, 'a', 11, 111};
  struct node b = {1, 'b', 22, 222};
  struct node c = {2, 'c', 33, 333};
  struct node d = {3, 'd', 44, 444};
  struct node e = {4, 'e', 55, 555};

  connect(graph, a, b);
  connect(graph, b, c);
  connect(graph, c, d);
  printGraph(graph);
  return 0;
}