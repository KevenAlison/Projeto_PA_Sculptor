#include "leitor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
using namespace std;

Leitor::Leitor(){

}

vector<FiguraGeometrica*> Leitor::parse(string filename){
    vector<FiguraGeometrica*> figs;
    ifstream fin;
    stringstream ss;
    string s, token;

    fin.open(filename.c_str());
    if(!fin.is_open()){
    cout << "Arquivo não abriu...";
    exit(0);
    }

    while(fin.good()){
        getline(fin,s);
        ss.clear();
        ss.str(s);
        ss >> token;

        if(ss.good()){
            if(token.compare("dim")==0){
                ss >> dimx >> dimy >> dimz;
            }
            else if(token.compare("putvoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
            }
            else if(token.compare("cutvoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z;
                figs.push_back(new CutVoxel(x,y,z));
            }
            else if(token.compare("putbox") == 0){
                int xi, xf, yi, yf, zi, zf;
                ss >> xi >> xf >> yi >> yf >> zi >> zf >> r >> g >> b >> a;
                figs.push_back(new PutBox(xi,xf,yi,yf,zi,zf,r,g,b,a));
            }
            else if(token.compare("cutbox") == 0){
                int xi, xf, yi, yf, zi, zf;
                ss >> xi >> xf >> yi >> yf >> zi >> zf;
                figs.push_back(new CutBox(xi,xf,yi,yf,zi,zf));
            }
            else if(token.compare("putsphere") == 0){
                int xc, yc, zc, raio;
                ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;
                figs.push_back(new PutSphere(xc,yc,zc,raio,r,g,b,a));
            }
            else if(token.compare("cutsphere") == 0){
                int xc, yc, zc, raio;
                ss >> xc >> yc >> zc >> raio;
                figs.push_back(new CutSphere(xc,yc,zc,raio));
            }
            else if(token.compare("putellipsoid") == 0){
                int xc, yc, zc, raiox, raioy, raioz;
                ss >> xc >> yc >> zc >> raiox >> raioy >> raioz >> r >> g >> b >> a;
                figs.push_back(new PutEllipsoid(xc,yc,zc,raiox,raioy,raioz,r,g,b,a));
            }
            else if(token.compare("cutellipsoid") == 0){
                int xc, yc, zc, raiox, raioy, raioz;
                ss >> xc >> yc >> zc >> raiox >> raioy >> raioz;
                figs.push_back(new CutEllipsoid(xc,yc,zc,raiox,raioy,raioz));
            }
        }
    }
    return(figs);

}
int Leitor::getDimx(){
    return dimx;
}

int Leitor::getDimy(){
    return dimy;
}

int Leitor::getDimz(){
    return dimz;
}
