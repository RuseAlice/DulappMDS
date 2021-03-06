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
//    h3.setDisponibilitate(false);
//    h4.setDisponibilitate(false);
//    h5.setDisponibilitate(false);
//    h6.setDisponibilitate(false);
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
    haine.insert(pair<int, Haina>(13,h13));
    haine.insert(pair<int, Haina>(14,h14));
    haine.insert(pair<int, Haina>(15,h15));
    haine.insert(pair<int, Haina>(16,h16));
    haine.insert(pair<int, Haina>(17,h17));
    haine.insert(pair<int, Haina>(18,h18));
    haine.insert(pair<int, Haina>(19,h19));
    haine.insert(pair<int, Haina>(20,h20));

//    HaineManager haineManager(haine,20);
//
//    haineManager.introducereHaina("rochie neagra", piesaUnica, Negru, sport, bumbac);
//
//    haineManager.introducereHaina("vesta de fas", jacheta,Negru, sport, fas);
//
//    haineManager.introducereHaina("rochie neagra", piesaUnica, Negru, sport, bumbac);
//    haineManager.editareHaina(h1, "helanca", top, Bej,casual, poliester);

    HaineManager *haineManager=haineManager->getManager();

    haineManager->introducereHaina("rochie neagra", piesaUnica, Negru, sport, bumbac);
    haineManager->introducereHaina("vesta de fas", jacheta,Negru, sport, fas);
    haineManager->introducereHaina("blugi", pantaloni, Albastru, casual, denim);
    haineManager->introducereHaina("tricou flori", top, Mov,casual, bumbac);
    haineManager->introducereHaina("geaca fas", jacheta,Albastru, casual, fas);
    haineManager->introducereHaina("blugi rupti", pantaloni, Gri, sport, denim);
    haineManager->introducereHaina("camasa cu volane", top, Negru, casual, poliester);
    haineManager->introducereHaina("haina de blana", jacheta,Bej, casual, poliester);
    haineManager->introducereHaina("salopeta matasoasa", piesaUnica, Portocaliu, formal, matase);
    haineManager->introducereHaina("fusta plisata", pantaloni, Gri, formal, stofa);
    haineManager->introducereHaina("helanca", top, Bej, casual, poliester);
    haineManager->introducereHaina("hanorac cu gluga", jacheta, Verde, sport, bumbac);
    haineManager->introducereHaina("vesta de fas", jacheta, Negru, sport, fas);
    haineManager->introducereHaina("tricou polo", top, Galben, sport, bumbac);
    haineManager->introducereHaina("camasa simpla", top, Alb, formal, bumbac);
    haineManager->introducereHaina("ie traiditionala", top, Alb, formal, in);
    haineManager->introducereHaina("sacou", jacheta, Bleumarin, business, lana);
    haineManager->introducereHaina("rochie rosie", piesaUnica, Rosu, formal, fas);
    haineManager->scoatereHaina(2);
    haineManager->scoatereHaina(5);
    haineManager->scoatereHaina(7);



    haineManager->editareHaina(3, "helanca", top, Bej,casual, poliester);

//    for(auto &item:haineManager->getHaine()){
//        cout<<item.first<<": "<<item.second.afisare()<<'\n';
//    }

    CLI *cli=new CLI();
    cli->mainMenu(0);


//REINTRODUCERE HAINA
//for(auto &item: haineManager.getHaine()){
//    if(item.second.getDisponibilitate()== false)
//        cout<<item.first<<": "<<item.second.afisare()<<"\n";
//}
//int nr;
//cout<<"Alegeti nr hainei pe care doriti sa o intorduceti: ";
//cin>>nr;
//haineManager.reintroducereHaina(nr);
//    for(auto &item: haineManager.getHaine()){
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//    for(auto &item: haineManager->getHaine()){
//        cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//int umerase[3]={-1,-1,-1};
//bool jacheta;
//bool piesaUnica;
//int nr_articole=0;
//cout<<"Doriti jacheta?";
//cin>>jacheta;
//cout<<"O singura piesa?";
//cin>>piesaUnica;
//if(jacheta){
//    for(auto &item:haineManager->getHaine()){
//        if(item.second.getPiesaVestimentara()==jacheta)
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//    cin>>umerase[nr_articole];
//    nr_articole++;
//}
//if(piesaUnica){
//    for(auto &item:haineManager->getHaine()){
//        if(item.second.getPiesaVestimentara()==piesaUnica)
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//    cin>>umerase[nr_articole];
//    nr_articole++;
//}else{
//    for(auto &item:haineManager->getHaine()){
//        if(item.second.getPiesaVestimentara()==top)
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//    cin>>umerase[nr_articole];
//    nr_articole++;
//    for(auto &item:haineManager->getHaine()){
//        if(item.second.getPiesaVestimentara()==pantaloni)
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }
//    cin>>umerase[nr_articole];
//    nr_articole++;
//}
//haineManager->creareTinuta(jacheta, piesaUnica,umerase[0], umerase[1], umerase[2]);
//
//    for(auto &item: haineManager->getHaine()){
//            cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }


//haineManager.generareTinuta(20, false, casual);
//    for(auto &item: haineManager.getHaine()){
//        cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }


//
//haineManager->generareTinuta(20, false, casual);
//    for(auto &item: haineManager->getHaine()){
//        cout<<item.first<<": "<<item.second.afisare()<<"\n";
//    }


    return 0;
}
