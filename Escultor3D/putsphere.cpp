#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xc, int yc, int zc, int raio, float r, float g, float b, float a){
    this->xc=xc; this->yc=yc; this->zc=zc; this->raio=raio;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    int x,y,z,dxs,dys,dzs;
    for(x=xc-raio; x<=xc+raio; x++){
        for(y=yc-raio; y<=yc+raio; y++){
            for(z=zc-raio; z<=zc+raio; z++){
                dxs=x-xc; dys=y-yc;dzs=z-zc;
                if((pow(dxs,2)+pow(dys,2)+pow(dzs,2))<=pow(raio,2)){
                    s.putVoxel(x,y,z);
                }
            }
        }
    }
}
