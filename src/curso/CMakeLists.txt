add_library(curso curso.cc)
target_include_directories(curso PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")

#add_executable(person_main person_main.cc)
#target_link_libraries(person_main person)
