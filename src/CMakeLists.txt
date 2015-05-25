ADD_LIBRARY(calculator calculator.cpp)
ADD_LIBRARY(input input.cpp)

ADD_EXECUTABLE(main main.cpp)

ADD_SUBDIRECTORY(utils/)

TARGET_LINK_LIBRARIES(main
  ${CMAKE_THREAD_LIBS_INIT}
  ${GMPXX_LIBRARIES}
  ${GMP_LIBRARIES}
  utils
  calculator
  input
)
