#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
private:
    int xc, yc, zc, raiox, raioy, raioz;
public:
    CutEllipsoid(int xc, int yc, int zc, int raiox, int raioy, int raioz);
    ~CutEllipsoid();

    void draw(Sculptor &s);
};


#endif // CUTELLIPSOID_H
