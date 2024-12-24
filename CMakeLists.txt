cmake_minimum_required(VERSION 3.0)

project(DesignPattern)

add_subdirectory(StateMachine)
add_subdirectory(Factory)

add_executable(DesignPattern main.cpp)

target_link_libraries(DesignPattern PUBLIC 
                                    Factory
                                    StateMachine)

