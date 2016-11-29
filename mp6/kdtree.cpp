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


//There is a passage on this in wikipedia explaining how to do this. Thank God.
template <int Dim>
Point<Dim> KDTree<Dim>::NNHelper(int L1,int L2,int curDim,const Point<Dim>& query) const 
{
  Point <Dim> currbest,target,dummy;
  int median=(L1+L2)/2;
  int splitdistance;
  int distance2;
  //  target=points[median];
  //means we are at the end
  
      //these are testing left and right
  if(smallerDimVal(points[median],query,curDim)==true)
    {
      currbest=NNHelper(median+1,L2,(curDim+1)%Dim,query);
    }
  else// if(smallerDimVal(target,query,curDim)==false)
    {
      currbest=NNHelper(L2,median-1,(curDim+1)%Dim,query);
    }
    
  //find one that is closest
  if(shouldReplace(query,currbest,points[median]))
    {
      currbest=points[median];
    }
  //euclidiean distance probably should have made a helper function for this
  for(int i=0;i<Dim;i++)
    {
      distance2=distance2+(pow(currbest[i]-query[i],2));
      //distance2=distance2+(pow(potential[i]-target[i],2));
    }
  /* (the squared dist between [the value in the currentDim of the point splitting the plane] and [the value in the currentDim of the target point] ), with (the squared dist between the current best point and the search query)Piazza Post*/ 
  // splitdistance =(query[curDim]-target[curDim])*(query[curDim]-target[curDim]);
  splitdistance=pow(query[curDim]-points[median][curDim],2);
 
  if(splitdistance<=distance2)
    {

      if(smallerDimVal(points[median],query,curDim)==true)
	{
	  dummy=NNHelper(L1,median-1,(curDim+1)%Dim,query);
	}
     else //      if(smallerDimVal(target,query,curDim)==false)
	{

	  dummy=NNHelper(median+1,L2,(curDim+1)%Dim,query);

	}


    }
  if(shouldReplace(query,currbest,dummy)==true)
    {
      currbest=dummy;
    }
      return currbest;
}

template <int Dim>
void KDTree<Dim>::KDTreeHelper( vector<Point<Dim>> &myvector, int L1, int L2,int d)
{
  
  if(L1>L2)
    {
      return;
    }
  int median=(L1+L2)/2;
  
  points[median]= quickselect(myvector,L1,L2,d,median);
  KDTreeHelper(myvector,L1,median-1,(d+1)%Dim);
     KDTreeHelper(myvector,median+1,L2,(d+1)%Dim);
    
    
    
  


}

template <int Dim>
Point<Dim> KDTree<Dim>::quickselect( vector<Point<Dim>>&myvector, int L1, int L2, int curDim,int k)
{
  //  int y=(L2 - L1 + 1) == 0 ? 1 : (L2 - L1 + 1);
  int median=(L1+L2)/2;
int  pivotindex= partition(myvector,L1,L2,median,curDim);
 if(L1==L2)
   {
     return myvector[L1];
   }
 
    
      if(k==pivotindex)
	{
	  return myvector[k];
	}
      else if(k<pivotindex)
	{
	  return quickselect(myvector,L1,pivotindex-1,curDim,median);
	}
      else
	{
	  return quickselect(myvector,pivotindex+1,L2,curDim,median);

	}
   
    
 
}
//pseudocode on wikipedia for this
template <int Dim>
int KDTree<Dim>:: partition( vector<Point<Dim>> &myvector, int L1, int L2,int k,int curDim)
{
  
  Point<Dim> pivotpoint = myvector[(L1+L2)/2];
  swap(myvector[(L1+L2)/2],myvector[L2]);
  int si=L1;
  int n=L1;
  // for(int n=L1;n<L2;n++)
  while(n<L2)
{
      if(smallerDimVal(myvector[n],pivotpoint,curDim)==true)
	{
	  swap(myvector[si],myvector[n]);
	  si++;
	}
      n++;
}
  swap(myvector[L2],myvector[si]);
  return si;

}
