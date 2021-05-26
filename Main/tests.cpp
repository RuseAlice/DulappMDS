#include <catch2/catch_all.hpp>
#include "../Entities/Consumable.h"
#include "../Services/DulapManager.h"
#include "../Entities/Haina.h"
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