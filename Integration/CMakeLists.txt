cmake_minimum_required(VERSION 3.19)
project(rh LANGUAGES CXX)
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(rh
    WIN32 MACOSX_BUNDLE
    main.cpp
    rh.cpp
    rh.h
    rh.ui
    events.h
    events.cpp
    events.ui
    residence.cpp
    residence.h
    residence.ui
    service.cpp
    service.h
    service.ui
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui


    image.qrc
    img.qrc
)

target_link_libraries(rh
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS rh
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET rh
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
