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
    Projeto.setColor(0.502, 0.502, 0.502, 1);
    Projeto.putBox(9, 11, 3, 7, 0, 2);
    Projeto.putBox(8, 9, 3, 4, 0, 2);
    Projeto.putBox(12, 14, 3, 6, 0, 2);
    Projeto.putBox(14, 15, 3, 4, 0, 2);
    Projeto.putBox(12, 13, 6, 7, 0, 2);
    Projeto.putBox(10, 13, 7, 8, 0, 2);

    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(7, 9, 4, 7, 0, 2);
    Projeto.putBox(14, 16, 4, 7, 0, 2);
    Projeto.putBox(13, 14, 6, 7, 0, 2);

    //Tronco
    Projeto.setColor(0, 0, 0, 1);
    Projeto.putBox(9, 10, 7, 13, 0, 2);


    Projeto.writeOFF((char*)"uva.off");

    return 0;
}
