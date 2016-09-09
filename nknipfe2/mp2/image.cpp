#include "image.h"
#include "rgbapixel.h"


void Image :: flipleft()
{
  
  for(size_t x=0;x<(this->width())/2;x++)
    {
      for(size_t y=0;y< (this->height());y++)
        {

	   *ptr1 = *(this->operator()(x,y));
	   * ((this->operator()(x,y)))=*(this->operator()(this->width()-x-1,y));
	   * ((this->operator()(this->width()-x-1,y)))= *ptr1;
          
	  

        }

    }


  

}

void Image :: adjustbrightness(int r, int g, int b)
{
  
  for (size_t xi = 0; xi < this->width(); xi++) {
    for (size_t yi = 0; yi < this->height(); yi++) {
            
      if (((this->operator()(xi,yi))->red+r)>255)
	((this->operator()(xi,yi))->red)=255;
      else if(((this->operator()(xi,yi))->red+r)<0)
	((this->operator()(xi,yi))->red)=0;
      else
	((this->operator()(xi,yi))->red)=((this->operator()(xi,yi))->red+r);
      if (((this->operator()(xi,yi))->blue +b)>255)
	((this->operator()(xi,yi))->blue)=255;
      else if(((this->operator()(xi,yi))->blue+b)<0)
	((this->operator()(xi,yi))->blue)=0;
      else
	((this->operator()(xi,yi))->blue)=((this->operator()(xi,yi))->blue +b);
      if(((this->operator()(xi,yi))->green+g)>255)
	((this->operator()(xi,yi))->green)=255;
      else if(((this->operator()(xi,yi))->green)<0)
	((this->operator()(xi,yi))->green)=0;
      else
	((this->operator()(xi,yi))->green)= ((this->operator()(xi,yi))->green+g);


        }
    }
    



}

void Image :: invertcolors()
{
   for (size_t x2 = 0; x2 < this->width(); x2++) {
      for (size_t y2 = 0; y2 < this->height(); y2++) {
            

	(this->operator()(x2,y2))->red=(255- ((this->operator()(x2,y2))->red));
	(this->operator()(x2,y2))->blue=(255-((this->operator()(x2,y2))->blue));
	(this->operator()(x2,y2))->green=(255-((this->operator()(x2,y2))->green));


        } 



}
}
