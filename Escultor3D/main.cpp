#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    Sculptor Projeto(50,50,50);

    //Pés
    Projeto.setColor(0.168, 0.233, 0.184, 1);
    Projeto.putBox(6, 17, 0, 1, 0, 2);

    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(7, 16, 1, 3, 0, 2);
    Projeto.cutBox(11, 11, 1, 3, 0, 2);
    Projeto.putBox(6, 7, 1, 2, 0, 2);
    Projeto.putBox(16, 17, 1, 2, 0, 2);

    //Pernas
    Projeto.setColor(0.192, 0.192, 0.192, 1); //Calça
    Projeto.putBox(9, 11, 3, 7, 0, 2);
    Projeto.putBox(8, 9, 3, 4, 0, 2);
    Projeto.putBox(12, 14, 3, 6, 0, 2);
    Projeto.putBox(14, 15, 3, 4, 0, 2);
    Projeto.putBox(12, 13, 6, 7, 0, 2);
    Projeto.putBox(10, 13, 7, 8, 0, 2);

    Projeto.setColor(0, 0, 0, 1);  //Capa
    Projeto.putBox(7, 9, 4, 7, 0, 2);
    Projeto.putBox(14, 16, 4, 7, 0, 2);
    Projeto.putBox(8, 9, 7, 9, 0, 2);
    Projeto.putBox(13, 14, 6, 7, 0, 2);

    //Tronco
    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(10, 13, 7, 13, 0, 1);
    Projeto.putBox(9, 10, 7, 13, 0, 2); //Lado esquerdo
    Projeto.putBox(8, 9, 12, 13, 0, 2);
    Projeto.putBox(7, 9, 10, 12, 0, 2);
    Projeto.putBox(6, 8, 9, 11, 0, 2);
    Projeto.putBox(5, 7, 8, 9, 0, 2);
    Projeto.setColor(1, 0.7961, 0.4667, 1); //Mão esquerda
    Projeto.putBox(4, 6, 9, 10, 0, 2);
    Projeto.putBox(5, 6, 10, 11, 0, 2);
    Projeto.setColor(0.5882, 0.2941, 0, 1); //Varinha
    Projeto.putBox(4, 5, 10, 11, 0, 2);
    Projeto.putBox(3, 4, 11, 12, 0, 2);
    Projeto.putBox(2, 3, 12, 13, 0, 2);
    Projeto.putBox(1, 2, 13, 14, 0, 2);
    Projeto.putBox(0, 1, 14, 15, 0, 2);

    Projeto.setColor(0.502, 0.502, 0.502, 1);
    Projeto.putBox(10, 13, 8, 11, 1, 2);
    Projeto.putBox(10, 11, 11, 12, 1, 2);
    Projeto.putBox(12, 13, 11, 12, 1, 2);
    Projeto.setColor(1, 1, 1, 1);
    Projeto.putBox(10, 11, 12, 13, 1, 2);
    Projeto.putBox(12, 13, 12, 13, 1, 2);
    Projeto.putBox(11, 12, 11, 12, 1, 2);
    Projeto.setColor(1, 0, 0, 1);
    Projeto.putBox(11, 12, 12, 13, 1, 2);

    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(13, 15, 7, 13, 0, 2);  //Lado direito
    Projeto.putBox(15, 17, 9, 11, 0, 2);
    Projeto.putBox(15, 16, 11, 13, 0, 2);
    Projeto.setColor(1, 0.7961, 0.4667, 1); //Mão direita
    Projeto.putBox(15, 17, 8, 9, 0, 2);
    Projeto.putBox(16, 17, 7, 8, 0, 2);

    //Rosto
    Projeto.setColor(1, 0.7961, 0.4667, 1);
    Projeto.putEllipsoid(23, 36, 1, 17, 12, 3);

    Projeto.setColor(0, 0, 0, 1); //Olhos
    Projeto.putBox(7, 9, 18, 20, 1, 2);
    Projeto.putBox(14, 16, 18, 20, 1, 2);
    Projeto.setColor(0.4, 0.4, 0.4, 1); //Óculos
    Projeto.putBox(5, 6, 17, 21, 1, 2); //Lado esquerdo
    Projeto.putBox(6, 10, 16, 17, 1, 2);
    Projeto.putBox(10, 11, 17, 21, 1, 2);
    Projeto.putBox(6, 10, 21, 22, 1, 2);
    Projeto.putBox(12, 13, 17, 21, 1, 2);
    Projeto.putBox(13, 17, 16, 17, 1, 2); //Lado direito
    Projeto.putBox(17, 18, 17, 21, 1, 2);
    Projeto.putBox(13, 17, 21, 22, 1, 2);
    Projeto.putBox(13, 17, 16, 17, 1, 2);
    Projeto.putBox(11, 12, 19, 20, 1, 2); //Perninha do centro
    Projeto.putBox(4, 5, 19, 20, 1, 2); //Perninha esquerda
    Projeto.putBox(18, 19, 19, 20, 1, 2); // Perninha direita

    //Cabelo
    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(3, 5, 19, 24, 0, 2);
    Projeto.putBox(3, 4, 18, 19, 0, 2);
    Projeto.putBox(3, 21, 23, 26, 0, 2);
    Projeto.putBox(4, 5, 21, 22, 0, 2);
    Projeto.putBox(20, 22, 18, 24, 0, 2);
    Projeto.putBox(16, 20, 22, 23, 0, 2);
    Projeto.putBox(19, 20, 20, 22, 0, 2);
    Projeto.putBox(5, 6, 22, 23, 0, 2);
    Projeto.cutBox(3, 4, 25, 26, 0, 2);
    Projeto.cutBox(20, 21, 25, 26, 0, 2);
    Projeto.cutBox(21, 22, 18, 19, 0, 2);
    Projeto.putBox(6, 18, 26, 27, 0, 2);
    Projeto.putBox(13, 15, 22, 23, 0, 2);
    Projeto.putBox(3, 21, 18, 24, 0, 1);

    Projeto.setColor(1, 0.7961, 0.4667, 1);
    Projeto.putBox(6, 8, 22, 23, 1, 2);
    Projeto.putBox(7, 8, 23, 24, 1, 2);
    Projeto.putBox(14, 15, 22, 23, 1, 2);

    //Pomo de ouro
    Projeto.setColor(0.9843, 0.9804, 0.1765, 1);
    Projeto.putSphere(20, 10, 1, 1);

    Projeto.writeOFF((char*)"harry.off");

    return 0;
}
