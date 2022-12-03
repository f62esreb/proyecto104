#ifndef INICIO_SESION
#define INICIO_SESION

#include <list>
#include "../lista_usuarios/lista_usuarios.h"
#include <string>
#include "../inicio_sesion/inicio_sesion.h"

class Inicio_Sesion {

    private:
        std::string id_usuario_;
        Lista_Usuarios & lista_usuarios_;
    public:

        Inicio_Sesion(Lista_Usuarios & lista_usuarios):lista_usuarios_(lista_usuarios){};
        bool iniciarSesion(std::string usuario, std::string password);
        void cerrarSesion();
        inline std::string get_id_usuario() {return id_usuario_;};

};



#endif