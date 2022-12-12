add_library(administrador_aplicacion administrador_aplicacion.cc)
target_link_libraries(administrador_aplicacion PUBLIC lista_usuarios lista_cursos)
target_include_directories(administrador_aplicacion PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
			               ${PROJECT_SOURCE_DIR}/src/lista_usuarios
                           ${PROJECT_SOURCE_DIR}/src/lista_cursos)

