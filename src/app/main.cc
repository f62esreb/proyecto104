#include "app.h"
#include <iostream>

int main() {
    int option;
    std::string dni, pass;
    bool login_page = true;

    Lista_Cursos cursos = inicializarCursos();
    Lista_Usuarios usuarios = inicializarUsuarios();

    Administrador_Cursos admin_cursos(cursos);
    Administrador_Recursos admin_recursos(cursos);
    Administrador_Aplicacion admin_app(cursos, usuarios);

    Inicio_Sesion login(usuarios, admin_cursos, admin_recursos, admin_app);

    
    while ( true ) {
        while ( login.get_id_usuario() == "empty" ) {
            menuPrincipal();
            std::cout << "Introduce una opcion" << std::endl;
            std::cin >> option;

            switch (option) {
                case 1:
                    std::cout << "Los cursos actualmente disponibles son:" << std::endl;
                    std::cout << "-----------------------------------------------------------" << std::endl;
                    mostrarCursos(cursos);
                    std::cout << "Es necesario iniciar sesion para interactuar con los cursos" << std::endl;
                    std::cout << "-----------------------------------------------------------" << std::endl;
                    break;
                case 2:
                        std::cout << "-- SISTEMA DE CURSOS DE EXTENSIÓN DE LA UNIVERSIDAD DE CÓRDOBA --" << std::endl;
                        std::cout << "-- INICIO DE SESIÓN ---------------------------------------------" << std::endl;
                        std::cout << "DNI/NIF> ";
                        std::cin >> dni;
                        std::cout << "Contraseña> ";
                        std::cin >> pass;


                        if (! login.iniciarSesion(dni, pass)) {
                            std::cout << "Error: usuario o contrasena invalidos" << std::endl;
                        }
                    break;
            }
        }

        if ( login.get_tipo_admin() != "none" ) {
            std::cout << "Bienvenido administrador cualquiera" << std::endl;
            cursos.guardarCursos();
            login.cerrarSesion();
        } else if ( login.get_id_usuario() != "empty" ) {
            Usuario& usuario = usuarios.verUsuario(login.get_id_usuario());

            std::cout << "Bienvenido, " << usuario.get_name() << std::endl;
            menuEstudiante();
            
            std::cout << "> ";
            std::cin >> option;

            std::string id;
            switch (option)
            {
            case 1:
                std::cout << "-----------------------------------------------------------" << std::endl;
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

                if(cursos.inscripcion(id, login.get_id_usuario())==true){
                    if (usuarios.inscripcionUsuario(login.get_id_usuario(), id)) {
                        std::cout<<"La inscripcion se ha realizado con exito." << std::endl;
                    } else {
                        std::cout<<"Error, ya se encuentra inscrito a este curso" << std::endl;
                    }
                } else {
                    std::cout << "El curso al que intenta inscribirse no existe" << std::endl;
                }

                break;

            case 4:
                usuario = usuarios.verUsuario(login.get_id_usuario());

                std::cout << "Perfil para " << usuario.get_name() << std::endl;
                std::cout << "-- INFORMACION GENERAL ----" << std::endl;
                std::cout << "Correo electronico " << usuario.get_correo() << std::endl;
                std::cout << "Numero de identidad " << usuario.get_id_usuario() << std::endl;
                std::cout << "-- CURSOS DEL USUARIO -----" << std::endl;
                if ( usuario.get_cursos().size() == 0 ){
                    std::cout << "No se encuentra inscrito a ningun curso." << std::endl;
                    std::cout << "---------------------------" << std::endl;
                } else {
                    for ( std::string curso : usuario.get_cursos() ) {
                        std::cout << "ID del curso: " << curso << std::endl;
                        std::cout << "Nombre del curso: " << cursos.verCurso(curso).get_nombre() << std::endl;
                        std::cout << "-----------------------------" << std::endl;
                    }
                }

                break;

            case 5:
                std::cout << "Cerrando sesion" << std::endl;
                login.cerrarSesion();

                break;
            
            default:
                std::cout << "Error: opción invalida." << std::endl;

                break;
            }
        }
    }

}