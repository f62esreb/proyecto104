#ifndef ADMININSTRADOR_APLICACION_H
#define ADMININSTRADOR_APLICACION_H

#include "administrador_cursos.h"
#include "usuario.h"
#include <string>

class Admininstrador_Aplicacion: public Usuario, public Admininstrador_Cursos {
    public:
        Admininstrador_Aplicacion(Usuario usuario, Lista_Cursos &cursos): Usuario(usuario), Admininstrador_Cursos(usuario, cursos) {};
        bool modificarUsuario(Usuario usuario, Usuario nuevo_usuario);
};

#endif