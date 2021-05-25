//
// Created by alice on 25.05.2021.
//

#ifndef DULAPP_HAINA_H
#define DULAPP_HAINA_H
#include<ctime>
#include <string>

using namespace std;
enum Culoare{null_culoare,Alb, Negru, Albastru, Verde, Galben, Rosu, Portocaliu, Bleumarin, Gri, Bej, Maro, Mov};
enum Stil{null_stil,casual, sport, business, formal};
enum Material{null_material,poliester, bumbac, stofa, denim, matase, in, fas, lana};
enum PiesaVestimentara{null_piesa,jacheta, top, pantaloni, piesaUnica};

class Haina {
private:
    string denumire;
    PiesaVestimentara piesaVestimentara;
    Culoare culoare;
    Stil stil;
    Material material;
    int nrPurtari=0;
    bool disponibil;
    time_t ultimaScoatere;


public:
    Haina(string denumire, PiesaVestimentara piesaV, Culoare culoare, Stil stil, Material material);
    Haina()=default;
    string getDenumire(){return denumire;}
    void setDenumire(string denumire){this->denumire=denumire;}
    PiesaVestimentara getPiesaVestimentara(){return piesaVestimentara;}
    void setPiesaVestimentara(PiesaVestimentara piesaVestimentara){this->piesaVestimentara=piesaVestimentara;}
    Culoare getCuloare(){return culoare;}
    void setCuloare(Culoare culoare){this->culoare=culoare;}
    Stil getStil(){return stil;};
    void setStil(Stil stil){this->stil=stil;}
    Material getMaterial(){return material;}
    void setMaterial(Material material){this->material=material;}
    int getNrPurtari(){return nrPurtari;}
    void setNrPurtari(int nr_purtari){this->nrPurtari=nr_purtari;}
    bool getDisponibilitate(){return disponibil;}
    void setDisponibilitate(bool disp){this->disponibil=disp;}
    time_t getUltimaScoatere(){return ultimaScoatere;}
    void setUltimaScoatere(time_t t){ultimaScoatere=t;}
    bool verificarePotrivire(Culoare culoare, Stil stil, float temperatura);
    string afisare();
    bool operator ==(Haina h);

};
#endif //DULAPP_HAINA_H
