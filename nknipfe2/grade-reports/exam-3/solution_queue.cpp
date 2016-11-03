#include "common.h"
#include <iostream>
#include <queue>

/*
  As a reminder, useful STL queue methods include:
  empty : Test whether container is empty (public member function)
  size : Return size (public member function)
  front : Access next element (public member function)
  push : Insert element (public member function)
  pop : Remove next element (public member function)
*/

using namespace std;

int get(queue<int> &q, int pos)
{
  queue<int> q1;
  q1=q;
  
  if(q1.size()!=0 and q1.size()>=pos)
    {

      if(pos==0)
	{

	  return q.front();

	}

      for(int i=0; i<pos; i++)
	{
	  q1.pop();

	}
      return q1.front();
    }

else
  {

    return -1;
  }


}
