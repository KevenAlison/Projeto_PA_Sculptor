#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutSphere : public FiguraGeometrica{
private:
    int xc,yc,zc,raio;
public:
    CutSphere(int xc, int yc, int zc, int raio);
    ~CutSphere();

    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
