cmake_minimum_required(VERSION 3.22)
project(stalingrad)

# Setting C++03 compatibility as we discussed
set(CMAKE_CXX_STANDARD 98)

# 1. Find the SFML package on your Ubuntu system
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 2. Add your main executable
add_executable(
        stalingrad
        main.cpp
        principal.cpp
        principal.hpp
        jogador.hpp
        jogador.cpp)

# 3. THIS IS THE MAGIC LINE TO FIX YOUR ERROR:
# It links the SFML libraries to the 'stalingrad' executable
target_link_libraries(stalingrad sfml-graphics sfml-window sfml-system)