/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <math.h>
#include <stdlib.h>
#include <algorithm>

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
  if(first[curDim]==second[curDim])
    {
      return true;
    }
  else if((first[curDim])<( second[curDim]))
    {
      return true;

    }
  else
    {
  return false;
    }

 }

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
  
  int distance1;
  int distance2;
  for(int i=0;i<Dim;i++)
    {
  distance1=distance1+(pow(currentBest[i]-target[i],2));
  distance2=distance2+(pow(potential[i]-target[i],2));
    }
if(distance2==distance1)
  {
    return true;

  }
 if(distance2<distance1)
   {
     return true;

   }
 else //if(distance2>distance1)
   {
     return false;
   }
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
  points=newPoints;
 
   
  KDTreeHelper(points,0,newPoints.size(),0);
    
}


template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return Point<Dim>();
}

template <int Dim>
void KDTree<Dim>::KDTreeHelper( vector<Point<Dim>> myvector, int L1, int L2,int d)
{/*
  int median=(L1+L2)/2;
  if(L1==L2)
    {
      return;
    }
  quickselect(myvector,L1,L2,d);
  if(median<L2)
    {
      KDTreeHelper(myvector,median+1,L2,(d+1)%Dim);

    }
  else if(median>L1)
    {
      KDTreeHelper(myvector,L1,median-1,(d+1)%Dim);

    }

  


}

template <int Dim>
void KDTree<Dim>::quickselect( vector<Point<Dim>>myvector, int L1, int L2, int curDim)
{
  if(L1==L2)
    {
      return;
    }
 
  int pivotpoint= L1+floor((rand()%(L2-L1+1)));
  pivotpoint=Pivot(myvector,L1,L2,pivotpoint);
 
   if(curDim<pivotpoint)
    {
      return quickselect(myvector,L1,pivotpoint-1,curDim);

    }
  else
    {
      return quickselect(myvector,pivotpoint+1,L2,curDim);

    }
 */

}

template <int Dim>
    int KDTree<Dim>::Pivot( vector<Point<Dim>> &myvector, int L1, int L2,int pivotpoint)
{
  /*int pivotindex= L1-1;
  // swap(myvector[pivotindex],myvector[L2]);
  for(int i=L1;i<L2;i++)
    {
      if(myvector[i]<myvector[L2])
	{
	  pivotindex++;
	  //	  swap(myvector[pivotindex],myvector[i]);
	  }
    }

  pivotindex++;
  //  swap(myvector[pivotindex],myvector[L2]);
  return pivotindex;
  */
}
