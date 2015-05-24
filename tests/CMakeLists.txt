add_executable(inputTest test_input.cpp)
add_executable(calculatorTest test_calculator.cpp)

target_link_libraries(inputTest
  ${GMPXX_LIBRARIES}
  ${GMP_LIBRARIES}
  gtest
  gtest_main
  input
)

target_link_libraries(calculatorTest
  gtest
  gtest_main
)

add_test(NAME calculator COMMAND calculatorTest)
add_test(NAME input COMMAND inputTest)
