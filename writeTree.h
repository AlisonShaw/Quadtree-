#ifndef WRITETREE
#define WRITETREE
#include "treeStructure.h"
void writeTree(Node *head);
void writeNode(FILE *fp, Node *node);
void printOut(FILE *fp, Node *node);


#endif