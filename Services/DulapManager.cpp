//
// Created by alice on 25.05.2021.
//

#include "DulapManager.h"
#include <thread>
#include <chrono>

//DulapManager::DulapManager() {}

DulapManager::DulapManager(string numeDezinfectant, string numeParfum){
    apa.setFull();
    apa.setNume("apa");
    dezinfectant.setFull();
    dezinfectant.setNume(numeDezinfectant);
    parfum.setFull();
    parfum.setNume(numeParfum);
}

bool DulapManager::spray(Consumable& c) {
    if (c.getProcent() > 0) {
        c.spray(20);
        cout<<c.getNume()<<" fas fas!! --"<<c.getProcent()<< "% \n";
        return true;
    }
    return false;
}

void DulapManager::sprayThread(int timer, Consumable& c){
    while (true) {
        if (spray(c))
            std::this_thread::sleep_for(std::chrono::seconds(timer));
        else break;
    }
}