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
        numeros_fecha.push_back(stoi(numero));
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

    while (!input.eof()) {
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

        Curso c(id, nombre, descripcion, crearFecha(fecha_inicio), crearFecha(fecha_fin), correo_admin_curso, ponentes, requisitos, stoi(participantes), stoi(max_participantes));
        L.addCurso(c);
    }

    return L;
}

void menu_estudiante() {
    std::cout << "1. Ver los cursos disponibles" << std::endl;
    std::cout << "2. Ver un curso en especifico" << std::endl;
    std::cout << "3. Inscribirse en el curso" << std::endl;
    std::cout << "4. Ver mis cursos" << std::endl;
    std::cout << "5. Cerrar sesion" << std::endl;
}

