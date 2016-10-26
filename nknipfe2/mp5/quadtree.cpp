/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
#include "quadtree.h"

Quadtree::Quadtree()
{
  root=NULL;
  
}
/*QuadtreeNode:: QuadtreeNode(int resolution, int xc, int yc)
{
  resol=resolution;
  x=xc;
  y=yc;
  nwChild=NULL;
  swChild=NULL;
  neChild=NULL;
  seChild=NULL;
}
*/
Quadtree::~Quadtree()
{
  clear(root);
}
/*I think you can use post order traversal to clear dynamic*/
void Quadtree:: clear(QuadtreeNode *&node)
{
  //stuff
  if(node!=NULL)
    {
      // delete node;
     
      clear(node->neChild);
      clear(node->seChild);
      clear(node->swChild);
      clear(node->nwChild);
      node=NULL;
    }
}
/*copy constructor*/
Quadtree::Quadtree(Quadtree const &other)
{


  copy(root);





} 	
Quadtree const & Quadtree::operator=(Quadtree const & other)
{
  if(root!=other.root)
    {

      clear(root);
      copy(root);
    }

  return *this;



}
//another constructor
Quadtree::Quadtree(PNG const & source,int resolution)
{
  //so buildTree and this do the same thing.
  buildTree(source, resolution);
}
void Quadtree::buildTree (PNG const &source, int resolution)
{
  buildtreehelp(source,resolution,root);

}
RGBAPixel Quadtree::getPixel(int x, int y )const
{
  //stuff
  return getpixelhelp(x,y,root);

}
PNG Quadtree::decompress()const
{
  if(root==NULL)
    {
      return *(new PNG());
    }
  int resolution=root->resol;
  PNG img(resolution,resolution);
  for (int i=0;i<resolution;i++)
    {

      for(int j=0;j<resolution;j++)
	{

	  *(img(i,j))=getPixel(i,j);

	}


    }
  return img;
}

void Quadtree:: copy( QuadtreeNode *&node)
{
  QuadtreeNode *currnode;
  QuadtreeNode *othernode=NULL;
  currnode=node;
  if(currnode!=NULL)
    {

      currnode=othernode;
      

      copy(node->neChild);
      copy(node->nwChild);
      copy(node->seChild);
      copy(node->swChild);
    }

}
void Quadtree::buildtreehelp(PNG const & source, int resolution, QuadtreeNode *node)
{
  if(resolution==1)
    {
      node->element= (*source(node->x,node->y));

	return;
    }

  //I assume this is done recursively
  //This tree is being built from scratch. We need to make all of the nodes.
  node->nwChild = new QuadtreeNode(resolution,node->x,node->y);
  node->neChild = new QuadtreeNode(resolution,node->x+resolution/2,node->y);
  node->swChild = new QuadtreeNode(resolution,node->x, node->y+resolution/2);
  node->seChild = new QuadtreeNode(resolution, node->x+resolution/2, node->y+resolution/2);
  buildtreehelp(source,resolution/2, node->nwChild);
  buildtreehelp(source,resolution/2, node->neChild); 
  buildtreehelp(source,resolution/2, node->swChild); 
  buildtreehelp(source,resolution/2, node->seChild);





  //need to store average elements of all pixels. will come back for 5.2. I think this will help later with prune


}
RGBAPixel Quadtree::getpixelhelp(int x, int y, QuadtreeNode *node) const
{
  if(node==NULL || x>node->resol ||y>node->resol)
    {
      return *(new RGBAPixel());
    }

  if((node->x==x&&node->y==y&&node->resol==1)||node->nwChild==NULL)
    {

      return node->element;

    }

  if(x>=((node->resol)/2) && y<=((node->resol)/2))
    {
      return getpixelhelp(x,y,node->neChild);

    }
  if(x<=((node->resol)/2) && y>=((node->resol)/2))
    {
      return getpixelhelp(x,y,node->swChild);

    }
  if(x>=((node->resol)/2) && y>=((node->resol)/2))
    {
      return getpixelhelp(x,y,node->seChild);

    }
  if(x<=((node->resol)/2) && y<=((node->resol)/2))
    {
      return getpixelhelp(x,y,node->nwChild);

    }




  return node->element;
  

  /*  
  Quadtree::QuadtreeNode:: QuadtreeNode(int xc, int yc, int resolution)
  {
	     
	resol=resolution;
	x=xc;
	y=yc;
	nwChild=NULL;
	swChild=NULL;
	neChild=NULL;
	seChild=NULL;
   }
  */


}
