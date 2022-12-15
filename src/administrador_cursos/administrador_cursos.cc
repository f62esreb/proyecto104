#include "administrador_cursos.h"
#include <fstream>

bool Administrador_Cursos::cargarAdministrador() {
    std::ifstream input("admin_cursos.txt");

    if (!input.is_open()) {      
        std::ofstream input("admin_cursos.txt");
        std::cout << "Error: no se ha encontrado ningun usuario administrador de cursos, usando por defecto el inicio de sesión con usuario: admin_cursos y contraseña: admin_cursos. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
        input.close();
        return false;
    }

    else if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: no se ha encontrado ningun usuario administrador de cursos, usando por defecto el inicio de sesión con usuario: admin_cursos y contraseña: admin_cursos. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
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


bool Administrador_Cursos::guardarAdministrador()
{
	std::ofstream input("admin_cursos.txt");

    input << this->get_id_usuario() << std::endl;
    input << this->get_name() << std::endl;
    input << this->get_password() << std::endl;
    input << this->get_correo() << std::endl;

	input.close();

    return true;
}
