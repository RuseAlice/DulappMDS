//
// Created by alice on 25.05.2021.
//
#include "Consumable.h"

//Consumable::Consumable() {
//    nume = "";
//    cantitate = 0;
//}

Consumable::Consumable(string nume, int cantitate) {
    this->nume = nume;
    this->cantitate = cantitate;
}

bool Consumable::operator==(Consumable c) const{
    return this->nume==c.nume && this->cantitate==c.cantitate;
}
