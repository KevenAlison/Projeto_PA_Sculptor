#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int xc, int yc, int zc, int raio){
    this->xc=xc; this->yc=yc; this->zc=zc; this->raio=raio;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &s){
    int x,y,z,dxs,dys,dzs;
    for(x=xc-raio; x<=xc+raio; x++){
        for(y=yc-raio; y<=yc+raio; y++){
            for(z=zc-raio; z<=zc+raio; z++){
                dxs=x-xc; dys=y-yc;dzs=z-zc;
                if((pow(dxs,2)+pow(dys,2)+pow(dzs,2))<=pow(raio,2)){
                    s.cutVoxel(x,y,z);
                }
            }
        }
    }
}
