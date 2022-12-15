#ifndef ADMININSTRADOR_APLICACION_H
#define ADMININSTRADOR_APLICACION_H

#pragma once
#include "../administrador_cursos/administrador_cursos.h"
#include "../administrador_recursos/administrador_recursos.h"
#include "../lista_usuarios/lista_usuarios.h"
#include "../lista_cursos/lista_cursos.h"
#include "../usuario/usuario.h"
#include <string>

class Administrador_Aplicacion: public Usuario {
    private:
        Lista_Cursos& cursos_;
        Lista_Usuarios& usuarios_;
    public:
        Administrador_Aplicacion(Lista_Cursos &cursos, Lista_Usuarios &usuarios): Usuario("admin", "admin", "admin", "admin"), cursos_(cursos), usuarios_(usuarios) {this->cargarAdministrador(); };
        bool cargarAdministrador();

        inline bool modificarUsuario(std::string id, Usuario nuevo_usuario){return usuarios_.modificarUsuario(id,nuevo_usuario);};
        inline bool borrarUsuario(std::string id){return usuarios_.deleteUsuario(id);};
        bool guardarAdministrador();
};

#endif