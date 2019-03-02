#include <iostream>
#include <vector>
using std::cout;

void connectNodes(std::vector<std::vector<int>>& graph, int node1, int node2) {
  if (node1 < graph.size() && node2 < graph.size()) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
  }
}

void printGraph(const std::vector<std::vector<int>>& graph) {
  cout << "\n";
  for (const auto& row : graph) {
    for (const auto& col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
}
void printConnectedNodes(const std::vector<std::vector<int>>& graph, int node) {
  cout << "Nodes connected with node " << node << " are: ";
  for (size_t x = 0; x < graph[node].size(); x++) {
    if (graph[node][x] == 1)
      cout << x << " ";
  }
}

int main() {
  // 5 nodes of indexes from 0 to 4
  std::vector<std::vector<int>> graph{{0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0}};
  printGraph(graph);
  connectNodes(graph, 1, 2);
  connectNodes(graph, 1, 3);
  connectNodes(graph, 0, 1);

  printGraph(graph);
  printConnectedNodes(graph, 1);
}