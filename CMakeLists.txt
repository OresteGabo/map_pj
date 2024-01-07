# CMakeLists.txt in the project's root directory

cmake_minimum_required(VERSION 3.26)
project(map_pj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Network  REQUIRED)


# Add your main executable
add_executable(map_pj main.cpp
        Widget.cpp
        Widget.h
        App.cpp
        App.h
        Car.cpp
        Car.h
        Arret.cpp
        Arret.h
        PathNode.cpp
        PathNode.h
        Path.cpp
        Path.h
        Hexagon.cpp
        Hexagon.h
        MapWidget.cpp
        MapWidget.h
        CarConnectionManager.cpp
        CarConnectionManager.h)
target_link_libraries(map_pj
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network  # Add this line


)


