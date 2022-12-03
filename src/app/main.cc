#include "app.h"
#include <iostream>

int main() {
    std::string dni, pass;
    Lista_Cursos cursos = inicializarCursos();

    std::cout << "-- SISTEMA DE CURSOS DE EXTENSIÓN DE LA UNIVERSIDAD DE CÓRDOBA --";
    std::cout << "-- INICIO DE SESIÓN ---------------------------------------------";
    std::cout << "DNI/NIF> ";
    std::cin >> dni;
    std::cout << "Contraseña> ";
    std::cin >> pass;

    

}