cmake_minimum_required(VERSION 3.31)
project(Search_Engine_Model_Qt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Qt6_DIR "/Users/davidberbecar/Qt/6.9.0/macos/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(Search_Engine_Model_Qt
        main.cpp
        gui.h
        gui.cpp
        gui.ui
        Service.h
        Service.cpp
        Document.h
        Document.cpp
)

target_link_libraries(Search_Engine_Model_Qt
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)