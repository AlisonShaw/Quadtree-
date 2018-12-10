#ifndef BUILDTREE
#define BUILDTREE
#include "treeStructure.h"
Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent);
void growTree(Node *parent);
void destroyTree(Node *head);
void removeChildren (Node * parent);

#endif
