//
// Created by bogdan on 5/28/21.
//

#ifndef DULAPP_JSONHANDLER_H
#define DULAPP_JSONHANDLER_H

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

class JSONHandler {
public:
    static string parseJSONFromFile(ifstream&);
    static string parseJSON(json);
    static json getJSONFromString(string);
    static json getJSONFromFile(ifstream&);
};



#endif //DULAPP_JSONHANDLER_H
