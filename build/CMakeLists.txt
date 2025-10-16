cmake_minimum_required(VERSION 3.10)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

# Caminho para o código-fonte
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../src")
add_executable(calculator "${SRC_DIR}/main.cpp")

# Tratamento de erro para FLTK
find_package(FLTK REQUIRED)
if (NOT FLTK_FOUND)
    message(FATAL_ERROR "FLTK não encontrado. Por favor, instale a biblioteca FLTK antes de compilar.")
endif()

# Vincula a biblioteca FLTK
target_link_libraries(calculator PRIVATE fltk)
