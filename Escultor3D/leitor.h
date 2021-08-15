#ifndef LEITOR_H
#define LEITOR_H
#include <vector>
#include "figurageometrica.h"
#include "sculptor.h"
#include <string>
using namespace std;

class Leitor{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Leitor();
    vector<FiguraGeometrica*> parse(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // LEITOR_H
