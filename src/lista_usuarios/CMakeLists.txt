add_library(lista_usuarios lista_usuarios.cc)
target_link_libraries(lista_usuarios PUBLIC usuario)
target_include_directories(lista_usuarios PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
			   ${PROJECT_SOURCE_DIR}/src/usuario)

#add_executable(person_main person_main.cc)
#target_link_libraries(person_main person)
