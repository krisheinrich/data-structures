#include <iostream>
#include <vector>
#include <algorithm>

#include "Node.h"

Node::Node(int n) {
  value = n;
}

void Node::addChild(Node child) {
  children.push_back(child);
}

class TreeHeight {
  int n;
  std::vector<int> parents;
  std::vector<Node> nodes;

public:
  void read() {
    std::cin >> n;
    parents.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> parents[i];
  }

  int compute_height() {
    // Build tree
    int root_index;
    // Create array of nodes
    for (int i = 0; i < n; ++i)
      nodes[i] = new Node();
    // Read each parent index
    for (int child_index = 0; child_index < parents.size(); ++child_index ) {
      int parent_index = parents[child_index];
      if (parent_index == -1)
        root_index = child_index;
      else
        nodes[parent_index].addChild(nodes[child_index]);

    }
    // Traverse to deepest element with breadth-first
    // count height from there

    //***************************************************************
    // Naive solution:
    // For each label in input vector:
    //   Calculate depth of label
    //   MaxHeight <-- max(depth, MaxHeight)
    //***************************************************************
    /*
    int maxHeight = 0;
    for (int index = 0; index < n; index++) {
      int height = 0;
      for (int node = index; node != -1; node = parent[node])
        height++;
      maxHeight = std::max(maxHeight, height);
    }
    return maxHeight;
    */
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
