/* Copyright 2023 Owned by Seshadri Basava
 * Adjaceny list code as part of graph theory problems
 * Given a graph print out the adjaceny list
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

  void addEdge(int source, int destination);
  void printGraph();
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

int main() {
  int vertices = 7;

  // create graph
  Graph g(vertices);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(4, 6);
  g.addEdge(5, 6);

  g.printGraph();
}
