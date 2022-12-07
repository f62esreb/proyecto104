#include "app.h"
#include <iostream>

int main() {
    std::string dni, pass;
    bool login_page = true;

    Lista_Cursos cursos = inicializarCursos();
    Lista_Usuarios usuarios = inicializarUsuarios();
    Inicio_Sesion login(usuarios);


    while ( true ) {
        while ( login.get_id_usuario() == "empty" ) {
            std::cout << "-- SISTEMA DE CURSOS DE EXTENSIÓN DE LA UNIVERSIDAD DE CÓRDOBA --" << std::endl;
            std::cout << "-- INICIO DE SESIÓN ---------------------------------------------" << std::endl;
            std::cout << "DNI/NIF> ";
            std::cin >> dni;
            std::cout << "Contraseña> ";
            std::cin >> pass;


            if (! login.iniciarSesion(dni, pass)) {
                std::cout << "Error: usuario o contrasena invalidos" << std::endl;
            }
        }

        if ( login.get_id_usuario() != "empty" ) {
            int option;

            std::cout << "Bienvenido, " << login.get_id_usuario() << std::endl;
            menuEstudiante();
            
            std::cout << "> ";
            std::cin >> option;

            std::string id;
            switch (option)
            {
            case 1:
                mostrarCursos(cursos);
                break;
            case 2:
                std::cout << "Introduce el ID del curso a continuación: ";
                std::cin >> id;
                
                mostrarCurso(cursos.verCurso(id));
                break;
            case 5:
                std::cout << "Cerrando sesion" << std::endl;
                login.cerrarSesion();
                break;
            
            default:
                break;
            }
        }
    }

}