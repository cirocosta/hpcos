ADD_LIBRARY(calculatorlib calculator.cpp)
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main 
    calculatorlib 
    ${CMAKE_THREAD_LIBS_INIT} 
    ${GMPXX_LIBRARIES} ${GMP_LIBRARIES} 
)
