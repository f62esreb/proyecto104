add_library(camaras camaras.cc)
target_link_libraries(camaras PUBLIC recurso)
target_include_directories(camaras PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}
                           ${PROJECT_SOURCE_DIR}/src/camaras)
