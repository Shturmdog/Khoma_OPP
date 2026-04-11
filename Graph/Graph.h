#pragma once
#include <iostream>
#include <set>
using namespace std;

class Node {
	string name;
	set<Node*> neighbours;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
public:
	typedef set<Node*>::const_iterator node_iterator;

	Node(const string& aname) : name(aname) {};
	const string& getname() const { return name; }
	node_iterator nb_begin() const {
		return neighbours.begin();
	}
	node_iterator nb_end() const {
		return neighbours.end();
	}
	friend class Graph;
};

class Graph {
	set<Node*> nodes;
public:
	typedef set<Node*>::const_iterator node_iterator;

	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);

	node_iterator begin() const {
		return nodes.begin();
	}
	node_iterator end() const {
		return nodes.end();
	}
};
