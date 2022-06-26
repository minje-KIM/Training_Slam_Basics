cmake_minimum_required( VERSION 2.8 )
project( Rotation )


#   Add a list of directories to find the header file included in each source file with the #include syntax.
#   INCLUDE_DIRECTORIES ( <Directory_1> <Directory_2> ... )
include_directories( "/usr/include/eigen3")

add_executable( mat_representation basic_representation.cpp )
add_executable( rot_representation rotation_representation.cpp )

