#ifndef LISTA_USUARIOS_H
#define LISTA_USURIOS_H

#include <list>
#include <string>
#include "../usuario/usuario.h"
#include <fstream>

class Lista_Usuarios {
    private:
        std::list<Usuario> lista_usuarios_;
    public:
        Usuario verUsuario(std::string id);
        bool addUsuario(Usuario usuario);
        bool modificarUsuario(std::string id, Usuario usuario);
        bool guardarUsuarios();
};


#endif