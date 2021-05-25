//
// Created by alice on 25.05.2021.
//

#ifndef DULAPP_INTERFACE_H
#define DULAPP_INTERFACE_H
enum language {en, ro};

class Interface {

protected:
    language lang=ro;
public:
    virtual void mainMenu(const int &menuPage) = 0;
//    virtual void checkRecommendations() = 0;
//    virtual void checkWeather() = 0;
//    virtual void checkEvents() = 0;
//    virtual void checkConsumables() = 0;
//    virtual void showFreeHangers() = 0;
//    virtual void showControlsAndSettings() = 0;
};

class CLI: public Interface {
public:
    void mainMenu(const int &menuPage) override;
    CLI()=default;
};
#endif //DULAPP_INTERFACE_H
