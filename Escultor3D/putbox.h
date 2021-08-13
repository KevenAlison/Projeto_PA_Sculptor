#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutBox : public FiguraGeometrica{
private:
    int xi, xf, yi, yf, zi, zf;
public:
    PutBox(int xi, int xf, int yi, int yf, int zi, int zf, float r, float g, float b, float a);
    ~PutBox();

    void draw(Sculptor &s);
};

#endif // PUTBOX_H
