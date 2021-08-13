#include "putbox.h"

PutBox::PutBox(int xi, int xf, int yi, int yf, int zi, int zf, float r, float g, float b, float a){
    this->xi=xi; this->xf=xf; this->yi=yi; this->yf=yf; this->zi=zi; this->zf=zf;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

PutBox::~PutBox()
{

}

void PutBox::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    int cx, cy, cz;
        for(cx=xi; cx<xf; cx++){
          for(cy=yi; cy<yf; cy++){
            for(cz=zi; cz<zf; cz++){
                s.putVoxel(cx,cy,cz);
            }
           }
         }

}
