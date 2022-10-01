cmake_minimum_required(VERSION 3.8)

project(greeter)

set(GREETER_SOURCES
        include/greeter/config.hpp
        include/greeter/greeter.hpp
        src/greeter.cpp
)

# note there is no static/shared
add_library(greeter_lib ${GREETER_SOURCES})

target_include_directories(greeter_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main greeter_lib)

if(BUILD_SHARED_LIBS)
  target_compile_definitions(greeter_lib PRIVATE GREETER_EXPORTS) 
  target_compile_definitions(greeter_lib INTERFACE GREETER_IMPORTS) 
endif()
