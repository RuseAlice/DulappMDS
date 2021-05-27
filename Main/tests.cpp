#include <catch2/catch_all.hpp>
#include "../Entities/Consumable.h"
#include "../Services/DulapManager.h"
#include "../Entities/Haina.h"
#include "../Services/HaineManager.h"
#include "../Services/SearchEngine.h"
#include <thread>

TEST_CASE("Testeaza Consumabilele (unit)", "[consumabile]") {
    SECTION("Constructor default + set/get") {
        Consumable parfum;
        REQUIRE(parfum.getNume() == "");
        REQUIRE(parfum.getProcent() == 0);
        parfum.setNume("Refresh");
        parfum.setProcent(50);
        REQUIRE(parfum.getNume() == "Refresh");
        REQUIRE(parfum.getProcent() == 50);
    }
    SECTION("Constructor custom + metodele") {
        Consumable apa("apa", 100); //test constructor + metode
        apa.spray(2);
        apa.spray(2);
        REQUIRE(apa.getProcent() == 96);
        apa.setFull();
        REQUIRE(apa.getProcent() == 100);
        Consumable apa2("apa", 100);
        REQUIRE (apa == apa2);
    }
}

TEST_CASE("Testare DulapManager (integration)", "[consumabile][dulap]") {
    DulapManager DM;
    Consumable dezinfectant = DM.getDezinfectant();
    dezinfectant.setNume("Dettol");
    REQUIRE(dezinfectant.getNume() == "Dettol");
    // REQUIRE(dezinfectant.getNume() == DM.getDezinfectant().getNume()); // copiere, nu atribuire"
    DM.getApa().setFull();
    std::thread t1 = std::thread(&DulapManager::sprayThread, &DM, 0.5, std::ref(DM.getApa()));
    t1.join();
    REQUIRE(DM.getApa().getProcent() == 0); // se face spray pana ajunge la 0
    DM.setFull();
    REQUIRE(DM.getParfum().getProcent() == 100);
}

TEST_CASE("Testare Haine (unit)", "[haine]") {
    SECTION("Testare Constructori + set/get") {
        Haina h0;
        //cout << h0.afisare();
        //REQUIRE((h0.getDenumire() == "" && h0.getMaterial() == null_material && h0.getCuloare() == null_culoare && h0.getDisponibilitate() == false && h0.getStil() == null_stil && h0.getPiesaVestimentara() == null_piesa)); // nu se initializeaza enum cu null_etc
        Haina h1("camasa simpla", top, Alb, formal, bumbac);
        REQUIRE((h1.getDenumire() == "camasa simpla" && h1.getMaterial() == bumbac && h1.getPiesaVestimentara() == top && h1.getCuloare() == Alb && h1.getStil() == formal && h1.getDisponibilitate() == true && h1.getNrPurtari() == 0));
        h1.setCuloare(Albastru);
        REQUIRE(h1.getCuloare() == Albastru);
        h1.setDisponibilitate(true);
        REQUIRE(h1.getDisponibilitate() == true);
    }
    SECTION("Metode") {
        Haina h2("tricou flori", top, Mov,casual, bumbac);
        //h2.afisare();
        REQUIRE(h2.verificarePotrivire(Verde, formal, 20.0) == false);
        Haina h3 ("sacou", jacheta, Bleumarin, business, lana);
        REQUIRE(h3.verificarePotrivire(Bleumarin, business, 15.0) == true);
    }
}

TEST_CASE("Teste HaineManager (unit si integration)", "[haine][dulap]"){
    Haina h1("camasa simpla", top, Alb, casual, bumbac);
    Haina h2 ("geaca verde", jacheta, Verde, business, stofa);
    Haina h3 ("rochie rosie", piesaUnica, Rosu, casual, matase);
    Haina h4 ("blugi", pantaloni, Albastru, casual, denim);
    Haina h5 ("tricou flori", top, Mov,casual, bumbac);
    Haina h6 ("geaca fas", jacheta,Albastru, casual, fas);
    Haina h7("helanca", top, Bej,business, poliester);
    Haina h8 ("fusta plisata", pantaloni, Gri, business, stofa);
    map<int, Haina> haine;
    haine.insert(haine.begin(), pair<int, Haina>(1,h1));
    haine.insert(pair<int, Haina>(2,h2));
    haine.insert(pair<int, Haina>(3,h3));
    haine.insert(pair<int, Haina>(4,h4));
    haine.insert(pair<int, Haina>(5,h5));
    haine.insert(pair<int, Haina>(6,h6));
    haine.insert(pair<int, Haina>(7,h7));
    haine.insert(pair<int, Haina>(8, h8));
    HaineManager HM(haine, 8);
    REQUIRE(HM.getNrUmerase() == 8);
    //HM.vizualizareHaina(h4);
    HM.setNrUmerase(10);
    REQUIRE(HM.getNrUmerase() == 10);
    HM.editareHaina(h4, "sacou", jacheta, Gri, business, bumbac); //editarea se face in dulap
    REQUIRE(HM.getHaine().find(4)->second.getDenumire() == "sacou"); // ne uitam in dulap
    HM.stergereHaina(h6);
    //REQUIRE(HM.getNrUmerase() == 5);  //fals pt ca doar pentru ca haina e eliminata din dulap, asta nu inseamna ca si umerasul dispare
    REQUIRE(HM.getHaine().count(6) == 0); //cu find(6) == haine.end() nu merge
    HM.generareTinuta(15.0, false, casual);
    HM.generareTinuta(30.0, false, business); // de ce nu merge??
}

TEST_CASE("Teste SearchEngine (unit si integration)", "[haine][search]") {
    Haina h1("camasa simpla", top, Alb, casual, bumbac);
    Haina h2 ("geaca verde", jacheta, Verde, business, stofa);
    Haina h3 ("rochie rosie", piesaUnica, Rosu, casual, matase);
    Haina h4 ("blugi", pantaloni, Albastru, casual, denim);
    Haina h5 ("tricou flori", top, Mov,casual, bumbac);
    Haina h6 ("geaca fas", jacheta,Albastru, casual, fas);
    Haina h7 ("camasa cu volane", top, Negru, formal, poliester);
    Haina h8 ("camasa simpla", top, Alb, formal, bumbac);
    map<int, Haina> haine;
    haine.insert(haine.begin(), pair<int, Haina>(1,h1));
    haine.insert(pair<int, Haina>(2,h2));
    haine.insert(pair<int, Haina>(3,h3));
    haine.insert(pair<int, Haina>(4,h4));
    haine.insert(pair<int, Haina>(5,h5));
    haine.insert(pair<int, Haina>(6,h6));
    haine.insert(pair<int, Haina>(7,h7));
    haine.insert(pair<int, Haina>(8, h8));
    SearchEngine SE;

    map<int,Haina> haineCasual = SE.cautare(haine, casual);
    REQUIRE(haineCasual.size() == 5);
    //for (auto &item : haineCasual)
    //    cout << item.second.afisare();
    map<int,Haina> camasi = SE.cautare(haine, "camasa");
    REQUIRE(camasi.size() == 3);
}