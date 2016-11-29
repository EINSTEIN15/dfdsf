/* Your code here! */
#include "dsets.h"
#include <iostream>
#include <vector>
using namespace std;



void DisjointSets::addelements	(int num)
{
  for(int i=0;i<num;i++)
    {
      myvector.push_back(-1);
    }
}

int DisjointSets::find	(int elem)	
{
  if(myvector[elem]<0)
    {
      return elem;
    }
  else
    {

      return myvector[elem]=find(myvector[elem]);

    }
}
void DisjointSets::setunion	(int a,int b)		
{
  int x=find(a);
  int y=find(b);
  

  int newSize=myvector[x]+myvector[y];
  if(myvector[x]<=myvector[y])
    {
      myvector[y]=x;
      myvector[x]=newSize;

    }
  else
    {
      myvector[x]=y;
      myvector[y]=newSize;


    }

}

