cmake_minimum_required(VERSION 3.25)
project(cpp26_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
# Catch2 we'll use later for tests

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-gdwarf-4)
endif()

include_directories(include)

add_executable(cpp26_test 
    src/main.cpp
    src/string_utils.cpp
)

target_link_libraries(cpp26_test
    PRIVATE
        nlohmann_json::nlohmann_json
        cpr::cpr
        fmt::fmt
        spdlog::spdlog
)