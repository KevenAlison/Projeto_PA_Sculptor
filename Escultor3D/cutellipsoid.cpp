#include "cutellipsoid.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int xc, int yc, int zc, int raiox, int raioy, int raioz){
    this->xc=xc; this->yc=yc; this->zc=zc; this->raiox=raiox; this->raioy=raioy; this->raioz=raioz;
}

CutEllipsoid::~CutEllipsoid()
{

}

void CutEllipsoid::draw(Sculptor &s){
    int x,y,z;
    for(x=xc-raiox; x<=xc+raiox; x++){
        for(y=yc-raioy; y<=yc+raioy; y++){
            for(z=zc-raioz; z<=zc-raioz; z++){
                //Equação da elipse
                if((pow((x-xc),2) / pow(raiox,2) + pow((y-yc),2) / pow(raioy,2) + pow((z-zc),2) / pow(raioz,2)) <= 1.0){
                    s.cutVoxel(x,y,z);
                }
            }
        }
    }
}
