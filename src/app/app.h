#ifndef APP_H
#define APP_H

#include "../lista_cursos/lista_cursos.h"
#include "../lista_usuarios/lista_usuarios.h"
#include "../curso/curso.h"

Lista_Cursos inicializarCursos();
Lista_Usuarios inicializarUsuarios();
time_t crearFecha(std::string& fecha);

#endif