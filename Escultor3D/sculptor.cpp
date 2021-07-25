#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

//Construtor com alocação de memória
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    int x,y;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for(x=0; x<nx; x++){
         v[x] = new Voxel*[nx*ny];
    }
    for(x=0; x<nx; x++){
        for(y=0; y<ny; y++){
            v[x][y]= new Voxel[nz*ny*nx];
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
    if( (x>=nx || x<0)  ||  (y>=ny || y<0)  ||  (z>=nz || z<0) ){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
    v[x][y][z].isOn = true;
    v[x][y][z].a = a;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
}

//Desativa o voxel
void Sculptor::cutVoxel(int x, int y, int z){
    if( (x>=nx || x<0)  ||  (y>=ny || y<0)  ||  (z>=nz || z<0) ){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
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

//Desativa voxels entre um intervalo
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

//Habilitar voxels dentro dos limites da esfera
void Sculptor::putSphere(int xc, int yc, int zc, int raio){
    int x,y,z,dxs,dys,dzs;
    if( ((xc+raio)>=nx || (xc+raio)<0)  ||  ((yc+raio)>=ny || (yc+raio)<0)  ||  ((zc+raio)>=nz || (zc+raio)<0)){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
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


//Desabilitar voxels dentro dos limites da esfera
void Sculptor::cutSphere(int xc, int yc, int zc, int raio){
    if( ((xc+raio)>=nx || (xc+raio)<0)  ||  ((yc+raio)>=ny || (yc+raio)<0)  ||  ((zc+raio)>=nz || (zc+raio)<0)){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
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

//Habilitar voxels dentro dos limites da elipsoide
void Sculptor::putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    if( ((xc+rx)>=nx || (xc+rx)<0)  ||  ((yc+ry)>=ny || (yc+ry)<0)  ||  ((zc+rz)>=nz || (zc+rz)<0)){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
    int x,y,z;
    for(x=0; x<=nx; x++){
        for(y=0; y<=ny; y++){
            for(z=0; z<=nz; z++){
                //Equação da elipse
                if((pow((x-xc),2) / pow(rx,2) + pow((y-yc),2) / pow(ry,2) + pow((z-zc),2) / pow(rz,2)) <= 1.0){
                    putVoxel(x,y,z);
                }
            }
        }
    }

}

//Desabilitar voxels dentro dos limites da elipsoide
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    if( ((xc+rx)>=nx || (xc+rx)<0)  ||  ((yc+ry)>=ny || (yc+ry)<0)  ||  ((zc+rz)>=nz || (zc+rz)<0)){
        cout << "Valores indicados ultrapassam os limites da matriz " << nx << " x " << ny << " x " << nz << endl;
        exit(0);
    }
    int x,y,z;
    for(x=0; x<=nx; x++){
        for(y=0; y<=ny; y++){
            for(z=0; z<=nz; z++){
                //Equação da elipse
                if((pow((x-xc),2) / pow(rx,2) + pow((y-yc),2) / pow(ry,2) + pow((z-zc),2) / pow(rz,2)) <= 1.0){
                    cutVoxel(x,y,z);
                }
            }
        }
    }

}

//Gerar aquivo .OFF
void Sculptor::writeOFF(const char *nome){
    int Nvoxels=0,x,y,z;
    string str;
    ofstream fout;

    fout.open(nome); //Abertura do fluxo de arquivo

    if(! fout.is_open()){
        cout << "Falha na criação do arquivo\n";
        exit(1);
    }else
        cout << "Gerando Arquivo...\n";


    fout<<"OFF"<<endl; //Identificação do tipo de arquivo OFF

    //Conta os voxels ativos
        for(x=0;x<nx;x++){
            for(y=0;y<ny;y++){
                for(z=0;z<nz;z++){
                    if(v[x][y][z].isOn){
                        Nvoxels++;
                    }
                }
            }
        }

    //Conta a quantidade de faces e vertices da projeção
     int Nv=8*Nvoxels;
     int Nf=6*Nvoxels;

     fout<<Nv<<" "<<Nf<<" "<<0<<endl;

     //Definição das cordenadas espaciais dos voxels ativos
        for(x=0;x<nx;x++){
            for(y=0;y<ny;y++){
                for(z=0;z<nz;z++){
                    if(v[x][y][z].isOn == true){
                            fout<< x-0.5 <<" "<< y+0.5 <<" "<< z-0.5 <<endl;
                            fout<< x-0.5 <<" "<< y-0.5 <<" "<< z-0.5 <<endl;
                            fout<< x+0.5 <<" "<< y-0.5 <<" "<< z-0.5 <<endl;
                            fout<< x+0.5 <<" "<< y+0.5 <<" "<< z-0.5 <<endl;
                            fout<< x-0.5 <<" "<< y+0.5 <<" "<< z+0.5 <<endl;
                            fout<< x-0.5 <<" "<< y-0.5 <<" "<< z+0.5 <<endl;
                            fout<< x+0.5 <<" "<< y-0.5 <<" "<< z+0.5 <<endl;
                            fout<< x+0.5 <<" "<< y+0.5 <<" "<< z+0.5 <<endl;
                    }
                }
            }
        }

    //Definição das faces dos voxels a partir dos vertices
    int contador = 0;
    fixed(fout);
    for(x = 0; x<nx; x++){
        for(y = 0; y<ny; y++){
            for(z = 0; z<nz; z++){
                if(v[x][y][z].isOn == true){
                    int cord = 8*contador;
                    fout << 4 <<" "<< cord+0 <<" "<< cord+3 <<" "<< cord+2 <<" "<< cord+1 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    fout << 4 <<" "<< cord+4 <<" "<< cord+5 <<" "<< cord+6 <<" "<< cord+7 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    fout << 4 <<" "<< cord+0 <<" "<< cord+1 <<" "<< cord+5 <<" "<< cord+4 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    fout << 4 <<" "<< cord+0 <<" "<< cord+4 <<" "<< cord+7 <<" "<< cord+3 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    fout << 4 <<" "<< cord+3 <<" "<< cord+7 <<" "<< cord+6 <<" "<< cord+2 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    fout << 4 <<" "<< cord+1 <<" "<< cord+2 <<" "<< cord+6 <<" "<< cord+5 <<" "<< v[x][y][z].r <<" " << v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].a <<endl;
                    contador++;
                }
            }
        }
    }
    cout << "Arquivo gerado!! \n";
    fout.close(); //Fecha fluxo de arquivo
}
