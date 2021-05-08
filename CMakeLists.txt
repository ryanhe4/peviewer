cmake_minimum_required(VERSION 3.19)
project(peviewer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "C:/Qt/6.1.0/msvc2019_64/lib/cmake")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets SvgWidgets Xml)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

add_subdirectory(src)