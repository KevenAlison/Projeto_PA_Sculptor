#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nz;
    ny = _ny;
    nz = _nx;

    v = new Voxel**[nx];

    for(int i=0; i<nx; i++){
         v[i] = new Voxel*[nx*ny];
    }
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            v[i][j]= new Voxel[nz*ny*nx];
        }
    }


}


//Destrutor com liberação de memoria alocada
Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

//fixa uma cor para o voxel
void Sculptor::setColor(float red, float green, float blue, float opacidade){
   r = red;
   g = green;
   b = blue;
   a = opacidade;
}

//Ativa o voxel
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].a = a;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
}

//Desativa o voxel
void Sculptor::cutVoxel(int x, int y, int z){
v[x][y][z].isOn = false;
}

//Ativa voxels entre um intervalo
void Sculptor::putBox(int xi, int xf, int yi, int yf, int zi, int zf){
    int cx, cy, cz;
        for(cx=xi; cx<xf; cx++){
          for(cy=yi; cy<yf; cy++){
            for(cz=zi; cz<zf; cz++){

                putVoxel(cx,cy,cz);

            }
           }
         }

}

void Sculptor::cutBox(int xi, int xf, int yi, int yf, int zi, int zf){
    int cx, cy, cz; //coordenadas x,y,z
    for(cx=xi; cx<=xf; cx++){
        for(cy=yi; cy<=yf; cy++){
            for(cz=zi; cz<=zf; cz++){

                cutVoxel(cx,cy,cz);

            }
        }
    }

}

void Sculptor::putSphere(int xc, int yc, int zc, int raio){
    int x,y,z,dxs,dys,dzs;


    for(x=0; x<=nx; x++){
        for(y=0; y<=ny; y++){
            for(z=0; z<=nz; z++){
                dxs=x-xc; dys=y-yc;dzs=z-zc;
                if((pow(dxs,2)+pow(dys,2)+pow(dzs,2))<=pow(raio,2)){
                    putVoxel(x,y,z);
                }
            }
        }
    }

}

void Sculptor::cutSphere(int xc, int yc, int zc, int raio){
    int x,y,z,dxs,dys,dzs;


    for(x=0; x<=nx; x++){
        for(y=0; y<=ny; y++){
            for(z=0; z<=nz; z++){
                dxs=x-xc; dys=y-yc;dzs=z-zc;
                if((pow(dxs,2)+pow(dys,2)+pow(dzs,2))<=pow(raio,2)){
                    cutVoxel(x,y,z);
                }
            }
        }
    }

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double rx2 = rx/2.0, ry2 = ry/2.0, rz2 = rz/2.0;
    double dist;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                //Equação da elipse
                dist = (i-xcenter/2.0)*(i-xcenter/2.0) / (rx2*rx2) + (j-ycenter/2.0)*(j-ycenter/2.0) / (ry2*ry2) + (k-zcenter/2.0)*(k-zcenter/2.0) / (rz2*rz2);

                //Condição para desenho da elipse (distância menor que 1)
                if(dist <= 1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double rx2 = rx/2.0, ry2 = ry/2.0, rz2 = rz/2.0;
    double dist;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                //Equação da elipse
                dist = (i-xcenter/2.0)*(i-xcenter/2.0) / (rx2*rx2) + (j-ycenter/2.0)*(j-ycenter/2.0) / (ry2*ry2) + (k-zcenter/2.0)*(k-zcenter/2.0) / (rz2*rz2);

                //Condição para desenho da elipse (distância menor que 1)
                if(dist <= 1.0){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char *nome){
    string str;
    ofstream f_out;
    f_out.open(nome);


    if(! f_out.good())
    {
        cout << "Falha ao criar arquivo\n";
    }
    else
        cout << "Gerando Arquivo...\n";


    int totalDeElementos = nx*ny*nz;

    for(int i = 0; i<nx; i++)
    {
        for(int j = 0; j<ny; j++)
        {
            for(int k = 0; k<nz; k++)
            {
                if(v[i][j][k].isOn == false)
                {
                    totalDeElementos--;
                }
            }
        }
    }

    str += "OFF\n";
    str += to_string(totalDeElementos*8) + " " + to_string(totalDeElementos*6) + " " + "0\n";

    for(int i = 0; i<nx; i++)
    {
        for(int j = 0; j<ny; j++)
        {
            for(int k = 0; k<nz; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    str += to_string(i-0.5) + " " + to_string(j+0.5) + " " + to_string(k-0.5) + "\n";
                    str += to_string(i-0.5) + " " + to_string(j-0.5) + " " + to_string(k-0.5) + "\n";
                    str += to_string(i+0.5) + " " + to_string(j-0.5) + " " + to_string(k-0.5) + "\n";
                    str += to_string(i+0.5) + " " + to_string(j+0.5) + " " + to_string(k-0.5) + "\n";
                    str += to_string(i-0.5) + " " + to_string(j+0.5) + " " + to_string(k+0.5) + "\n";
                    str += to_string(i-0.5) + " " + to_string(j-0.5) + " " + to_string(k+0.5) + "\n";
                    str += to_string(i+0.5) + " " + to_string(j-0.5) + " " + to_string(k+0.5) + "\n";
                    str += to_string(i+0.5) + " " + to_string(j+0.5) + " " + to_string(k+0.5) + "\n";
                }
            }
        }
    }

    int cont = 0;

    for(int i = 0; i<nx; i++)
    {
        for(int j = 0; j<ny; j++)
        {
            for(int k = 0; k<nz; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    int pos = 8*cont;
                    str += "4 " + to_string(pos) + " " + to_string(pos+3) + " " + to_string(pos+2) + " " + to_string(pos+1) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos+4) + " " + to_string(pos+5) + " " + to_string(pos+6) + " " + to_string(pos+7) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos) + " " + to_string(pos+1) + " " + to_string(pos+5) + " " + to_string(pos+4) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos) + " " + to_string(pos+4) + " " + to_string(pos+7) + " " + to_string(pos+3) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str +="4 " + to_string(pos+3) + " " + to_string(pos+7) + " " + to_string(pos+6) + " " + to_string(pos+2) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos+1) + " " + to_string(pos+2) + " " + to_string(pos+6) + " " + to_string(pos+5) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    cont++;
                }
            }
        }
    }
    cout << "Arquivo gerado!! \n";
    f_out << str;
    f_out.close();
}
