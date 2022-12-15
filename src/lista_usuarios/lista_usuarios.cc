#include "lista_usuarios.h"

Usuario& Lista_Usuarios::verUsuario(std::string id)
{
    Usuario& u = empty;
    for ( Usuario& c : lista_usuarios_ ) {
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


bool Lista_Usuarios::modificarUsuario(std::string id, Usuario nuevo_usuario) {
    for ( auto it = lista_usuarios_.begin(); it != lista_usuarios_.end(); it++ ) {
        if ( it->get_id_usuario() == id ) { 
            *it = nuevo_usuario;
            return true;
        }
    }

    return false;
}


bool Lista_Usuarios :: guardarUsuarios()
{
    std::ofstream input("usuarios.txt");
    input << lista_usuarios_.size();

    for ( Usuario u : lista_usuarios_ ) 
    {
        input << u.get_id_usuario() << "\n";
        input <<u.get_name()<< "\n";
        input <<u.get_password()<< "\n";
        input <<u.get_correo()<< "\n";
        input <<"\n";

    }

    input.close();

    return true;
}

bool Lista_Usuarios::inscripcionUsuario(std::string id_usuario, std::string id){
    for (auto u = lista_usuarios_.begin(); u != lista_usuarios_.end(); u++){
        if(u->get_id_usuario()==id_usuario){
            if (u->inscribirseCurso(id) == true) {
                return true;
            }
            std::cout << "Error: el usuario ya esta inscrito en el curso" << std::endl;
            return false;
        }
    }

    this->guardarUsuarios();
    
    return false;
}

bool Lista_Usuarios::deleteUsuario(std::string id_usuario){

    for(auto it=lista_usuarios_.begin();it!=lista_usuarios_.end();it++){
        if(it->get_id_usuario()==id_usuario){
            it=lista_usuarios_.erase(it);
            return true;
        }
    }

    return false;
}