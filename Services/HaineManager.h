//
// Created by alice on 25.05.2021.
//

#ifndef DULAPP_HAINEMANAGER_H
#define DULAPP_HAINEMANAGER_H
#include "../Entities/Haina.h"
#include <map>

class HaineManager {
private:
    int nrUmerase;
    map<int,Haina> haine;
    inline static HaineManager *manager;
    HaineManager(map<int,Haina> h, int nr);

public:
    static HaineManager *getManager() {
        map<int, Haina> h;
        if (!manager)
            manager = new HaineManager(h, 20);
        return manager;
    }

    void setNrUmerase(int nr){nrUmerase=nr;}
    int getNrUmerase(){return nrUmerase;}
    map<int,Haina> getHaine(){return haine;}
    void setHaine(map<int, Haina> h){haine.swap(h);}
    void introducereHaina(string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void introducereHaina(Haina h);
    void editareHaina(int umeras, string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void vizualizareHaina(Haina haina);
    void stergereHaina(Haina haina);
    void stergereHaina(int idx);
    void generareTinuta(float temperatura, bool precipitatii, Stil stil);
    void creareTinuta(bool jacheta, bool piesaUnica, int piesa1, int piesa2=-1, int piesa3=-1);
    void reintroducereHaina(int nr);
    void scoatereHaina(int nr);

};
#endif //DULAPP_HAINEMANAGER_H
