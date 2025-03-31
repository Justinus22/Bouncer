cmake_minimum_required(VERSION 3.28)
project(Bouncer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Bouncer src/main.cpp src/Application.cpp src/GameState.cpp src/Button.cpp src/MainMenu.cpp src/Gameplay.cpp src/PlatformGenerator.cpp src/Bouncer.cpp src/Platform.cpp src/GameOver.cpp src/AssetManager.cpp)

target_include_directories(Bouncer PRIVATE include)
target_compile_features(Bouncer PRIVATE cxx_std_17)
target_link_libraries(Bouncer PRIVATE SFML::Graphics)
