/**
 * Copyright owned by Seshadri Basava, 2023
 * BFS pattern
 * Given a graph print the bfs pattern
 * Written on July 14
 **/

#include <iostream>
#include <iterator>
#include <list>

class Graph {
  std::list<int> *adj_lists;
  int vertices;
  bool *visited;

public:
  // constructors
  Graph();
  Graph(int v);

  // destructor
  ~Graph();

  void addEdge(int source, int destination);
  void printGraph();
  void BFS(int root);
};

Graph::Graph() {}
Graph::Graph(int v) {
  adj_lists = new std::list<int>[v];
  vertices = v;
  visited = new bool[vertices];
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

void Graph::BFS(int root) {
  for (int i = 0; i < vertices; i++)
    visited[i] = false;
  std::cout << "Printing BFS pattern for graph starting with " << root
            << std::endl;
  std::list<int> queue;
  queue.push_back(root);

  while (!queue.empty()) {
    int current_vertex = queue.front();
    visited[current_vertex] = true;
    std::cout << current_vertex << " ";
    queue.pop_front();

    std::list<int>::iterator i;
    for (i = adj_lists[current_vertex].begin();
         i != adj_lists[current_vertex].end(); i++) {
      if (!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
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

  g.BFS(0);
  g.BFS(1);
  g.BFS(2);
}
