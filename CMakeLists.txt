cmake_minimum_required(VERSION 3.15...3.26)
set(PYTHON_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/.venv/Scripts/python.exe")
project(
  test_package
  LANGUAGES CXX
  VERSION "0.0.1")

find_package(
  Python
  COMPONENTS Interpreter Development
  REQUIRED)

file(GLOB test_package_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_subdirectory(pybind11)
pybind11_add_module(test_package src/main.cpp ${test_package_SRC})

target_compile_definitions(test_package PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS test_package LIBRARY DESTINATION .)