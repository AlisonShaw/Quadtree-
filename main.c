#include <stdio.h>
#include "buildTree.h"
#include "writeTree.h"
#include "treeStructure.h"
void task1();
void task2_1();
void task2_2();
void task3();
int main(int argc, char **argv)
{

    task3();
    return 0;
}
void task1()
{
    Node *head = NULL;
    head = makeNode(0.0, 0.0, 0);
    makeChildren(head);
    writeTree( head );
    destroyTree(head);
}
void task2_1()
{
    Node *head = NULL;
    head = makeNode(0.0, 0.0, 0);
    makeChildren(head);
    growTree(head);
    growTree(head);
    //从一个1级节点中删除子节点
    removeChildren(head->child[0]->child[0]);
    writeTree( head );
    destroyTree(head);
}
void task2_2()
{
    Node *head = NULL;
    head = makeNode(0.0, 0.0, 0);
    makeChildren(head);
    growTree(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[1]);
    //从一个1级节点中删除子节点
    removeChildren(head->child[0]->child[0]);
    writeTree( head );
    destroyTree(head);
}
void task3()
{
    Node *head = NULL;
    // make the head node
    head = makeNode(0.0, 0.0, 0);
    // make a tree
    makeChildren(head);
    growTree(head);
    growTree(head);
    growTree(head);//调用三次函数得到LEVEL3的四叉树
    setflag(head,0);
    int n1=add_data_dependent(head);
    int n2=remove_data_dependent(head);
    writeTree( head );
    printf("add:%d remove:%d\n",n1,n2);
    destroyTree(head);
}
