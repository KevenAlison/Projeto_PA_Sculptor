#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"


class PutSphere : public FiguraGeometrica{
private:
    int xc,yc,zc, raio;
public:
    PutSphere(int xc, int yc, int zc, int raio, float r, float g, float b, float a);
    ~PutSphere();

    void draw(Sculptor &s);
};


#endif // PUTSPHERE_H
