cmake_minimum_required(VERSION 3.0.0)
project(StalinSort VERSION 0.1.0)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES catch2/2.13.6
                      BASIC_SETUP
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(Catch2 REQUIRED)

add_library(StalinSort INTERFACE stalinsort.hpp)
target_compile_features(StalinSort INTERFACE cxx_std_11)

enable_testing()
add_executable(StalinTest test.cpp)
target_link_libraries(StalinTest Catch2::Catch2 StalinSort)
target_compile_options(StalinTest PRIVATE -Wall -Wextra -Werror -Wfatal-errors -Wpedantic)
add_test(NAME StalinTest COMMAND StalinTest)
