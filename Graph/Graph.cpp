#include "Graph.h"
#include <iostream>
#include <set>
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

void Graph::addNode(Node* node) {
	nodes.insert(node);
}

void Graph::removeEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end()) {
		return;
	}
	if (nodes.find(end) == nodes.end()) {
		return;
	}

	begin->removeNeighbour(end);
	end->removeNeighbour(begin);
}

void Node::addNeighbour(Node* neighbour) {
	neighbours.insert(neighbour);
}

void Node::removeNeighbour(Node* neighbour) {
	neighbours.erase(neighbour);
}

bool BFS::connected(Node* begin, Node* end)
{
	if (!begin || !end)
		return false;

	queue<Node*> nodes;
	nodes.push(begin);
	set<Node*> visited;

	while (!nodes.empty())
	{
		Node* next = nodes.front();
		nodes.pop();

		if (next == end)
			return true;

		visited.insert(next);

		for (Node::node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
	}
	return false;
}