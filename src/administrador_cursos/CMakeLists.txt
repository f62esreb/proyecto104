add_library(administrador_cursos administrador_cursos.cc)
target_link_libraries(administrador_cursos PUBLIC lista_cursos)
target_include_directories(administrador_cursos PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
                           ${PROJECT_SOURCE_DIR}/src/lista_cursos)

