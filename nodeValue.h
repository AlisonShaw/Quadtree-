#ifndef NODEVALUEH
#define NODEVALUEH
#include "treeStructure.h"
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void setflag( Node *node, double time );
int add_data_dependent( Node *node);
int remove_data_dependent( Node *node);

#endif
