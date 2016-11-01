/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
#include "quadtree.h"
#include <math.h>
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
  copy(other.root,root);
} 	
Quadtree const & Quadtree::operator=(Quadtree const & other)
{
  if(root!=other.root)
    {

      clear(root);
      copy(other.root,root);
      
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
  //  root=NULL;
buildtreehelp(source,resolution,root,0,0);

}
RGBAPixel Quadtree::getPixel(int x, int y )const
{
  //stuff
  
  return  getpixelhelp(x,y,root);

}
PNG Quadtree::decompress()const
{
  if(root==NULL)
    {
      return *(new PNG());
    }
  int resolution=root->resol;
  PNG img(resolution,resolution);
  for(int a=0;a<resolution;a++)
    for(int b=0; b<resolution;b++)
      {

	*img(a,b)=getPixel(a,b);

      }



  return img;
  
}
void Quadtree:: copy(QuadtreeNode *tree1, QuadtreeNode *&tree2)
{
  //QuadtreeNode *currnode;
  // QuadtreeNode *copynode=NULL;
  //  currnode=node;
  if(tree1!=NULL)
    {

      tree2=new QuadtreeNode(*tree1);
      tree2->element=tree1->element;
      copy(tree1->nwChild,tree2->nwChild);
      copy(tree1->neChild,tree2->neChild);
      copy(tree1->seChild,tree2->seChild);
      copy(tree1->swChild,tree2->swChild);

    }
  

}
void Quadtree::buildtreehelp(PNG const & source, int resolution, QuadtreeNode *&node, int x, int y)
{ 
  
  if(node==NULL )
    {
      node = new QuadtreeNode(resolution,x,y);
    }
  if(resolution==1)
    {
      node->element=*(source(node->x,node->y));

	return;
    }
  //  root=new QuadtreeNode(resolution,0,0);
 
  //I assume this is done recursively
  //This tree is being built from scratch. We need to make all of the nodes.
  /* node->nwChild = new QuadtreeNode(resolution,node->x,node->y);
  node->neChild = new QuadtreeNode(resolution,node->x+resolution/2,node->y);
  node->swChild = new QuadtreeNode(resolution,node->x, node->y+resolution/2);
  node->seChild = new QuadtreeNode(resolution, node->x+resolution/2, node->y+resolution/2);
  */

  
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
  if(node==NULL)
    {
      return *(new RGBAPixel());
      
    }
  if(/*(node->x==x && node->y==y&&node->resol==1)||*/node->nwChild==NULL)
    {
      return node->element;
    }
  if((x>=node->nwChild->x&&x<node->nwChild->x+node->nwChild->resol)&&((y>=node->nwChild->y&&y<node->nwChild->y+node->nwChild->resol)))
    {
      return getpixelhelp(x,y,node->nwChild);
    }
  if((x>=node->neChild->x&&x<node->neChild->x+node->neChild->resol)&&((y>=node->neChild->y&&y<node->neChild->y+node->neChild->resol)))
    {
      return getpixelhelp(x,y,node->neChild);
    }
 if((x>=node->seChild->x&&x<node->seChild->x+node->seChild->resol)&&((y>=node->seChild->y&&y<node->seChild->y+node->seChild->resol)))
    {
      return getpixelhelp(x,y,node->seChild);
    }
 else
   {

     return getpixelhelp(x,y,node->swChild);

   }
	     
 
}
  
 // return node->element;

  // return node->element;
  

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



void Quadtree::clockwiseRotate()
{
 clockwiserotatehelper(root);
}
void  Quadtree::clockwiserotatehelper(QuadtreeNode *node)
{
  QuadtreeNode *tmp;

  if(node->nwChild==NULL)
    {
      return;
    }
 

  int xnw = node->nwChild->x;
  int ynw = node->nwChild->y;
  
  int xne = node->neChild->x;
  int yne = node->neChild->y;

  int xse = node->seChild->x;
  int yse = node->seChild->y;

  int xsw = node->swChild->x;
  int ysw = node->swChild->y;

  tmp=node->nwChild;
  node->nwChild=node->neChild;
  node->neChild=node->seChild;
  node->seChild=node->swChild;
  node->swChild=tmp;
  
  node->nwChild->x=xne;
  node->nwChild->y=yne;

  node->neChild->x=xse;
  node->neChild->y=yse;

  node->seChild->x=xsw;
  node->seChild->y=ysw;

  node->swChild->x=xnw;
  node->swChild->y=ynw;
  
  clockwiserotatehelper(node->nwChild);
  clockwiserotatehelper(node->swChild);
  clockwiserotatehelper(node->seChild);
  clockwiserotatehelper(node->swChild);

  /*  
  node->nwChild->x=xne;
  node->nwChild->y=yne;

  node->neChild->x=xse;
  node->neChild->y=yse;

  node->seChild->x=xsw;
  node->seChild->y=ysw;

  node->swChild->x=xnw;
  node->swChild->y=ynw;
  */



}

void Quadtree::prune(int tolerance)
{ 
  prunehelper(tolerance,root);
}
int Quadtree::pruneSize(int tolerance)
{
  // QuadtreeNode *tmp=root;

  return prunesizehelper(tolerance,root);
}

int Quadtree::idealPrune(int numLeaves)const
{
  return 28594;
}


void Quadtree::prunehelper(int tolerance, QuadtreeNode *&node) 
{
  if(node==NULL||node->nwChild==NULL)
    {
      return;
    }
  
  if(checker(node,node,tolerance)==true)
    {
      clear(node->nwChild);
      clear(node->swChild);
      clear(node->neChild);
      clear(node->seChild);
      return;
    }

  prunehelper(tolerance,node->nwChild);
  prunehelper(tolerance,node->swChild);
  prunehelper(tolerance,node->neChild);
  prunehelper(tolerance,node->seChild);

}


bool Quadtree :: checker(QuadtreeNode* node1,QuadtreeNode *node2, int tolerance) 
{
  if(node2->nwChild==NULL)
    {
      if(checkdifference(node1,node2)<=tolerance)
	{
	  return true;
	}
      else
	{
	  return false;

	}

    }
  else
    {
      return checker(node1,node2->nwChild,tolerance) && checker(node1,node2->neChild,tolerance) && checker(node1,node2->swChild,tolerance) && checker(node1,node2->seChild,tolerance);
    }





}    
int Quadtree:: checkdifference( QuadtreeNode *node1, QuadtreeNode *node2)
{
  int x=(pow(node2->element.red-node1->element.red,2)+(pow(node2->element.green-node1->element.green,2)+(pow(node2->element.blue-node1->element.blue,2))));
  return x;
}

int Quadtree :: prunesizehelper(int tolerance, QuadtreeNode *node) 
{ 
  QuadtreeNode *tmp;
  tmp=root;
  prunehelper(tolerance,tmp);
  return count(tmp);

}
int Quadtree :: count(QuadtreeNode *node)
{
  

  int c=1;
 

  if(node==NULL)
    {
      return 0;
    }
  else if(node->nwChild==NULL)
    {
      return 1;
      
    }

  else
    {
      
      c+=count(node->nwChild);
      c+=count(node->neChild);
      c+=count(node->swChild);
      c+=count(node->seChild);
      return c;
    }

}
