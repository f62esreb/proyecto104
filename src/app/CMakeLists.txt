add_library(app_func app.cc)
target_include_directories(app_func PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")

add_executable(main main.cc)
target_link_libraries(main app_func lista_cursos lista_usuarios inicio_sesion administrador_cursos administrador_recursos administrador_aplicacion)
