add_library(inicio_sesion inicio_sesion.cc)
target_link_libraries(inicio_sesion PUBLIC lista_usuarios)
target_include_directories(inicio_sesion PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
			   ${PROJECT_SOURCE_DIR}/src/lista_usuarios)

#add_executable(person_main person_main.cc)
#target_link_libraries(person_main person)
