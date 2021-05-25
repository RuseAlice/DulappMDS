cmake_minimum_required(VERSION 3.19)
project(Dulapp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dulapp Main/main.cpp
        Entities/Haina.h

        Interface/Interface.h
        Interface/Interface.cpp
        Services/DulapManager.h
        Services/DulapManager.cpp
        Services/HaineManager.h

        Services/SearchEngine.h
        Services/SearchEngine.cpp
        Services/NotificationManager.h
        Services/NotificationManager.cpp
        Entities/Consumable.h
        Entities/Consumable.cpp)