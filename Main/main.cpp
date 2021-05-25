#include <iostream>


#include "../Entities/Haina.h"

#include "../Entities/Haina.cpp"
//#include "../Entities/Umeras.h"
#include "../Services/HaineManager.h"
//#include "../Services/HaineManager.cpp"
#include "../Services/SearchEngine.h"
#include "../Services/DulapManager.h"
#include "../Interface/Interface.h"
#include <string>
#include <thread>
#include <map>
#include <curl/curl.h>
using namespace std;
int main(int argc, char **argv) {

    Haina h1 ("geaca verde", jacheta, Verde, casual, stofa);
    Haina h2 ("rochie rosie", piesaUnica, Rosu, formal, matase);
    Haina h3 ("blugi", pantaloni, Albastru, casual, denim);
    Haina h4 ("tricou flori", top, Mov,casual, bumbac);
    Haina h5 ("geaca fas", jacheta,Albastru, casual, fas);
    Haina h6 ("rochie neagra", piesaUnica, Negru, sport, bumbac);
    Haina h7 ("pantaloni de stofa", pantaloni, Maro, formal, stofa);
    Haina h8 ("tricou sport", top, Rosu,sport, bumbac);
    Haina h9 ("salopeta matasoasa", piesaUnica, Portocaliu, formal, matase);
    Haina h10 ("sacou", jacheta, Bleumarin, business, lana);
    Haina h11 ("blugi rupti", pantaloni, Gri, sport, denim);
    Haina h12 ("ie traditionala", top, Alb,formal, in);
    Haina h13 ("haina de blana", jacheta,Bej, casual, poliester);
    Haina h14 ("camasa cu volane", top, Negru, casual, poliester);
    Haina h15 ("camasa simpla", top, Alb, formal, bumbac);
    Haina h16 ("tricou polo", top, Galben,sport, bumbac);
    Haina h17 ("vesta de fas", jacheta,Negru, sport, fas);
    Haina h18 ("fusta plisata", pantaloni, Gri, formal, stofa);
    Haina h19("hanorac cu gluga", jacheta, Verde, sport, bumbac);
    Haina h20("helanca", top, Bej,casual, poliester);



    h4.setNrPurtari(3);
    h5.setNrPurtari(1);
    h3.setNrPurtari(2);
    h10.setNrPurtari(4);
    h7.setNrPurtari(1);


//    DulapManager DM("Dezinfectant", "Parfum");
//    DM.getApa().setFull();
//    std::thread t1 = std::thread(&DulapManager::sprayThread, &DM, 0.2, std::ref(DM.getApa()));
//
//    DM.getDezinfectant().setFull();
//    std::thread t2 = std::thread(&DulapManager::sprayThread, &DM, 0.1, std::ref(DM.getDezinfectant()));
//    t1.join();
//    t2.join();
    map<int, Haina> haine;
    haine.insert(haine.begin(), pair<int, Haina>(1,h1));
    haine.insert(pair<int, Haina>(2,h2));
    haine.insert(pair<int, Haina>(3,h3));
    haine.insert(pair<int, Haina>(4,h4));
    haine.insert(pair<int, Haina>(5,h5));
    haine.insert(pair<int, Haina>(6,h6));
    haine.insert(pair<int, Haina>(7,h7));
    haine.insert(pair<int, Haina>(8,h14));
    haine.insert(pair<int, Haina>(9,h9));
    haine.insert(pair<int, Haina>(10,h10));
    haine.insert(pair<int, Haina>(11,h11));
    haine.insert(pair<int, Haina>(12,h12));
    HaineManager haineManager(haine,20);
   
    haineManager.introducereHaina("rochie neagra", piesaUnica, Negru, sport, bumbac);
    
    haineManager.introducereHaina("vesta de fas", jacheta,Negru, sport, fas);
    
    haineManager.introducereHaina("rochie neagra", piesaUnica, Negru, sport, bumbac);
    haineManager.editareHaina(h1, "helanca", top, Bej,casual, poliester);
    for(auto &item:haineManager.getHaine()){
        cout<<item.first<<": "<<item.second.afisare()<<'\n';
    }
    
    //CLI *cli=new CLI();
    //cli->mainMenu(0);





    return 0;
}
