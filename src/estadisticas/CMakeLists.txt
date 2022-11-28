add_library(estadisticas estadisticas.cc)
target_include_directories(estadisticas PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")

#add_executable(person_main person_main.cc)
#target_link_libraries(person_main person)
