cmake_minimum_required(VERSION 3.10)
project(StudentuValdymoSistema VERSION 2.0)

# C++ standartas
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Kompiliavimo flagų nustatymas
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Pagrindinė programa
add_executable(programa
    "3 strategija.cpp"
    studentas.cpp
    failai.cpp
)

# Header failai
target_include_directories(programa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================
# Google Test konfigūracija (unit testams)
# ============================================
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    # Google Test atsisiuntimas
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    
    # Windows: prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    
    # Įjungiame testus
    enable_testing()
    
    # Test executable
    add_executable(programa_tests
        test_studentas.cpp
        studentas.cpp
        failai.cpp
    )
    
    # Linkiname su Google Test
    target_link_libraries(programa_tests
        GTest::gtest_main
        GTest::gmock_main
    )
    
    # Pridedame testus į CTest
    include(GoogleTest)
    gtest_discover_tests(programa_tests)
    
    message(STATUS "Unit tests enabled")
endif()

# Diegimo nustatymai
install(TARGETS programa DESTINATION bin)

# Informacija
message(STATUS "")
message(STATUS "========================================")
message(STATUS "Studentų Valdymo Sistema v${PROJECT_VERSION}")
message(STATUS "========================================")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "========================================")
message(STATUS "")