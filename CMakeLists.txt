cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(zeta_r LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Boost 1.68 REQUIRED COMPONENTS math_c99 chrono)

add_executable(${PROJECT_NAME}
    "mainwindow.ui" "mainwindow.cpp" "mainwindow.hpp"
    "main.cpp"
    "chartview.hpp" "chartview.cpp"
    "chart.hpp" "chart.cpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Charts Boost::math_c99 Boost::chrono)
