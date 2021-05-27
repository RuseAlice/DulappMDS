//
// Created by alice on 25.05.2021.
//

#include "Interface.h"
#include "../Services/HaineManager.cpp"
#include <stdio.h>
#include <iostream>
#include <limits>
#include <fstream>
#include <thread>
#include "../Services/DulapManager.h"

using std::numeric_limits;

void CLI::mainMenu(const int &menuPage) {

    std::ofstream myFile("Logfile.txt");

    int newPage = -1;
    HaineManager *hm=hm->getManager();
    DulapManager dm= DulapManager("Dettol","Khalis");
    switch (menuPage) {
        case 0: {
            if (this->lang == en) {
                std::cout << "Welcome to SmartDrobe!\n";
                std::cout << "What can I help you with? \342\230\272 \n" <<
                          "Enter one of the numbers below to let me know!\n";
                // \342\230\272 este smiley face
                std::cout << "1. Consult outfit recommendations for today.\n" <<
                          "2. Check what the weather is going to be.\n" <<
                          "3. View my upcoming events.\n" <<
                          "4. Modify wardrobe.\n" <<
                          "5. See hangers.\n" <<
                          "6. Access controls and settings.\n";
                for (;;) {
                    std::cout << "So which one will it be? ";
                    if (std::cin >> newPage && newPage > 0 && newPage < 7) {
                        std::cout << "Success!/n";
                        if (newPage == 1) myFile << "1. Consult outfit recommendations for today.\n";
                        else if (newPage == 2) myFile << "2. Check what the weather is going to be.\n";
                        else if (newPage == 3) myFile << "3. View my upcoming events.\n";
                        else if (newPage == 4) myFile << "4. Modify wardrobe.\n";
                        else if (newPage == 5) myFile <<  "5. See hangers.\n";
                        else if (newPage == 6) myFile << "6. Access controls and settings.\n";
                        break;
                    } else {
                        std::cout << R"(I asked you to choose one of the given numbers! \342\230\272)" << std::endl;
                        std::cout << "Let's try again!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            } else {
                std::cout << "SmartDrobe îți stă la dispoziție!\n";
                std::cout << "Cum te pot ajuta? \342\230\272\n"
                          << "Introdu unul dintre numerele comenzilor de mai jos!\n";
                std::cout << "1. Consultă recomandările de ținute pentru azi.\n" <<
                          "2. Verifică starea meteo.\n" <<
                          "3. Creeaza o tinuta.\n" <<
                          "4. Modifcă articolele din dulap.\n" <<
                          "5. Vezi umerașele.\n" <<
                          "6. Accesează setările.\n";
                for (;;) {
                    std::cout << "Așadar, ce alegi? ";
                    if (std::cin >> newPage && newPage > 0 && newPage < 7) {
                        //std::cout << "Success!/n/n";
                        if (newPage == 1) myFile << "1. Consultă recomandările de ținute pentru azi.\n";
                        else if (newPage == 2) myFile << "2. Verifică starea meteo.\n";
                        else if (newPage == 3) myFile << "3. Vezi evenimentele imediat viitoare.\n";
                        else if (newPage == 4) myFile << "4. Modifcă articolele din dulap.\n";
                        else if (newPage == 5) myFile << "5. Vezi umerașele.\n";
                        else if (newPage == 6) myFile << "6. Accesează setările.\n";
                        break;
                    } else {
                        std::cout << "Trebuie să alegi una dintre opțiunile valabile! \342\230\272" << std::endl;
                        std::cout << "Să încercăm din nou!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }
            break;
        }
        case 1: {
            float temp;
            bool precipitatii;
            int stil;
            cout<<"Care este temperatura de astazi?";
            cin>>temp;
            cout<<"Sunt anuntate precipitatii?";
            cin>>precipitatii;

            for (;;) {
                cout<<"Care este stilul pe care il doresti astazi?";
                std::cout << "1. casual\n 2. sport\n 3. business\n 4. formal\n";
                if (std::cin >> stil && stil > 0 && stil < 5) {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            hm->generareTinuta(temp, precipitatii, (Stil)stil);


            break;
        }
        case 2: //nu tine de menu interface, te trimite la aplicatia/ site ul cu prognoze
            break;
        case 3: {
            int umerase[3]={-1,-1,-1};
            bool jacheta;
            bool piesaUnica;
            int nr_articole=0;
            cout<<"Doriti jacheta?";
            cin>>jacheta;
            cout<<"O singura piesa?";
            cin>>piesaUnica;
            if(jacheta){
                for(auto &item:hm->getHaine()){
                    if(item.second.getPiesaVestimentara()==jacheta)
                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                }
                cin>>umerase[nr_articole];
                nr_articole++;
            }
            if(piesaUnica){
                for(auto &item:hm->getHaine()){
                    if(item.second.getPiesaVestimentara()==piesaUnica)
                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                }
                cin>>umerase[nr_articole];
                nr_articole++;
            }else{
                for(auto &item:hm->getHaine()){
                    if(item.second.getPiesaVestimentara()==top)
                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                }
                cin>>umerase[nr_articole];
                nr_articole++;
                for(auto &item:hm->getHaine()){
                    if(item.second.getPiesaVestimentara()==pantaloni)
                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                }
                cin>>umerase[nr_articole];
                nr_articole++;
            }
            hm->creareTinuta(jacheta, piesaUnica,umerase[0], umerase[1], umerase[2]);



            break;
        }
            break;
        case 4: {
            int contentAction = 0;
            if (this->lang == en) {
                std::cout << "So you want to modify my content! What exactly will you do?\n";
                std::cout << "1. Add a new clothing item.\n";
                std::cout << "2. Edit one of the clothing items.\n";
                std::cout << "3. Delete a clothing item.\n";
                for (;;) {
                    std::cout << "Let me know your intention by typing the number of the upcoming action! ";
                    if (std::cin >> contentAction && contentAction > 0 && contentAction < 4) {
                        std::cout << "Success!/n";
                        if (contentAction == 1) myFile << "1. Add a new clothing item.\n";
                        else if (contentAction == 2) myFile << "2. Edit one of the clothing items.\n";
                        else if (contentAction == 3) myFile << "3. Delete a clothing item.\n";
                        break;
                    } else {
                        std::cout << "Please don't make up your own actions! \342\230\272" << std::endl;
                        std::cout << "Remember! Only the numbers from my list are available!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            } else {
                std::cout << "Îmi modifici conținutul? În ce mod mai exact?\n";
                std::cout << "1. Adaug un nou articol vestimentar.\n";
                std::cout << "2. Editez un articol vestimentar cunoscut.\n";
                std::cout << "3. Elimin un articol vestimentar.\n";
                std::cout << "4. Adaug un articol existent.\n";
                for (;;) {
                    std::cout << "Introdu numărul acțiunii ca să știu și eu ce faci! ";
                    if (std::cin >> contentAction && contentAction > 0 && contentAction < 5) {
                        switch (contentAction) {
                            case 1:
                            {
                                std::string nume;
                                int culoare;
                                int material;
                                int stil;
                                int piesa;
                                std::cout << "Introdu denumirea articolului vestimentar: ";
                                std::cin >> nume;
                                for (;;) {
                                    std::cout << "Alege culoarea articolului vestimentar: ";
                                    std::cout << "1. Alb\n 2. Negru\n 3. Albastru\n 4. Verde\n 5. Galben\n "
                                              << "6. Rosu\n 7. Portocaliu\n 8. Bleumarin\n 9. Gri\n 10. Bej\n 11. Maro\n 12. Mov\n";
                                    if (std::cin >> culoare && culoare > 0 && culoare < 13) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege materialul articolului vestimentar: ";
                                    std::cout << "1. poliester\n 2. bumbac\n 3. stofa\n 4. denim\n 5. matase\n "
                                              << "6. in\n 7. fas\n 8. lana\n";
                                    if (std::cin >> material && material > 0 && material < 9) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege stilul articolului vestimentar: ";
                                    std::cout << "1. casual\n 2. sport\n 3. business\n 4. formal\n";
                                    if (std::cin >> stil && stil > 0 && stil < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege piesa articolului vestimentar: ";
                                    std::cout << "1. jacheta\n 2. top\n 3. pantaloni\n 4. piesa unica\n";
                                    if (std::cin >> piesa && piesa > 0 && piesa < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                hm->introducereHaina(nume, (PiesaVestimentara) piesa, (Culoare) culoare, (Stil) stil,(Material) material);
                                for(auto &item: hm->getHaine()){
                                    cout<<item.first<<" "<<item.second.afisare()<<'\n';
                                }
                                break;
                            }
                            case 2:{
                                cout<<"Alege numarul umerasului pe care se afla articolul vestimentar pe care vrei sa-l editezi!";
                                for(auto &item: hm->getHaine()){
                                    cout<<item.first<<" "<<item.second.afisare()<<'\n';
                                }
                                int nrUmeras;
                                std::string nume;
                                int culoare;
                                int material;
                                int stil;
                                int piesa;
                                for(;;){
                                    if (std::cin >> nrUmeras && nrUmeras > 0 && nrUmeras < hm->getNrUmerase()){
                                        break;
                                    }else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }

                                std::cout << "Introdu noua denumire a articolului vestimentar: ";
                                std::cin >> nume;
                                for (;;) {
                                    std::cout << "Alege noua culoare a articolului vestimentar: ";
                                    std::cout << "1. Alb\n 2. Negru\n 3. Albastru\n 4. Verde\n 5. Galben\n "
                                              << "6. Rosu\n 7. Portocaliu\n 8. Bleumarin\n 9. Gri\n 10. Bej\n 11. Maro\n 12. Mov\n";
                                    if (std::cin >> culoare && culoare > 0 && culoare < 13) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege noul material al articolului vestimentar: ";
                                    std::cout << "1. poliester\n 2. bumbac\n 3. stofa\n 4. denim\n 5. matase\n "
                                              << "6. in\n 7. fas\n 8. lana\n";
                                    if (std::cin >> material && material > 0 && material < 9) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege noul stil al articolului vestimentar: ";
                                    std::cout << "1. casual\n 2. sport\n 3. business\n 4. formal\n";
                                    if (std::cin >> stil && stil > 0 && stil < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege piesa articolului vestimentar: ";
                                    std::cout << "1. jacheta\n 2. top\n 3. pantaloni\n 4. piesa unica\n";
                                    if (std::cin >> piesa && piesa > 0 && piesa < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                hm->editareHaina(nrUmeras, nume, (PiesaVestimentara) piesa, (Culoare) culoare, (Stil) stil,(Material) material);
                                for(auto &item: hm->getHaine()){
                                    cout<<item.first<<" "<<item.second.afisare()<<'\n';
                                }
                                break;

                            }
                            case 3:{
                                cout<<"Alege numarul umerasului pe care se afla articolul vestimentar pe care vrei sa-l indepartezi!";
                                for(auto &item: hm->getHaine()){
                                    cout<<item.first<<" "<<item.second.afisare()<<'\n';
                                }
                                int nrUmeras;
                                for(;;){
                                    if (std::cin >> nrUmeras && nrUmeras > 0 && nrUmeras < hm->getNrUmerase()){
                                        break;
                                    }else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                hm->stergereHaina(nrUmeras);
                                for(auto &item: hm->getHaine()){
                                    cout<<item.first<<" "<<item.second.afisare()<<'\n';
                                }
                                break;

                            }
                            case 4:{
                                for(auto &item: hm->getHaine()){
                                    if(item.second.getDisponibilitate()== false)
                                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                                }
                                int nr;
                                cout<<"Alegeti nr hainei pe care doriti sa o intorduceti: ";
                                cin>>nr;
                                hm->reintroducereHaina(nr);
                                    for(auto &item: hm->getHaine()){
                                            cout<<item.first<<": "<<item.second.afisare()<<"\n";
                                    }
                                    for(auto &item: hm->getHaine()){
                                        cout<<item.first<<": "<<item.second.afisare()<<"\n";
                                    }
                                break;
                            }
                        }

                        if (contentAction == 1) myFile << "1. Add a new clothing item.\n";
                        else if (contentAction == 2) myFile << "2. Edit one of the clothing items.\n";
                        else if (contentAction == 3) myFile << "3. Delete a clothing item.\n";
                        break;
                    } else {
                        std::cout << "Te rog nu inventa acțiuni! \342\230\272" << std::endl;
                        std::cout << "Ține minte! Numai acțiunile din lista mea sunt acceptate!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }
            break;
        }

        case 5: {
            for(int i=1;i<=hm->getNrUmerase();i++){
                if(hm->getHaine().find(i)==hm->getHaine().end()){
                    cout<<i<<": umerasul este gol \n";
                }else{
                    if(hm->getHaine().find(i)->second.getDisponibilitate()){
                        cout<<i<<": "<<hm->getHaine().find(i)->second.afisare()<<"\n";
                    }else{
                        cout<<i<<": umerasul este gol \n";
                    }
                }
            }

            break;
        }//metoda de a afisa umerasele cu status liber/ ocupat

        case 6: {
            cout<<"Alege actiunea dorita:";
            cout<<"1.Starea consumabilelor \n 2.Spray acum \n 3.Set timer";
            int actiune;
            for(;;){
                if (std::cin >> actiune && actiune > 0 && actiune < 4) {
                        switch(actiune){
                            case 1:{
                                cout<<"Apa: "<<dm.getApa().getProcent()<<"% \n";
                                cout<<"Dezinfectant: "<<dm.getDezinfectant().getProcent()<<"% \n";
                                cout<<"Parfum: "<<dm.getParfum().getProcent()<<"% \n";
                                break;
                            }
                            case 2:{
                                int parfum;
                                cout<<"Cu ce doresti sa pulverizezi?\n 1.Dezinfectant\n 2.Parfum\n";
                                for(;;){
                                    if (std::cin >> parfum && parfum > 0 && parfum < 3){
                                        if(parfum==1){
                                            dm.spray(dm.getDezinfectant());
                                        }else{
                                            dm.spray(dm.getParfum());
                                        }
                                        break;
                                    }else{
                                        std::cout << "Alege doar unul din numerele afisate! \342\230\272" << std::endl;
                                        std::cin.clear();
                                    }
                                }

                                break;
                            }
                            case 3:{
                                int parfum;
                                int interv;
                                cout<<"Introdu intervalul pe care il doresti intre pulverizari(nr de secunde)";
                                cin>>interv;
                                cout<<"Cu ce doresti sa pulverizezi?\n 1.Dezinfectant\n 2.Parfum\n";
                                for(;;){
                                    if (std::cin >> parfum && parfum > 0 && parfum < 3){
                                        if(parfum==1){

                                            std::thread t1 = std::thread(&DulapManager::sprayThread, &dm, interv, std::ref(dm.getDezinfectant()));
                                            t1.join();

                                        }else{
                                            std::thread t1 = std::thread(&DulapManager::sprayThread, &dm, interv, std::ref(dm.getParfum()));
                                            t1.join();
                                        }
                                        break;
                                    }else{
                                        std::cout << "Alege doar unul din numerele afisate! \342\230\272" << std::endl;
                                        std::cin.clear();
                                    }

                                break;
                            }
                        }
                        }
                    break;
                } else{
                    std::cout << "Alege doar unul din numerele afisate! \342\230\272" << std::endl;
                    std::cin.clear();
                }
            }


            break;
        }

    }
    mainMenu(newPage);
    myFile.close();
}