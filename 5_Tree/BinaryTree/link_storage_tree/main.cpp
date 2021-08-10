#include "Tree.h"

int main() {
    Tree t;
    initTree(t);

    addNode(t, 'a');
    addNode(t, 'h');
    addNode(t, 'e');

    levelVisit(t, NULL, printNode);

    return 0;
}