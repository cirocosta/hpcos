ADD_LIBRARY(calculator calculator.cpp)
ADD_LIBRARY(input input.cpp)

ADD_EXECUTABLE(main main.cpp)

ADD_SUBDIRECTORY(utils/)

TARGET_LINK_LIBRARIES(main
  ${CMAKE_THREAD_LIBS_INIT}
  ${GMP_LIBRARIES}
  ${GMPXX_LIBRARIES}
  utils
  calculator
  input
)
