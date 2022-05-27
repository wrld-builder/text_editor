cmake_minimum_required(VERSION 3.5)

project(text_editor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS WebEngineWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS WebEngineCore REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        highlighter.cpp
)

set(PROJECT_RESOURCES
    mainwindow.ui
    mainwindow.h
    highlighter.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(text_editor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(text_editor SHARED
            ${PROJECT_SOURCES} ${PROJECT_RESOURCES}
        )

    else()
        add_executable(text_editor
            ${PROJECT_SOURCES} ${PROJECT_RESOURCES}
        )
    endif()
endif()

target_link_libraries(text_editor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(text_editor PRIVATE Qt${QT_VERSION_MAJOR}::WebEngineWidgets)
target_link_libraries(text_editor PRIVATE Qt${QT_VERSION_MAJOR}::WebEngineCore)

set_target_properties(text_editor PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(text_editor)
endif()
