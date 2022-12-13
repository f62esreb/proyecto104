add_library(aulas aulas.cc)
target_link_libraries(aulas PUBLIC recurso)
target_include_directories(aulas PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
                           ${PROJECT_SOURCE_DIR}/src/aulas)
