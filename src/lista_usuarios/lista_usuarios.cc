#include "lista_usuarios.h"

Usuario Lista_Usuarios::verUsuario(std::string id)
{
    Usuario u("empty","empty","empty","empty");
    for ( Usuario c : lista_usuarios_ ) {
        if ( c.get_id_usuario() == id ) { 
            return c;
        }
    }
    return u;
}

bool Lista_Usuarios::addUsuario(Usuario usuario) {
    for ( Usuario c : lista_usuarios_ ) {
        if ( c.get_id_usuario() == usuario.get_id_usuario() ) { 
            return false;
        }
    }

    lista_usuarios_.push_back(usuario);
    return true;
}


bool Lista_Usuarios::modificarUsuario(std::string id, Usuario usuario) {
    for ( auto it = lista_usuarios_.begin(); it != lista_usuarios_.end(); it++ ) {
        if ( it->get_id_usuario() == id ) { 
            *it = usuario;
            return true;
        }
    }

    return false;
}