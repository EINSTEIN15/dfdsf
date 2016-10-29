/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
Quadtree();
   
~Quadtree();
   
Quadtree(PNG const &source, int resolution);
   
void buildTree (PNG const &source, int resolution);
   
RGBAPixel getPixel(int x, int y) const;
   
PNG decompress() const;
   
Quadtree const&   operator=(Quadtree const & other);
   
Quadtree(Quadtree const &other);

 void clockwiseRotate();
 void prune (int tolerance);
 int pruneSize(int tolerance) const;
 int idealPrune(int numLeaves) const;





 private:

   //   void clear(QuadtreeNode *&node);
   //void copy(const QuadtreeNode *&other);


   /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */
	int x;
	int y;
	int resol;
	//constructor for the nodes so they have x,y coordinates stored
	QuadtreeNode(int resolution, int xc, int yc)
	   {
	     
	resol=resolution;
	x=xc;
	y=yc;
	nwChild=NULL;
	swChild=NULL;
	neChild=NULL;
	seChild=NULL;
      }
	  
    };

    QuadtreeNode* root; /**< pointer to root of quadtree */
    //  QuadtreeNode*node;

    
    
    void clear(QuadtreeNode *&node);
    //include source here to eventually keep track of the average color of children
    void buildtreehelp(PNG const & source, int resolution, QuadtreeNode *&node,int x, int y);
    RGBAPixel getpixelhelp(int x, int y, QuadtreeNode *node) const;
    void copy(QuadtreeNode *tree1,QuadtreeNode *&tree2);
    void clockwiserotatehelper(QuadtreeNode *node);
    void prunehelper(int tolerance, QuadtreeNode *&node);
    bool checkdifference(int tolerance, QuadtreeNode *node);

/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
