###
### List of solution .cpp files
###
SET(solution_srcs problems/problem_1.cpp)

###
### List of shared library items
###
set(lib_srcs utils.cpp)

###
### List of frameork .cpp files for the shell
###
set(framework_srcs projecteuler.cpp registry.cpp)

###########################################################################
###  Project outputs: binaries and static libs                          ###
###########################################################################
# The library of shared code
add_library(shared STATIC ${lib_srcs})

# Command line shell
add_executable(euler ${solution_srcs} ${framework_srcs})
target_link_libraries(euler shared)
