# Install script for directory: /home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/AdolcForward"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/AlignedVector3"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/ArpackSupport"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/AutoDiff"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/BVH"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/EulerAngles"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/FFT"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/IterativeSolvers"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/KroneckerProduct"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/LevenbergMarquardt"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/MatrixFunctions"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/MoreVectorization"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/MPRealSupport"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/NNLS"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/NonLinearOptimization"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/NumericalDiff"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/OpenGLSupport"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/Polynomials"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/Skyline"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/SparseExtra"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/SpecialFunctions"
    "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/Splines"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "/home/lili/Documents/ExternalInclude/Eigen/source_dir/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lili/Documents/ExternalInclude/Eigen/build_dir/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

