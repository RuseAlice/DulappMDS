cmake_minimum_required(VERSION 3.19)
project(Dulapp)

find_package(Catch2 REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dulapp Main/main.cpp
        Entities/Haina.h
        Entities/Consumable.h

        Interface/Interface.h
        Interface/Interface.cpp

        Services/DulapManager.h
        Services/DulapManager.cpp
        Services/HaineManager.h
        Services/SearchEngine.h
        Services/SearchEngine.cpp
        Services/NotificationManager.h
        Services/NotificationManager.cpp
)

add_executable(tests Main/tests.cpp
        Entities/Consumable.h
        Entities/Consumable.cpp
        Entities/Haina.h
        Entities/Haina.cpp

        Services/DulapManager.h
        Services/DulapManager.cpp
        Services/HaineManager.h
        Services/HaineManager.cpp
        Services/SearchEngine.h
        Services/SearchEngine.cpp
        )

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Threads::Threads)