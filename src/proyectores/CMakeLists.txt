add_library(proyectores proyectores.cc)
target_link_libraries(proyectores PUBLIC recurso)
target_include_directories(proyectores PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
                           ${PROJECT_SOURCE_DIR}/src/proyectores)
