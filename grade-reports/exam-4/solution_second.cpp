#include "common.h"
#include "quadtree.h"

#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

int Quadtree::tallyNeighbors(RGBAPixel const & target, 
    QuadtreeNode const * curNode, int tolerance) const 
{
    //YOUR CODE HERE
  int i=0;
  if(curNode->nwChild!=NULL)
    {
      
      RGBAPixel current=curNode->element;
      if((current.red - target.red) * (current.red - target.red)
                + (current.green - target.green) * (current.green - target.green)
	 + (current.blue - target.blue) * (current.blue - target.blue)<tolerance)
	{

	  i++;

	}
      tallyNeighbors(target,curNode->nwChild,tolerance);
      tallyNeighbors(target,curNode->nwChild,tolerance);
      tallyNeighbors(target,curNode->nwChild,tolerance);
      tallyNeighbors(target,curNode->nwChild,tolerance);
      
    }
  

      return i;
    


}

void Quadtree::prunish(int tolerance, double percent) 
{
    //YOUR CODE HERE

  prunish(root,tolerance,resolution,percent);




} 
void Quadtree::prunish(QuadtreeNode * curNode, int tolerance, int res, double percent) 
{
    //YOUR CODE HERE
  int nearestnodes=tallyNeighbors(curNode->element,curNode,tolerance);
  double mypercent= nearestnodes/(res*res);
  if(mypercent>=percent)
    {
  
      clear(curNode->nwChild);
      
      clear(curNode->neChild);
      
      clear(curNode->swChild);
      
      clear(curNode->seChild);
      return;
}

 prunish(curNode->nwChild,tolerance,res/2,percent);
 prunish(curNode->neChild,tolerance,res/2,percent);
 prunish(curNode->swChild,tolerance,res/2,percent);
 prunish(curNode->seChild,tolerance,res/2,percent);




}
