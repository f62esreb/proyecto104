#ifndef INICIO_SESION
#define INICIO_SESION

#include "../administrador_aplicacion/administrador_aplicacion.h"
#include "../administrador_recursos/administrador_recursos.h"
#include "../administrador_cursos/administrador_cursos.h"
#include "../lista_usuarios/lista_usuarios.h"
#include "../inicio_sesion/inicio_sesion.h"
#include <string>
#include <list>

class Inicio_Sesion: public Usuario {

    private:
        std::string tipo_admin_;
        Lista_Usuarios & lista_usuarios_;
        Administrador_Cursos& admin_cursos_;
        Administrador_Recursos& admin_recursos_;
        Administrador_Aplicacion& admin_aplicacion_;
    public:
        Inicio_Sesion(Lista_Usuarios & lista_usuarios, Administrador_Cursos& cursos, 
        Administrador_Recursos& recursos, Administrador_Aplicacion& aplicacion): 
        lista_usuarios_(lista_usuarios), admin_cursos_(cursos), admin_recursos_(recursos), admin_aplicacion_(aplicacion), Usuario("empty", "empty", "empty", "empty") {};
        bool iniciarSesion(std::string usuario, std::string password);
        void cerrarSesion();
        inline std::string get_tipo_admin() { return tipo_admin_; };
};



#endif