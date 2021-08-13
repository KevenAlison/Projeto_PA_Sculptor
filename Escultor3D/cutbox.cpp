#include "cutbox.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    this->xi=x0; this->xf=x1; this->yi=y0; this->yf=y1; this->zi=z0; this->zf=z1;
}

CutBox::~CutBox(){

}

void CutBox::draw(Sculptor &s){
    int cx, cy, cz; //coordenadas x,y,z
    for(cx=xi; cx<=xf; cx++){
        for(cy=yi; cy<=yf; cy++){
            for(cz=zi; cz<=zf; cz++){

                s.cutVoxel(cx,cy,cz);

            }
        }
    }

}
