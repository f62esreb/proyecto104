add_library(inicio_sesion inicio_sesion.cc)
target_link_libraries(inicio_sesion PUBLIC lista_usuarios administrador_aplicacion administrador_recursos administrador_cursos)
target_include_directories(inicio_sesion PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
			               ${PROJECT_SOURCE_DIR}/src/lista_usuarios
                           ${PROJECT_SOURCE_DIR}/src/administrador_aplicacion
                           ${PROJECT_SOURCE_DIR}/src/administrador_recursos
                           ${PROJECT_SOURCE_DIR}/src/administrador_cursos)
