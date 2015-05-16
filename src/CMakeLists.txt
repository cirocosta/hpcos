add_library(calculatorlib calculator.cpp)
add_executable(main main.cpp)
target_link_libraries(main calculatorlib)
