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
      delete node;
      node=NULL;
    }
}
/*copy constructor*/
Quadtree::Quadtree(Quadtree const &other)
{ root=NULL;
  copy(root,other.root);
} 	
Quadtree const & Quadtree::operator=(Quadtree const & other)
{
  if(root!=other.root)
    {

      clear(root);
      copy(root,other.root);
    }

  return *this;



}
//another constructor
Quadtree::Quadtree(PNG const & source,int resolution)
{
  //so buildTree and this do the same thing.
  root=NULL;
  buildTree(source, resolution);
}
void Quadtree::buildTree (PNG const &source, int resolution)
{
  clear(root);

buildtreehelp(source,resolution,root,0,0);

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

void Quadtree:: copy(QuadtreeNode *&orig, QuadtreeNode *copynode)
{
  //QuadtreeNode *currnode;
  //QuadtreeNode *othernode=NULL;
  //  currnode=node;
  if(orig!=NULL)
    {

      copynode=orig;
      

      copy(orig->neChild,copynode->neChild);
      copy(orig->nwChild,copynode->nwChild);
      copy(orig->seChild,copynode->seChild);
      copy(orig->swChild,copynode->swChild);
    }

}
void Quadtree::buildtreehelp(PNG const & source, int resolution, QuadtreeNode *&node, int x, int y)
{ 
  if(node==NULL)
    {
      node=new QuadtreeNode(resolution,x,y);

    }
  if(resolution==1&& node!=NULL)
    {
      node->element= (*source(node->x,node->y));

	return;
    }
  //  root=new QuadtreeNode(resolution,0,0);
 
  //I assume this is done recursively
  //This tree is being built from scratch. We need to make all of the nodes.
  // node->nwChild = new QuadtreeNode(resolution,node->x,node->y);
  //node->neChild = new QuadtreeNode(resolution,node->x+resolution/2,node->y);
  //node->swChild = new QuadtreeNode(resolution,node->x, node->y+resolution/2);
  //node->seChild = new QuadtreeNode(resolution, node->x+resolution/2, node->y+resolution/2);
  


  buildtreehelp(source,resolution/2, node->nwChild,node->x,node->y);
  buildtreehelp(source,resolution/2, node->neChild,node->x+resolution/2,node->y); 
  buildtreehelp(source,resolution/2, node->swChild,node->x, node->y+resolution/2); 
  buildtreehelp(source,resolution/2, node->seChild,node->x+resolution/2, node->y+resolution/2);
  
//need to store average elements of all pixels. will come back for 5.2. I think this will help later with prune
  node->element.red=(node->nwChild->element.red+node->neChild->element.red+node->swChild->element.red+node->seChild->element.red)/4;
  node->element.green=(node->nwChild->element.green+node->neChild->element.green+node->swChild->element.green+node->seChild->element.green)/4;
  node->element.blue=(node->nwChild->element.blue+node->neChild->element.blue+node->swChild->element.blue+node->seChild->element.blue)/4;



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
      weird error when I try to delcare here. So I had to declare in quadtree.h
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
void Quadtree::clockwiseRotate()
{
 clockwiserotatehelper(root);
}
void  Quadtree::clockwiserotatehelper(QuadtreeNode *&node)
{
  QuadtreeNode *tmp;

  if(node==NULL)
    {
      return;

    }
  tmp=node->neChild;
  node->neChild=node->seChild;
  node->seChild=node->swChild;
  node->swChild=node->nwChild;
  node->nwChild=tmp;


  clockwiserotatehelper(node->nwChild);
  clockwiserotatehelper(node->swChild);
  clockwiserotatehelper(node->seChild);
  clockwiserotatehelper(node->swChild);

}
