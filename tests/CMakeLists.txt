add_executable(inputTest test_input.cpp)
add_executable(calculatorTest test_calculator.cpp)

target_link_libraries(inputTest gtest gtest_main
  ${CMAKE_THREAD_LIBS_INIT}
  ${GMPXX_LIBRARIES}
  ${GMP_LIBRARIES}
  input
)

target_link_libraries(calculatorTest gtest gtest_main
  ${CMAKE_THREAD_LIBS_INIT}
  ${GMPXX_LIBRARIES}
  ${GMP_LIBRARIES}
  utils
  input
  calculator
)

add_test(NAME input COMMAND inputTest)
add_test(NAME calculator COMMAND calculatorTest)
