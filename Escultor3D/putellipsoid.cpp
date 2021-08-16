#include "putellipsoid.h"
#include <cmath>

PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int raiox, int raioy, int raioz, float r, float g, float b, float a){
    this->xc=xc; this->yc=yc; this->zc=zc; this->raiox=raiox; this->raioy=raioy; this->raioz=raioz;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

PutEllipsoid::~PutEllipsoid()
{

}

void PutEllipsoid::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    int x,y,z;
    for(x=xc-raiox; x<=xc+raiox; x++){
        for(y=yc-raioy; y<=yc+raioy; y++){
            for(z=zc-raioz; z<=zc+raioz; z++){
                //Equação da elipse
                if((pow((x-xc),2) / pow(raiox,2) + pow((y-yc),2) / pow(raioy,2) + pow((z-zc),2) / pow(raioz,2)) <= 1.0){
                    s.putVoxel(x,y,z);
                }
            }
        }
    }
}
