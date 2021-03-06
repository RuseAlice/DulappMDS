cmake_minimum_required(VERSION 3.19)
project(Dulapp)

set(CMAKE_CXX_STANDARD 14)
find_package(Catch2 REQUIRED)
find_package(Threads REQUIRED)
include(FetchContent)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()



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
        Services/JSONHandler.cpp
        Services/JSONHandler.h
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
target_link_libraries(Dulapp PRIVATE curl Threads::Threads -lpistache PRIVATE nlohmann_json::nlohmann_json)