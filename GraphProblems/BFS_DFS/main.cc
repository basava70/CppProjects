/* Copyright 2023 Owned by Seshadri Basava
 * DFS and BFS pattern
 * Given a graph print out the dfs and bfs pattern
 * Written on July 14
 */
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
  void DFS(int root);
  void DFS_vist(int root);
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

void Graph::DFS_vist(int root) {
  visited[root] = true;
  std::cout << root << " ";
  std::list<int>::iterator i;
  for (i = adj_lists[root].begin(); i != adj_lists[root].end(); i++) {
    if (!visited[*i])
      DFS_vist(*i);
  }
}

void Graph::DFS(int root) {
  std::cout << "Printing DFS from vertex " << root << std::endl;
  for (int i = 0; i < vertices; i++)
    visited[i] = false;

  DFS_vist(root);
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
  g.DFS(0);
  g.DFS(1);
  g.DFS(2);
}
