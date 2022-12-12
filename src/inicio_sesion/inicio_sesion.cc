#include "inicio_sesion.h"


bool Inicio_Sesion::iniciarSesion(std::string usuario, std::string password)
{
    Usuario c = lista_usuarios_.verUsuario(usuario);

    if (c.get_name() == "empty") {
        if (admin_aplicacion_.get_id_usuario() == usuario) {
            if (admin_aplicacion_.get_password() == password) {
                this->set_id_usuario(admin_aplicacion_.get_id_usuario());
                this->set_password(admin_aplicacion_.get_password());
                this->set_name(admin_aplicacion_.get_name());
                this->set_correo(admin_aplicacion_.get_correo());

                tipo_admin_ = "aplicacion";
                return true;
            }
        }

        if (admin_cursos_.get_id_usuario() == usuario) {
            if (admin_cursos_.get_password() == password) {
                this->set_id_usuario(admin_cursos_.get_id_usuario());
                this->set_password(admin_cursos_.get_password());
                this->set_name(admin_cursos_.get_name());
                this->set_correo(admin_cursos_.get_correo());
                
                tipo_admin_ = "cursos";
                return true;
            }
        }

        if (admin_recursos_.get_id_usuario() == usuario) {
            if (admin_recursos_.get_password() == password) {
                this->set_id_usuario(admin_recursos_.get_id_usuario());
                this->set_password(admin_recursos_.get_password());
                this->set_name(admin_recursos_.get_name());
                this->set_correo(admin_recursos_.get_correo());

                tipo_admin_ = "recursos";
                return true;
            }
        }
    }

    std::string userpw = c.get_password();

    if (userpw!= password)
    {
        return false;
    }
    else
    {
        this->set_id_usuario(usuario);
        this->set_password(password);
        this->set_name(c.get_name());
        this->set_correo(c.get_correo());
        tipo_admin_ = "none";
        return true;
    }

}

void Inicio_Sesion::cerrarSesion()
{
    this->set_id_usuario("empty");
    tipo_admin_ = "none";

}