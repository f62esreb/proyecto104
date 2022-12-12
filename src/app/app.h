#ifndef APP_H
#define APP_H

#include "../administrador_aplicacion/administrador_aplicacion.h"
#include "../administrador_recursos/administrador_recursos.h"
#include "../administrador_cursos/administrador_cursos.h"
#include "../lista_cursos/lista_cursos.h"
#include "../lista_usuarios/lista_usuarios.h"
#include "../inicio_sesion/inicio_sesion.h"
#include "../curso/curso.h"

Lista_Cursos inicializarCursos();
Lista_Usuarios inicializarUsuarios();
time_t crearFecha(std::string& fecha);
void menuEstudiante();
void menuPrincipal();
void mostrarCursos(Lista_Cursos cursos);
void mostrarCurso(Curso c);

#endif