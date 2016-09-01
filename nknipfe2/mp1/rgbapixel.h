#ifndef _RGBAPIXEL_H
#define _RGBAPIXEL_H


#include <cstdint>
#include <iostream>

using std::uint8_t;
class RGBAPixel
{
 public:
  RGBAPixel();
  RGBAPixel(uint8_t red, uint8_t green, uint8_t blue);
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;





};















#endif


