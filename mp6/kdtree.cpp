/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;


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
 
   
  KDTreeHelper(points,0,newPoints.size()-1,0);
    
}


template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
  return NNHelper(0,points.size()-1,0,query);
}



template <int Dim>
Point<Dim> KDTree<Dim>::NNHelper(int L1,int L2,int curDim,const Point<Dim>& query) const 
{
  Point <Dim> currbest,target;
  int median=(L1+L2)/2;
  int splitdistance;
  int distance2;
  target=points[median];
  if(smallerDimVal(target,query,curDim)==true)
    {
      currbest=NNHelper(L1,median-1,curDim,query);
    }
  if(smallerDimVal(target,query,curDim)==false)
    {
      currbest=NNHelper(median+1,L2,curDim,query);
    }


  if(shouldReplace(query,currbest,target))
    {
      currbest=target;
    }
  return currbest;
}

template <int Dim>
void KDTree<Dim>::KDTreeHelper( vector<Point<Dim>> myvector, int L1, int L2,int d)
{
  int median=(L1+L2)/2;
  if(L1>L2)
    {
      return;
    }
 points[median]= quickselect(myvector,L1,L2,d);
  
    
      KDTreeHelper(myvector,median+1,L2,(d+1)%Dim);
      KDTreeHelper(myvector,L1,median-1,(d+1)%Dim);

    

  


}

template <int Dim>
Point <Dim> KDTree<Dim>::quickselect( vector<Point<Dim>>myvector, int L1, int L2, int curDim)
{

  
  int x= partition(myvector,L1,L2,curDim);
  int n=(L1+L2)/2;
  if(L1==L2)
    {
      return myvector[L1];
    }
 
  //  int x= partition(myvector,L1,L2,curDim);
  if(n==x)
    {
      return myvector[n];

    }
  if(n<x)
    {
      return quickselect(myvector,L1,x-1,n);

    }
  else
    {

      return quickselect(myvector,x+1,L2,n);

    }

}
//pseudocode on wikipedia for this
template <int Dim>
int KDTree<Dim>:: partition( vector<Point<Dim>> &myvector, int L1, int L2,int curDim)
{
  Point<Dim> pivotpoint = myvector[(L1+L2)/2];
  swap(myvector[(L1+L2)/2],myvector[L2]);
  int si=L1;
  int x=L1;
  while(x<L2)
    {
      if(myvector[x]<pivotpoint)
	{
	  swap(myvector[si],myvector[x]);
	  si++;
	}
      x++;
}
  swap(myvector[L2],myvector[si]);
  return si;

}
