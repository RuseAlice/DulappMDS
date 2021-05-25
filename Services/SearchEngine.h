//
// Created by alice on 25.05.2021.
//

#ifndef DULAPP_SEARCHENGINE_H
#define DULAPP_SEARCHENGINE_H
#include "../Entities/Haina.h"
#include "HaineManager.h"

class SearchEngine {
public:
    SearchEngine(){};
    map<int,Haina> cautare(map<int,Haina> haine, string nume);
    map<int,Haina> cautare(map<int,Haina> haine, PiesaVestimentara piesa);
    map<int,Haina> cautare(map<int,Haina> haine, Culoare culoare);
    map<int,Haina> cautare(map<int,Haina> haine, Stil stil);
    map<int,Haina> cautare(map<int,Haina> haine, Material material);
};
#endif //DULAPP_SEARCHENGINE_H
