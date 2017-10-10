cmake_minimum_required(VERSION 3.8)
project(cpp_2nd_tw_mighty_text_adventure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Area.hpp Game.cpp Game.h src/Room.cpp src/Room.h src/Connection.cpp src/Connection.h src/Player.cpp src/Player.h src/ItemDescriptor.cpp src/ItemDescriptor.h src/Item.cpp src/Item.h src/Inventory.cpp src/Inventory.h)
add_executable(cpp_2nd_tw_mighty_text_adventure ${SOURCE_FILES})