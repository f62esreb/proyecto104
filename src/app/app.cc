#include "app.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>


time_t crearFecha(std::string& fecha) { 
    std::vector<int> numeros_fecha;
    struct tm tm_fecha;

    std::stringstream ss(fecha);
    std::string numero;

    while (getline(ss, numero, '-')) {
        numeros_fecha.push_back(std::stoi(numero));
    }

    tm_fecha.tm_mday = numeros_fecha[0];
    tm_fecha.tm_mon = numeros_fecha[1] - 1;
    tm_fecha.tm_year = numeros_fecha[2] - 1900;
    tm_fecha.tm_hour = 0;
    tm_fecha.tm_min = 0;
    tm_fecha.tm_sec = 0;

    return mktime(&tm_fecha);
} 


Lista_Cursos inicializarCursos() { 
    Lista_Cursos L;

    std::ifstream input("cursos.txt");
    std::string numero;

    if (!input.is_open()) {
        std::ofstream input("cursos.txt");
        input.close();
        L.guardarCursos();
        return L;
    }

    if (input.peek() == 0) {
        input.close();
        L.guardarCursos();
        return L;
    }

    getline(input, numero);

    for (int i = 0; i < std::stoi(numero); i++) {
        struct tm timet_inicio;
        struct tm timet_fin;

        std::string id, nombre, descripcion;
        std::string fecha_inicio, fecha_fin;
        std::string correo_admin_curso, ponentes, requisitos;
        std::string participantes, max_participantes;
        std::string dummy;

        getline(input, id);
        getline(input, nombre);
        getline(input, descripcion);
        getline(input, fecha_inicio);
        getline(input, fecha_fin);
        getline(input, correo_admin_curso);
        getline(input, ponentes);
        getline(input, requisitos);
        getline(input, participantes);
        getline(input, max_participantes);
        getline(input, dummy);

        Curso c(id, nombre, descripcion, stoi(fecha_inicio), stoi(fecha_fin), correo_admin_curso, ponentes, requisitos, std::stoi(participantes), std::stoi(max_participantes));
        c.cargarListaParticipantes();
        L.addCurso(c);
    }

    input.close();

    return L;
}

Lista_Usuarios inicializarUsuarios()
{
    Lista_Usuarios L;

    std::ifstream input("usuarios.txt");
    std::string numero;

    if (!input.is_open()) {      
        std::ofstream input("usuarios.txt");
        input.close();
        L.guardarUsuarios();
        return L;
        }

    if (input.peek() == std::ifstream::traits_type::eof()) {
        input.close();
        L.guardarUsuarios();
        return L;
    }

    getline(input, numero);

    for (int i = 0; i < stoi(numero); i++) {
        std::string id_usuario, nombre, password, correo;
        std::string dummy;

        getline(input, id_usuario);
        getline(input, nombre);
        getline(input, password);
        getline(input, correo);
        getline(input, dummy);
    
        Usuario c(id_usuario, nombre, password, correo);
        c.cargarCursos();
        L.addUsuario(c);
    }
    
    input.close();

    return L;
}

void mostrarCurso(Curso c) {
    std::cout << "ID del curso: " << c.get_id() << std::endl;
    std::cout << "Nombre: " << c.get_nombre() << std::endl;
    std::cout << "Descripcion: " << c.get_descripcion() << std::endl;
    time_t time = c.get_fecha_inicio();
    std::cout << "Fecha inicio de curso: " << std::asctime(localtime(&time));
    time = c.get_fecha_fin();
    std::cout << "Fecha fin de curso: " << std::asctime(localtime(&time));
    std::cout << "Ponentes: " << c.get_ponentes() << std::endl;
    std::cout << "Participantes: " << c.get_participantes() << std::endl;
    std::cout << "Max participantes: " << c.get_max_participantes() << std::endl;
    std::cout << "Para mas informacion pongase en contacto con " << c.get_correo_admin_curso() << std::endl;
}

void mostrarCursos(Lista_Cursos cursos) {
    for (Curso c: cursos.verCursos()) {
        std::cout << "ID del curso: " << c.get_id() << std::endl;
        std::cout << "Nombre: " << c.get_nombre() << std::endl;
        std::cout << "Descripcion: " << c.get_descripcion() << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
}

void menuEstudiante() {
    std::cout << "1. Ver los cursos disponibles" << std::endl;
    std::cout << "2. Ver un curso en especifico" << std::endl;
    std::cout << "3. Inscribirse en el curso" << std::endl;
    std::cout << "4. Ver mi perfil" << std::endl;
    std::cout << "5. Cerrar sesion" << std::endl;
}

void menuPrincipal() {
    std::cout << "1. Ver cursos disponibles" << std::endl;
    std::cout << "2. Iniciar sesion" << std::endl;
}

