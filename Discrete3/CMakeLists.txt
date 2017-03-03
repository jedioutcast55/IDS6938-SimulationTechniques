cmake_minimum_required(VERSION 2.8.9)

project (Discrete3)


add_executable(Markov markov.cpp markov.h main.cpp)
set_target_properties(Markov PROPERTIES LINKER_LANGUAGE CXX)