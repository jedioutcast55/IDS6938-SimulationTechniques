cmake_minimum_required(VERSION 2.8.9)

project (MotionTester)



# Output paths
##############################################################
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")


# Variables
##############################################################
set(NANOGUI_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/nanogui/include)
set(EIGEN_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen)
set(GLM_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/glm)   
set(GLAD_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/nanogui/ext/glad/include)
set(GLFW_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/nanogui/ext/glfw/include)
set(NANOVG_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/nanogui/ext/nanovg/src)
set(OBJLOADER_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/tinyobjloader)  
  

SET (LIB_TYPE STATIC)


add_subdirectory(external)
add_subdirectory(Geometry)
add_subdirectory(simulationengine)
add_subdirectory(Visualizer)


# Simulation Framework
##############################################################
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)
add_definitions(-DNANOGUI_GLAD)
include_directories( 
   ${GLAD_INCLUDE_DIR}  
   ${EIGEN_INCLUDE_DIR} 
   ${GLFW_INCLUDE_DIR} 
   ${NANOVG_INCLUDE_DIR} 
   ${NANOGUI_INCLUDE_DIR} 
   ${GLM_INCLUDE_DIR}
   ${OBJLOADER_INCLUDE_DIR} 
   ${CMAKE_SOURCE_DIR}/geometry 
   ${CMAKE_SOURCE_DIR}/visualizer
   ${CMAKE_SOURCE_DIR}/simulationengine
   ${CMAKE_SOURCE_DIR}/external/nanogui/
)
add_executable(tester main.cpp helper.hpp)
target_link_libraries(tester glfw nanogui Visualizer Geometry opengl32 SimulationEngine Utilities)
ADD_DEPENDENCIES(tester glfw nanogui Visualizer Geometry Utilities SimulationEngine)


# Sanitize build environment for static build with C++11
if (MSVC)
  # Disable annoying secure CRT warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS")

  # We'll select the TBB library ourselves
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D__TBB_NO_IMPLICIT_LINKAGE")

  # Parallel build on MSVC (all targets)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

  if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")

    # Disable Eigen vectorization for Windows 32 bit builds (issues with unaligned access segfaults)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DEIGEN_DONT_ALIGN")
  endif()

  # Static build
  set(CompilerFlags
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()
elseif(APPLE)
  # Try to auto-detect a suitable SDK
  execute_process(COMMAND bash -c "xcodebuild -version -sdk | grep MacOSX | grep Path | head -n 1 | cut -f 2 -d ' '" OUTPUT_VARIABLE CMAKE_OSX_SYSROOT)
  string(REGEX REPLACE "(\r?\n)+$" "" CMAKE_OSX_SYSROOT "${CMAKE_OSX_SYSROOT}")
  string(REGEX REPLACE "^.*X([0-9.]*).sdk$" "\\1" CMAKE_OSX_DEPLOYMENT_TARGET "${CMAKE_OSX_SYSROOT}")
endif()