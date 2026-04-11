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

void Graph::addEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end()) {
		return;
	}
	if (nodes.find(end) == nodes.end()) {
		return;
	}

	begin->addNeighbour(end);
	end->addNeighbour(begin);
}