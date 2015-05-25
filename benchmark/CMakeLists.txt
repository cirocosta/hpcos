ADD_EXECUTABLE(benchmark benchmark.cpp)

TARGET_LINK_LIBRARIES(benchmark
  ${CMAKE_THREAD_LIBS_INIT}
  ${GMPXX_LIBRARIES}
  ${GMP_LIBRARIES}
  utils
  input
  calculator
)
