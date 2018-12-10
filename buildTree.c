#include <stdio.h>
#include <math.h>
#include "treeStructure.h"
Node *makeNode(double x, double y, int level)
{

    int i;
    Node *node = (Node *)malloc(sizeof(Node));
    node->level = level;
    node->xy[0] = x;
    node->xy[1] = y;
    node->flag=0;
    for (i = 0; i < 4; ++i)
        node->child[i] = NULL;

    return node;
}

// split a leaf nodes into 4 children

void makeChildren(Node *parent)
{

    double x = parent->xy[0];
    double y = parent->xy[1];

    int level = parent->level;

    double hChild = pow(2.0, -(level + 1));

    parent->child[0] = makeNode(x, y, level + 1);
    parent->child[1] = makeNode(x + hChild, y, level + 1);
    parent->child[2] = makeNode(x + hChild, y + hChild, level + 1);
    parent->child[3] = makeNode(x, y + hChild, level + 1);

    return;
}


void growTree(Node *parent)
{
    //如果parent为空 返回
    if(parent==NULL) return ;
    //如果是叶节点 ，创建子节点
    if(parent->child[0]==NULL)
        makeChildren(parent);
    //否则对它的子节点调用此函数
    else {
        growTree(parent->child[0]);
        growTree(parent->child[1]);
        growTree(parent->child[2]);
        growTree(parent->child[3]);
    }
    return;
}
void destroyTree(Node *head)
{
    int i;
    if (head == NULL)
        return;
    for (i = 0; i < 4; ++i)
    {
        destroyTree(head->child[i]);
    }
    free(head);
    return;
}
void removeChildren (Node * parent)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        Node *t=parent->child[i];
        parent->child[i]=NULL;
        free(t);
    }
    return;
}
