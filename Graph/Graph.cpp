#include <iostream>
#include <set>
#include "Graph.h"
using namespace std;

void Graph::removeNode(Node* node) {
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		(*it)->removeNeighbour(node);
	}

	nodes.erase(node);
	delete node;
}