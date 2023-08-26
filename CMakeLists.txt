cmake_minimum_required(VERSION 3.20)
project(PrimeNumbsFind VERSION 0.1.0)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)

find_package(Boost REQUIRED)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG e68764c147ea0dac1e8811925c531d937396878e 
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  GoogleBenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG 2257fa4d6afb8e5a2ccd510a70f38fe7fcdf1edf
)
FetchContent_MakeAvailable(GoogleBenchmark)

set(BENCHMARK_ENABLE_TESTING OFF)

add_subdirectory(PrimeNumbs)

add_executable(PrimeNumbsFind main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC
  PrimeNumbsKPEq
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
