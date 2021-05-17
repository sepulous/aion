cmake_minimum_required(VERSION 3.20)

include("../config.cmake")

project(
  ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV_WX_CONFIG)
  set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED)

set(SRCS
    main.cpp
    main_window.cpp
)

include(${wxWidgets_USE_FILE})

if(APPLE)
  add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRCS})
else()
  # Works for both Windows and Linux
  add_executable(${PROJECT_NAME} WIN32 ${SRCS})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
