cmake_minimum_required(VERSION 3.5)

set(PRNAME AlteratorQT)

project(${PRNAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(REQUIRES
	Core
	Gui
	Widgets
	Qml
	Quick
	)

add_subdirectory(src)


