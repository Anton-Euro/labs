cmake_minimum_required(VERSION 3.25)

set(PROJECT_N lab)

project(${PROJECT_N} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

find_package(nlohmann_json 3.11.3 REQUIRED)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/item.cpp
    src/itemlist.cpp 
    src/file.cpp
    src/dir.cpp
    src/listviewexplorer.cpp
)

set(HEADERS
    src/headers/mainwindow.h
    src/headers/item.h
    src/headers/itemlist.h 
    src/headers/file.h
    src/headers/dir.h
    src/headers/listviewexplorer.h
    src/headers/container.h
)

set(UI_HEADERS
    src/ui/ui_mainwindow.h
)

set(RESOURCE_FILES
    src/resources.qrc
)

qt_add_resources(RSS_SOURCES ${RESOURCE_FILES})

add_executable(${PROJECT_N}
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
    ${RSS_SOURCES}
)

target_link_libraries(${PROJECT_N}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    nlohmann_json::nlohmann_json
)


# set(UIS
#     mainwindow.ui
# )
# qt6_wrap_ui(UI_HEADERS ${UIS})