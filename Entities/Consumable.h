//
// Created by alice on 25.05.2021.
//

#ifndef DULAPP_CONSUMABLE_H
#define DULAPP_CONSUMABLE_H
#include <string>
#include <iostream>
using namespace std;

class Consumable{
private:
    string nume;
    int cantitate;
public:
    Consumable(){
        nume = "";
        cantitate = 0;
    }
    Consumable(string nume, int cantitate);
    string getNume(){return nume;}
    int getProcent(){return cantitate;}
    void setNume(string denumire){nume = denumire;}
    void setProcent(int nr){cantitate = nr;}
    void spray(int nr){cantitate -= nr;}
    void setFull(){cantitate = 100;}
    bool operator==(Consumable c) const;
};
#endif //DULAPP_CONSUMABLE_H
