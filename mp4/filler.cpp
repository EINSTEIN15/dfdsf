 /**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 *
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"

animation filler::dfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */

  solidColorPicker tmp(fillColor);

  
  return filler:: fill <Stack>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::dfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */

  gridColorPicker tmp(gridColor,gridSpacing);
  return filler::fill<Stack>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::dfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */




  gradientColorPicker tmp(fadeColor1,fadeColor2,radius,x,y);

  return filler::fill <Stack>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::dfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
  animation here;
  here =filler::fill<Stack>(img,x,y,fillColor,tolerance,frameFreq);
  return here;
}

animation filler::bfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
  solidColorPicker tmp(fillColor);
  return filler::fill<Queue>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::bfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */

  gridColorPicker tmp(gridColor,gridSpacing);



  return filler::fill<Queue>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::bfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */

  gradientColorPicker tmp(fadeColor1,fadeColor2,radius,x,y);
  return filler::fill<Queue>(img,x,y,tmp,tolerance,frameFreq);
}

animation filler::bfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
  animation here;
  here= filler::fill<Queue>(img,x,y,fillColor,tolerance,frameFreq);
  return here;
}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       int tolerance, int frameFreq)
{
    /**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure. Then, until the structure is
     * empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure.
     *
     *        If it has not been processed before and if its color is
     *        within the tolerance distance (up to and **including**
     *        tolerance away in square-RGB-space-distance) to the original
     *        point's pixel color [that is, \f$(currentRed - OriginalRed)^2 +
              (currentGreen - OriginalGreen)^2 + (currentBlue -
              OriginalBlue)^2 \leq tolerance\f$], then:
     *        1.    indicate somehow that it has been processed (do not mark it
     *              "processed" anywhere else in your code)
     *        2.    change its color in the image using the appropriate
     *              colorPicker
     *        3.    add all of its neighbors to the ordering structure, and
     *        4.    if it is the appropriate frame, send the current PNG to the
     *              animation (as described below).
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! The order you should put
     *        neighboring pixels **ONTO** the queue or stack is as follows:
     *        **RIGHT(+x), DOWN(+y), LEFT(-x), UP(-y). IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.** To reiterate, when you are exploring (filling out)
     *        from a given pixel, you must first try to fill the pixel to
     *        it's RIGHT, then the one DOWN from it, then to the LEFT and
     *        finally UP. If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq.
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     */

     
  OrderingStructure<RGBAPixel *> structure;
  OrderingStructure<unsigned long int>xc;
  OrderingStructure<unsigned long int>yc;
    
  
  int marked[300][300];
  //  bool marked[X1][Y1]=false;
unsigned long  int x1=0;
unsigned long int y1=0;
 unsigned long int x2=x;
 unsigned long int y2=y;
  int tmp;
  animation anime;
  RGBAPixel originalpixel;
  RGBAPixel *currentpixel;
  originalpixel=*(img(x,y));
  int framecount=0;
  //int g;
  //int b;
  //int r;
  /* tmp=(currentpixel.red-originalpixel.red)*(currentpixel.red-originalpixel.red)+(currentpixel.blue-originalpixel.blue)*(currentpixel.blue-originalpixel.blue)+(currentpixel.green-originalpixel.green)*(currentpixel.green-originalpixel.green);*/
  // w=img.width();
  //  cout<<w<<endl;
  while(x1<img.width()&& y1<img.height())
    {
      
	
	  marked[x1][y1]=false;
	  y1++;
         x1++;
    }

  structure.add(img(x,y));
  xc.add(x);
  yc.add(y);
  while(!structure.isEmpty())
    {
       currentpixel =structure.remove();
       // currentpixel->red=originalpixel.red;
       // currentpixel->green=originalpixel.green;
       //  currentpixel->blue=originalpixel.blue;
      unsigned long      int xc2=xc.remove();
      unsigned long      int yc2=yc.remove();


      //      cout<<"Here"<<endl;
      
tmp=(currentpixel->red-originalpixel.red)*(currentpixel->red-originalpixel.red)+(currentpixel->blue-originalpixel.blue)*(currentpixel->blue-originalpixel.blue)+(currentpixel->green-originalpixel.green)*(currentpixel->green-originalpixel.green);
 if(!marked[xc2][yc2] && tmp<=tolerance)
   {
     //  cout<<"what"<<endl;
     
     marked[xc2][yc2]=true;
     *currentpixel=fillColor(xc2,yc2);
     if(xc2+1<img.width())
       {
	 structure.add(img(xc2+1,yc2));
	 xc.add(xc2+1);
	 yc.add(yc2);
		   }	   
       if(yc2+1<img.height())
	 {
	   structure.add(img(xc2,yc2+1));
	   xc.add(xc2);
	   yc.add(yc2+1);
		     }
	 if(xc2-1>0)
	   {
	     structure.add(img(xc2-1,yc2));
	     xc.add(xc2-1);
	     yc.add(yc2);
	   }
	       if(yc2-1>0)
		 {
		   structure.add(img(xc2,yc2-1));
		   xc.add(xc2);
		   yc.add(yc2-1);
		 }
	       
	       framecount++;
	       if((framecount % frameFreq)==0)
		 {

		   anime.addFrame(img);
		 
		 }
	       //	       cout<<"here"<<endl;
	       
	   
   }


    }

  
    
  return anime;


}
