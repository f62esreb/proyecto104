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
    admin_recursos.cargarRecursos();
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
                case 3:
                    return 0;
                    break;
                default:
                    std::cout << "Error: opcion invalida" << std::endl;
                    break;
            }
        }

        if ( login.get_tipo_admin() == "recursos" ) {
            std::cout << "Bienvenido administrador de recursos..." << std::endl;
            menuAdminRecursos();
            std::cin >> option;

            switch ( option ) {
                case 1:
                    mostrarCursos(cursos);
                    break;
                case 2:
                    mostrarRecursos(admin_recursos);
                    break;

                case 3:
                    mostrarRecursosCurso(admin_recursos, cursos);
                    break;

                case 4:
                    addRecursoSistema(admin_recursos);
                    break;
                
                case 5:
                    quitarRecursoSistema(admin_recursos);
                    break;
                
                case 6:
                    addRecursoCurso(admin_recursos, cursos);
                    break;

                case 7:
                    quitarRecursoCurso(admin_recursos);
                    break;

                case 8:
                    login.cerrarSesion();
                    break;

                default:
                    std::cout << "Error, introduce una opcion valida." << std::endl;
                    break;
            }

        } 

        else if ( login.get_tipo_admin()=="cursos" ) {
            std::cout << "Bienvenido administrador de cursos..." << std::endl;
            menuAdminCursos();
            std::cin >> option; 
            
            std::string id;

            switch(option){
                case 1:
                    mostrarCursos(cursos);
                    break;

                case 2:
                    std::cout << "Introduce el ID del curso a continuación: ";
                    std::cin >> id;
                    mostrarCurso(cursos.verCurso(id));
                    break;

                case 3:
                    addCursoSistema(admin_cursos);
                    break;
                
                case 4:
                    modificarCursoSistema(admin_cursos);
                    break;

                case 5:
                    login.cerrarSesion();
                    break;

                default:
                    std::cout<<"Error, introduce una opcion valida."<<std::endl;
                    break;
            }

        }

        else if(login.get_tipo_admin()=="aplicacion"){
            std::cout<<"Bienvenido administrador de la aplicacion..."<<std::endl;
            menuAdminApp();
            std::cin>>option;
            
            std::string id;

            switch(option){
                case 1:
                    mostrarUsuarios(usuarios);
                    break;
                
                case 2:
                    std::cout<<"Introduce el ID del usuario: ";
                    std::cin>>id;
                    mostrarUsuario(usuarios.verUsuario(id));
                    break;
                
                case 3:
                    hacerAdmin(admin_app, admin_recursos, admin_cursos, usuarios);
                    break;
                
                case 4:
                    std::cout<<"Introduce los datos del usuario a continuacion"<<std::endl;
                    addUsuarioSistema(usuarios);
                    break;
                
                case 5:
                    std::cout<<"Inserte el ID del usuario que desea quitar: ";
                    std::cin>>id;

                    eliminarUsuario(admin_app, id);
                    break;
                
                case 6:
                    modificarUsuario(admin_app);
                    break;
                
                case 7:
                    mostrarCursos(cursos);
                    break;

                case 8:
                    std::cout << "Introduce el ID del curso a continuación: ";
                    std::cin >> id;
                    mostrarCurso(cursos.verCurso(id));
                    break;

                case 9:
                    addCursoSistema(admin_cursos);
                    break;

                case 10:
                    quitarCurso(cursos);
                    break;

                case 11:
                    modificarCursoSistema(admin_cursos);
                    break;

                case 12:
                    login.cerrarSesion();
                    break;

                default:
                    std::cout<<"Error, introduce una opcion valida."<<std::endl;
                    break; 
            }
        }

        else if ( login.get_id_usuario() != "empty" ) {
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