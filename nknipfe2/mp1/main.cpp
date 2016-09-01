#include <iostream>
using namespace std;
#include "rgbapixel.h"
#include "png.h"
int main()
{
  RGBAPixel *ptr,*ptr2;

  PNG original("in.png");
  PNG new_image(original.width(),original.height()); 
  for(size_t x=0;x<original.width();x++)
    {
      for(size_t y=0;y< original.height();y++)
	{
	 
	  
	  *new_image.operator()(original.width()-x-1,original.height()-y-1)=*original(x,y);
    
	 
	}
  
    }


  new_image.writeToFile("out.png");
}
