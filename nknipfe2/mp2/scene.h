#ifndef _SCENE_H
#define _SCENE_H
#include "image.h"
#include "png.h"
#include "rgbapixel.h"
class Scene
{
  
 public:
  Scene (int max);
  ~Scene();
  Scene(const Scene &source);
  const Scene & operator= (const Scene &source);
  void changemaxlayers(int newmax);
  void addpicture (const char *FileName, int index, int x, int y);
  void changelayer(int index, int newindex);
  void translate (int index, int xcoord, int ycoord);
  void deletepicture(int index);
  Image* getpicture(int index) const;
  Image drawscene() const;
  void m_copy(Scene const &source);
  void m_clear();

private:
  int m_max;
  int * xcoord;
  int * ycoord;
  int ** rows;
 
 






};

#endif
