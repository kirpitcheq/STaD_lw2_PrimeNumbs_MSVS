add_library(PrimeNumbsKPEq PrimeNumbsKPEq.cpp PrimeNumbsKPEq.h)

project(PrimeNumbs)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC
    PrimeNumbsKPEq
    benchmark::benchmark
)