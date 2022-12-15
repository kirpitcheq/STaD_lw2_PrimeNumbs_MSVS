cmake_minimum_required(VERSION 3.20)
project(PrimeNumbsFind VERSION 0.1.0)

include(CTest)
enable_testing()

project(p)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.80.0
)
FetchContent_MakeAvailable(Boost)
FetchContent_Declare(
  GoogleBenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG 2257fa4d6afb8e5a2ccd510a70f38fe7fcdf1edf
)
FetchContent_MakeAvailable(GoogleBenchmark)
set(BENCHMARK_ENABLE_TESTING OFF)

# target_link_libraries(boost_test PRIVATE Boost::filesystem
# Boost::program_options)
add_subdirectory(PrimeNumbs)

# add_executable(PrimeNumbsFind main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC
  PrimeNumbsKPEq
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
