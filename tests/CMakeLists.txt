add_executable(runUnitTests test_calculator.cpp)

# linking gtest_main as we're not providing a
# main
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests calculatorlib)


add_test(NAME calculator COMMAND runUnitTests)
