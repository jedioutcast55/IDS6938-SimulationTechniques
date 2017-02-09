
include_directories(
  # Eigen linear algebra library
  ${EIGEN_INCLUDE_DIR}  
  # GLM Specification
  ${GLM_INCLUDE_DIR}
  # GLAD library for accessing OpenGL functions
  ${GLAD_INCLUDE_DIR}
  # GLFW library for accessing OpenGL functions
  ${GLFW_INCLUDE_DIR}
  # NanoGUI user interface library
  ${NANOGUI_INCLUDE_DIR} 
  # NanoVG drawing library
  ${NANOVG_INCLUDE_DIR}
  #GLM
  ${GLM_INCLUDE_DIR}
  # Geometry library
  ${CMAKE_SOURCE_DIR}/geometry
  ${CMAKE_SOURCE_DIR}/simulationengine
  ${OBJLOADER_INCLUDE_DIR}   
)

  

# Actual FormFactors sources
set(VISUALIZERER_SRCS
  ShaderSourceCode.h
  helper.hpp
  theCamera.h theCamera.cpp
  gridlines.h gridlines.cpp
  AxisLines.h AxisLines.cpp
  Points.h Points.cpp
  FullScreenQuad.h FullScreenQuad.cpp
  mesh.h mesh.cpp  
  Visualizer.h Visualizer.cpp
)

#SET( RESOURCES    
#  QuadFragmentShader.frag
#  SimpleFragmentShader.frag
#)


add_definitions(-DNANOGUI_GLAD)
add_library (Visualizer ${LIB_TYPE} ${VISUALIZERER_SRCS} )


ADD_DEPENDENCIES(Visualizer glfw nanogui Geometry SimulationEngine)

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