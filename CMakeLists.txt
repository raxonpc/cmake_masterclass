cmake_minimum_required(VERSION 3.8)

project(greeter)

option(GREETER_SHARED "Build greeter as shared_library" BUILD_SHARED_LIBS)
if(GREETER_SHARED)
        set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

include(FetchContent)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 9.1.0
)
FetchContent_MakeAvailable(fmt)

set(GREETER_SOURCES
        include/greeter/config.hpp
        include/greeter/greeter.hpp
        src/greeter.cpp
)

if(GREETER_SHARED)
        add_library(greeter_lib SHARED ${GREETER_SOURCES})
else()
        add_library(greeter_lib STATIC ${GREETER_SOURCES})
endif()
target_include_directories(greeter_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(greeter_lib fmt::fmt)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main greeter_lib)

if(GREETER_SHARED)
  target_compile_definitions(greeter_lib PRIVATE GREETER_EXPORTS) 
  target_compile_definitions(greeter_lib INTERFACE GREETER_IMPORTS) 
endif()

# INSTALLATION TARGET
install(TARGETS greeter_lib
	        RUNTIME DESTINATION bin 
	        ARCHIVE DESTINATION lib
	        LIBRARY DESTINATION lib
)

# copy public include files
install(FILES 
	include/greeter/config.hpp
	include/greeter/greeter.hpp
	DESTINATION include/greeter)
