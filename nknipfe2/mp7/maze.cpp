/* Your code here! */
#include "maze.h"
#include <vector>
#include <iostream>
#include "dsets.cpp"
using namespace std;

SquareMaze::SquareMaze ()
{

}
void SquareMaze::makeMaze(int width, int height)
{
  this->mazeheight=height;
  this->mazewidth=width;
  DisjointSets set;
  set.addelements(height*width);









}
bool SquareMaze::canTravel(int x,int y,int dir) const
{



}


void SquareMaze::setWall(int x,int y, int dir, bool exists)
{
  int tmp=y*mazewidth+x;
  if(dir==0)
    {
      rightwall[tmp]=exists;
      
    }
  else if(dir==1)
    {
      bottomwall[tmp]=exists;
      
    }


}


vector<int> SquareMaze::solveMaze()
{



}


PNG *SquareMaze:: drawMaze () const
{




}
PNG* SquareMaze:: drawMazeWithSolution()
{




}
