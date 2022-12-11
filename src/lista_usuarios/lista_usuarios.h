#ifndef LISTA_USUARIOS_H
#define LISTA_USURIOS_H

#include <list>
#include <string>
#include "../usuario/usuario.h"
#include <fstream>

class Lista_Usuarios {
    private:
        Usuario empty;
        std::list<Usuario> lista_usuarios_;
    public:
        Lista_Usuarios(): empty("empty", "empty", "empty", "empty") {};
        Usuario& verUsuario(std::string id);
        bool addUsuario(Usuario usuario);
        bool modificarUsuario(std::string id, Usuario usuario);
        bool guardarUsuarios();
        bool inscripcionUsuario(std::string id_usuario, std::string id);
};


#endif