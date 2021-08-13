#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"


class PutEllipsoid : public FiguraGeometrica{
private:
    int xc,yc,zc,raiox,raioy,raioz;
public:
    PutEllipsoid(int xc, int yc, int zc, int raiox, int raioy, int raioz, float r, float g, float b, float a);
    ~PutEllipsoid();

    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
