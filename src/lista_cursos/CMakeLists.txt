add_library(lista_cursos lista_cursos.cc)
target_link_libraries(lista_cursos PUBLIC curso)
target_include_directories(lista_cursos PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
			   ${PROJECT_SOURCE_DIR}/src/curso)

#add_executable(person_main person_main.cc)
#target_link_libraries(person_main person)
