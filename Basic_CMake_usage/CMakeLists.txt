#   Using additional "Build" Folder to build, It is easy to manage the contents of the folder



#   Specifies the minimum version for running the CMake build script.
#   Usually located at the top of CMakeLists.txt
#   CMake below the version specified here will print out an error and exit if it tries to parse the build script.
cmake_minimum_required( VERSION 2.8 )


#   Set the Project Name
#   It is not recommended to include spaces.
project( HelloWorld )

#   Add the library that you want to create as the final result of the build.
#   Repeat this command is adding the libraries that you want to create.
#   ADD_LIBRARY (<Library_Name> <Source_File> <Source_File>... )
add_library( hellolibrary lib_1.cpp lib_2.cpp )

#   Create a final result of Build
#   Repeating this command makes additional execution files.
#   ADD_EXECUTABLE (<exec_file name> <source_file> <source_file>... )
add_executable( helloWorld Helloworld.cpp ) 


#   TARGET_LINK_LIBRARIES (<Target_Name> <Library>... )
target_link_libraries(helloWorld hellolibrary )













