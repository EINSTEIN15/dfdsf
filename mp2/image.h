#ifndef _IMAGE_H
#define _IMAGE_H

#include <cstdint>
#include <iostream>
#include "png.h"
using std::uint8_t;
class Image:public PNG
{
 public:
  using PNG::PNG;
  void flipleft();
  void adjustbrightness (int r, int g, int b);
  void invertcolors();
  RGBAPixel * ptr1= new RGBAPixel(); 
   













};

#endif
