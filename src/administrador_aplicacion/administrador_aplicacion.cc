#include "administrador_aplicacion.h"
#include <iostream>
#include <fstream>

bool Administrador_Aplicacion::cargarAdministrador() {
    std::ifstream input("admin.txt");

    if (!input.is_open()) {      
        std::ofstream input("admin.txt");
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
    
        this->set_id_usuario(id_usuario);
        this->set_name(nombre);
        this->set_password(password);
        this->set_correo(correo);
    }

    input.close();

    return true;
}

bool Administrador_Aplicacion::guardarAdministrador()
{
	std::ofstream input("admin.txt");

    input << this->get_id_usuario() << std::endl;
    input << this->get_name() << std::endl;
    input << this->get_password() << std::endl;
    input << this->get_correo() << std::endl;

	input.close();

    return true;
}

