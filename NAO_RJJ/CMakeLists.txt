##
# Copyright (c) 2011 Aldebaran Robotics. All Rights Reserved.

cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)
# Give a name to the project.
project(NAO_RJJ)
# This include enable you to use our CMake framework
find_package(qibuild)

set(_srcs
  move.cpp
  move.h
  main.cpp
  robot.h
  robot.cpp
  robotsmanager.h
  robotsmanager.cpp
  util.h
)

# Create an executable named move,
qi_create_bin(NAO_RJJ ${_srcs})

qi_use_lib(NAO_RJJ ALCOMMON ALMEMORYFASTACCESS)
