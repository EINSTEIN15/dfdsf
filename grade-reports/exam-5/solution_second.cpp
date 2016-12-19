#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector<int> uptree, int index)
{
    if (uptree[index]<=0)
      return index;
    else return find(uptree, uptree[index]);
}

int componentsUpTree(vector<int> uptree)
{
    // Your code here!
    return -1;
}

