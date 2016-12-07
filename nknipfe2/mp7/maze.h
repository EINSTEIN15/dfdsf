/* Your code here! */
#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <iostream>
#include "png.cpp"
using namespace std;
class SquareMaze
{
 public:
  SquareMaze();
  void makeMaze(int width,int height);
  bool canTravel(int x,int y,int dir) const;
  void setWall(int x,int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG* drawMaze() const;
  PNG* drawMazeWithSolution();
 private:
  vector<int> v;
  vector<bool>rightwall;
  vector<bool>leftwall;
  int mazewidth;
  int mazeheight;
};
#endif
