cmake_minimum_required(VERSION 3.15)
project(abyss LANGUAGES CXX)

find_package(pybind11 REQUIRED)

# kaynaklar
set(SOURCES
    src/main.cpp
    src/state_machine.cpp
    src/state.cpp
    src/transition.cpp
)

# modulu olustr
pybind11_add_module(core ${SOURCES})

# headerlari ekle
target_include_directories(core PRIVATE include)

# .so cikis yolu veya windows icin baska macte de so cikiomus
set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/abyss")