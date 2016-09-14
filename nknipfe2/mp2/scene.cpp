#include "scene.h"
#include "image.h"
#include <iostream>
using namespace std;

Scene :: Scene(int max)
{
  
  
  Image ** rows[m_max];
  Image * xcoord= new Image() ;
  Image * ycoord = new Image ();

  for(int i=0;i<max;i++)
    {
      rows[i]=NULL;
      
    }
  xcoord=0;
  ycoord=0;
}

Scene :: ~Scene()
{
  for(int i=0; i<m_max;i++)
    {
      delete []rows[i];
      rows[i]=NULL;

    }
  delete [] xcoord;
  delete [] ycoord;

}
Image Scene ::drawscene()const
{



}
Scene :: Scene(const Scene &source)
{
  
  m_copy(source);

}


void Scene:: changemaxlayers(int newmax)
{




}

void Scene :: addpicture(const char *FileName, int index, int x, int y)
{
    


}

void Scene :: changelayer(int index, int newindex)
{
  if(index==newindex)
    {
      return;
    }
  else if(newindex !=NULL)
    {
    deletepicture(newindex);

    }
}


void Scene :: translate( int index, int xcoord, int ycoord)
{



}

//void Scene :: deletepicture(int index)
//{
  

//}
void Scene :: m_copy(const Scene &source)
{
  
  
  
  int ** rows = new int *[m_max];
  int * xcoord= new int(m_max) ;
  int * ycoord = new int (m_max);
  
  for(int i=0; i<m_max; i++)
    {

           source.rows[i] =rows[i];
	    source.xcoord[i] =xcoord[i];
	    source.ycoord[i]=ycoord[i];


    }

  



}

void Scene :: m_clear()
{
  

}
Image * Scene::getpicture(int index) const
{


}

void Scene::deletepicture(int index)
{
  if(index!=NULL)
    {
      delete rows[index];
      xcoord=0;
      ycoord=0;

    }
  else
    {

      cout<<"invalid index"<<endl;


    }


}
const Scene & Scene::operator= (const Scene &source)
{


}
