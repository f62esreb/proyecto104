#include "app.h"
#include <iostream>

int main() {
    std::string dni, pass,id_usuario;
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
            Usuario usuario = usuarios.verUsuario(login.get_id_usuario());

            std::cout << "Bienvenido, " << usuario.get_name() << std::endl;
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
            case 3:
                std::cout<<"Introduzca el ID del curso: ";
                std::cin>> id;

                std::cout<<"Introduzca su ID: ";
                std::cin>>id_usuario;

                cursos.inscripcion(id, id_usuario);
                
                if(cursos.inscripcion(id,id_usuario)==true){
                    usuarios.inscripcionUsuario(id_usuario, id);
                }
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