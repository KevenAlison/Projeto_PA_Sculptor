#ifndef SCULPTOR_H
#define SCULPTOR_H


struct Voxel {
  float r,g,b; //Cores
  float a; //Transparencia
  bool isOn; // Voxel Ativado/Desativado
};

class Sculptor {
protected:
  Voxel ***v; //Matriz 3d
  int nx,ny,nz; // Dimensões
  float r,g,b,a; // Propriedades atuais do voxel
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};



#endif // SCULPTOR_H
