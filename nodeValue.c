#include "math.h"
#include "stdio.h"
#include "treeStructure.h"

// Evaluate function at centre of quadtree node
double value( double x, double y, double time );

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);
  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}
void setflag( Node *node, double time )
{
    if(node==NULL) return ;
    if(node->child[0]==NULL)
    {
    if(nodeValue(node,time)>0.5)
    node->flag=1;
    if(nodeValue(node,time)<-0.5)
    node->flag=-1;
    }
    int i;
    for(i=0;i<4;i++)
    setflag(node->child[i],time);
    return ;
}
int add_data_dependent( Node *node)
{
    int ans=0;
    if(node==NULL) return 0;
    int i;
    if(node->child[0]==NULL&&node->flag==1)
    {
        makeChildren(node);
        return 1;
    }
    for(i=0;i<4;i++)
    ans+=add_data_dependent(node->child[i]);

    return ans;
}
int remove_data_dependent( Node *node)
{
    int ans=0;
    if(node==NULL||node->child[0]==NULL) return 0;
    int i,f=1;
        for(i=0;i<4;i++)
        {
            if(node->child[0]->flag!=-1)
                f=0;
        }
        if(f)
        {
            removeChildren(node);
            return 1;
        }
        for(i=0;i<4;i++)
        ans+=remove_data_dependent(node->child[i]);
    return ans;
}
