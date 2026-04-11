#include <iostream>
#include <locale.h>
#include "Graph.h"
using namespace std;

int main() {
    Graph g;
    setlocale(LC_ALL, "RU");

    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");

    g.addNode(a);
    g.addNode(b);
    g.addNode(c);
    cout << "Nodes: " << distance(g.begin(), g.end()) << " (3)\n";

    g.addEdge(a, b);
    g.addEdge(b, c);
    cout << "Neigbours B: ";
    for (auto it = b->nb_begin(); it != b->nb_end(); ++it)
        cout << (*it)->getname();
    cout << " (AC)\n";

    g.removeNode(b);
    cout << "Nodes after remove B: " << distance(g.begin(), g.end()) << " (2)\n";
    cout << "Neighbours A: " << (a->nb_begin() == a->nb_end() ? "0" : "есть") << " (0)\n";

    return 0;
}