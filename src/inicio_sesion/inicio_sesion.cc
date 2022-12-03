#include "inicio_sesion.h"


bool Inicio_Sesion::iniciarSesion(std::string usuario, std::string password)
{
    Usuario c = lista_usuarios_.verUsuario(usuario);

    std::string userpw = c.get_password();

    if (userpw!= password)
    {
        return false;
    }
    else
    {
        id_usuario_ = usuario;
        return true;
    }

}

void Inicio_Sesion::cerrarSesion()
{
    id_usuario_ = "empty";
}