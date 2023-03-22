cmake_minimum_required(VERSION 3.20)
project(pakeditor)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendor)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

add_executable(pakeditor 
        src/pakeditor/main.cpp 
        src/pakeditor/ui.cpp
)

target_include_directories(pakeditor
        PRIVATE ${GTKMM_INCLUDE_DIRS} include/
)
target_link_libraries(pakeditor 
        PRIVATE ${GTKMM_LIBRARIES} libpak
)