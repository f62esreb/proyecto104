#include "administrador_aplicacion.h"
#include <iostream>
#include <fstream>

bool Administrador_Aplicacion::cargarAdministrador() {
    std::ifstream input("admin_cursos.txt");

    if (!input.is_open()) {      
        std::ofstream input("admin_cursos.txt");
        std::cout << "Error: no se ha encontrado ningun usuario administrador de la aplicacion, usando por defecto el inicio de sesión con usuario: admin y contraseña: admin. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
        input.close();
        return false;
    }

    else if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: no se ha encontrado ningun usuario administrador de la aplicacion, usando por defecto el inicio de sesión con usuario: admin y contraseña: admin. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
        input.close();
        return false;
    }

    else {
        std::string id_usuario, nombre, password, correo;

        getline(input, id_usuario);
        getline(input, nombre);
        getline(input, password);
        getline(input, correo);
    
        Usuario(id_usuario, nombre, password, correo);
    }

    input.close();

    return true;
}

bool Administrador_Aplicacion::hacerAdministrador(Usuario usuario) {
    this->set_id_usuario(usuario.get_id_usuario());
    this->set_password(usuario.get_password());
    this->set_name(usuario.get_name());
    this->set_correo(usuario.get_correo());

    return true;
}