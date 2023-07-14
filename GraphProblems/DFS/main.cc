/* Copyright 2023 Owned by Seshadri Basava
 * DFS pattern
 * Given a graph print out the dfs pattern
 * Written on July 13
 */
#include <iostream>
#include <iterator>
#include <list>

class Graph {
  std::list<int> *adj_lists;
  int vertices;

public:
  // constructors
  Graph();
  Graph(int v);

  // destructor
  ~Graph();
  void DFS_vist(int root, bool visited[]);

  void addEdge(int source, int destination);
  void printGraph();
  void DFS(int root);
};

Graph::Graph() {}
Graph::Graph(int v) {
  adj_lists = new std::list<int>[v];
  vertices = v;
}

Graph::~Graph() { delete[] adj_lists; }

void Graph::addEdge(int source, int destination) {
  adj_lists[source].push_back(destination);
  adj_lists[destination].push_back(source);
}

void Graph::printGraph() {
  std::cout << "Plotting graph " << std::endl;
  for (int i = 0; i < vertices; i++) {
    std::cout << "vertex " << i;
    for (auto &node : adj_lists[i])
      std::cout << " -> " << node;
    printf("\n");
  }
}

void Graph::DFS_vist(int root, bool visited[]) {
  visited[root] = true;
  std::cout << root << " ";
  std::list<int>::iterator i;
  for (i = adj_lists[root].begin(); i != adj_lists[root].end(); i++) {
    if (!visited[*i])
      DFS_vist(*i, visited);
  }
}

void Graph::DFS(int root) {
  std::cout << "Printing DFS from vertex " << root << std::endl;
  bool *visited = new bool[vertices];
  for (int i = 0; i < vertices; i++)
    visited[i] = false;

  DFS_vist(root, visited);
  std::cout << std::endl;
}

int main() {
  int vertices = 7;

  // create graph
  Graph g(vertices);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  // g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(4, 6);
  g.addEdge(5, 6);

  g.printGraph();

  g.DFS(0);
  g.DFS(1);
  g.DFS(2);
}
