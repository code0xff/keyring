cmake_minimum_required(VERSION 3.20)
project(keyring)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("-Wno-c++11-narrowing")

if(APPLE)
    set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
    set(BOOST_ROOT /usr/local/opt/boost)
endif()

include(FetchContent)
FetchContent_Declare(
        fc
        GIT_REPOSITORY "https://github.com/EOSIO/fc"
        GIT_TAG 0b45f08f656d0f68f383ab13bd3f1b29cadb942f
)
FetchContent_MakeAvailable(fc)

add_executable(keyring main.cpp bech32.h bech32.cpp util/vector.h)
target_link_libraries(keyring fc)