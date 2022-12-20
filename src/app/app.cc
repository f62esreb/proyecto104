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
        std::string precio;

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
        getline(input, precio);
        getline(input, dummy);

        Curso c(id, nombre, descripcion, stoi(fecha_inicio), stoi(fecha_fin), correo_admin_curso, ponentes, requisitos, std::stoi(participantes), std::stoi(max_participantes), std::stof(precio));
        c.cargarListaParticipantes();
        c.cargarListaRecursos();
        L.loadCurso(c);
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
        L.loadUsuario(c);
    }
    
    input.close();

    return L;
}

void mostrarCurso(Curso c) {
    if (c.get_id() != "none") {
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
        std::cout << "Precio: " << c.get_precio() << "€" << std::endl;
        std::cout << "Para mas informacion pongase en contacto con " << c.get_correo_admin_curso() << std::endl;
    } else {
        std::cout << "Error: no existe el curso." << std::endl;
    }

}

void mostrarCursos(Lista_Cursos cursos) {
    for (Curso c: cursos.verCursos()) {
        std::cout << "ID del curso: " << c.get_id() << std::endl;
        std::cout << "Nombre: " << c.get_nombre() << std::endl;
        std::cout << "Descripcion: " << c.get_descripcion() << std::endl;
        std::cout << "Precio: " << c.get_precio() << "€" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
}

void mostrarUsuarios(Lista_Usuarios usuarios) {
    for (Usuario u: usuarios.verUsuarios()) {
        std::cout << "ID del usuario: " << u.get_id_usuario() << std::endl;
        std::cout << "Nombre: " << u.get_name() << std::endl;
        std::cout << "Contraseña: " << u.get_password() << std::endl;
        std::cout << "Correo: "<< u.get_correo() << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
}

void menuEstudiante() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "1. Ver los cursos disponibles" << std::endl;
    std::cout << "2. Ver un curso en especifico" << std::endl;
    std::cout << "3. Inscribirse en el curso" << std::endl;
    std::cout << "4. Ver mi perfil" << std::endl;
    std::cout << "5. Cerrar sesion" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void menuPrincipal() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "1. Ver cursos disponibles" << std::endl;
    std::cout << "2. Iniciar sesion" << std::endl;
    std::cout << "3. Cerrar aplicacion" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void menuAdminRecursos() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "1. Ver cursos disponibles" << std::endl;
    std::cout << "2. Ver recursos disponibles" << std::endl;
    std::cout << "3. Ver recursos asignados a un curso" << std::endl;
    std::cout << "4. Añadir recurso al sistema" << std::endl;
    std::cout << "5. Quitar recurso del sistema" << std::endl;
    std::cout << "6. Asignar recurso a un curso" << std::endl;
    std::cout << "7. Quitar recurso a un curso" << std::endl;
    std::cout << "8. Cerrar sesion" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void menuAdminCursos(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "1. Ver cursos disponibles" << std::endl;
    std::cout << "2. Ver un curso especifico" << std::endl;
    std::cout << "3. Añadir curso" << std::endl;
    std::cout << "4. Modificar curso" << std::endl;
    std::cout << "5. Cerrar sesion" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void menuAdminApp(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout<<"1. Ver Usuarios."<<std::endl;
    std::cout<<"2. Ver Usuario."<<std::endl;
    std::cout<<"3. Hacer Administrador."<<std::endl;
    std::cout<<"4. Añadir Usuario."<<std::endl;
    std::cout<<"5. Quitar Usuario."<<std::endl;
    std::cout<<"6. Modificar Usuario."<<std::endl;
    std::cout<<"7. Ver Cursos."<<std::endl;
    std::cout<<"8. Ver Curso."<<std::endl;
    std::cout<<"9. Añadir Curso."<<std::endl;
    std::cout<<"10. Quitar Curso."<<std::endl;
    std::cout<<"11. Modificar Curso."<<std::endl;
    std::cout<<"12. Cerrar sesion."<<std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void mostrarRecursos(Administrador_Recursos admin_recursos) {
    int inc, atributo;
    std::string tipo_recurso;

    if (admin_recursos.verRecursosDisponibles().size() < 1) {
        std::cout << "Error: no hay recursos en el sistema." << std::endl;
    } else {
        std::cout << "Los recursos disponibles en el sistema son:" << std::endl;
        inc = 0;
        for ( Recurso R : admin_recursos.verRecursosDisponibles() ){
            if (R.get_recurso() == Tipo::CAMARA) {
                tipo_recurso = "Camara con calidad de ";
                atributo = R.get_calidad_imagen();
            } else if (R.get_recurso() == Tipo::PROYECTOR) {
                tipo_recurso = "Proyector con brillo de ";
                atributo = R.get_brillo();
            } else if (R.get_recurso() == Tipo::AULA) {
                tipo_recurso = "Aula con aforo de ";
                atributo = R.get_aforo();
            }

            inc++;
            std::cout << inc <<". " << R.get_id_recurso() <<  " -- (" << tipo_recurso << atributo << ")" << std::endl;
        }
    }
}

void mostrarRecursosCurso(Administrador_Recursos admin_recursos, Lista_Cursos cursos) {
    std::string id;

    std::cout << "Introduce el ID de un curso: ";
    std::cin >> id;

    Curso c = cursos.verCurso(id);

    if (c.get_id() == "none") {
        std::cout << "Error: El curso no existe." << std::endl;
    } else {
        int inc, atributo;
        std::string tipo_recurso;

        if (c.verRecursos().size() < 1) {
            std::cout << "Error: El curso no tiene recursos asignados" << std::endl;
        }

        std::cout << "Los recursos disponibles en el curso seleccionado son: " << std::endl;
        inc = 0;

        for ( Recurso R : c.verRecursos() ) {
            if (R.get_recurso() == Tipo::CAMARA) {
                tipo_recurso = "Camara con calidad de ";
                atributo = R.get_calidad_imagen();
            } else if (R.get_recurso() == Tipo::PROYECTOR) {
                tipo_recurso = "Proyector con brillo de ";
                atributo = R.get_brillo();
            } else if (R.get_recurso() == Tipo::AULA) {
                tipo_recurso = "Aula con aforo de ";
                atributo = R.get_aforo();
            }

            inc++;
            std::cout << inc <<". " << R.get_id_recurso() <<  " -- (" << tipo_recurso << atributo << ")" << std::endl;
        }
    }


}

void addRecursoSistema(Administrador_Recursos& admin_recursos) {
    std::string id;
    Tipo t;
    int atributo, tipo_n;

    std::cout << "Introduce el ID del recurso: ";
    std::cin >> id;

    std::cout << "Seleccione el tipo del recurso: " << std::endl;
    std::cout << "1. Camara" << std::endl;
    std::cout << "2. Proyector" << std::endl;
    std::cout << "3. Aula" << std::endl;
    std::cout << "> ";
    std::cin >> tipo_n;

    if (tipo_n == 1) {
        t = Tipo::CAMARA;
        std::cout << "Introduce la calidad de la camara (en megapixels)> ";
        std::cin >> atributo; 
        Recurso R(id, t, atributo);
        if(admin_recursos.addRecurso_Sistema(R)) {
            std::cout << "Recurso añadido correctamente" << std::endl;
        } else {
            std::cout << "Error: ya existe un recurso con el mismo identificador." << std::endl;
        }
    } else if (tipo_n == 2) {
        t = Tipo::PROYECTOR;
        std::cout << "Introduce el brillo del proyector (en candelas)> ";
        std::cin >> atributo; 
        Recurso R(id, t, 0, atributo);
        if(admin_recursos.addRecurso_Sistema(R)) {
            std::cout << "Recurso añadido correctamente" << std::endl;
        } else {
            std::cout << "Error: ya existe un recurso con el mismo identificador." << std::endl;
        }   
    } else if (tipo_n == 3) {
        t = Tipo::AULA;
        std::cout << "Introduce el aforo maximo del aula> ";
        std::cin >> atributo;  
        Recurso R(id, t, 0, 0, atributo);
        if(admin_recursos.addRecurso_Sistema(R)) {
            std::cout << "Recurso añadido correctamente" << std::endl;
        } else {
            std::cout << "Error: ya existe un recurso con el mismo identificador." << std::endl;
        }
    } else {
        std::cout << "Error añadiendo recurso: numero invalido" << std::endl;
    }
}

void quitarRecursoSistema(Administrador_Recursos& admin_recursos) {
    std::string id;
    
    std::cout << "Introduce el id de un recurso: ";
    std::cin >> id;

    if (admin_recursos.quitarRecurso_Sistema(id)) {
        std::cout << "El recurso se ha quitado de manera correcta." << std::endl;
    } else {
        std::cout << "Error: este recurso no existe." << std::endl;
    }
}

bool addRecursoCurso(Administrador_Recursos& admin_recursos, Lista_Cursos& cursos) {
    std::string id_curso;
    std::string id_recurso;

    std::cout << "Introduce el ID del curso:";
    std::cin >> id_curso;

    std::cout << "Introduce el ID del recurso:";
    std::cin >> id_recurso;

    for (Recurso R : admin_recursos.verRecursosDisponibles()) {
        if ( R.get_id_recurso() == id_recurso) {
            if (admin_recursos.addRecurso(id_curso, R)) {
                std::cout << "Recurso añadido al curso correctamente" << std::endl;
                return true;
            }
            break;
        }
    }

    std::cout << "Error: el curso o recurso no existe." << std::endl;
    return false;
}

void quitarRecursoCurso(Administrador_Recursos& admin_recursos) {
    std::string id_curso;
    std::string id_recurso;

    std::cout << "Introduce el ID del curso:";
    std::cin >> id_curso;

    std::cout << "Introduce el ID del recurso:";
    std::cin >> id_recurso;

    if(admin_recursos.quitarRecurso(id_curso, id_recurso)){
        std::cout << "Recurso quitado correctamente" << std::endl;
    } else {
        std::cout << "Error: el recurso o curso no existe." << std::endl;
    }
}

 Curso insertarDatosCurso(){
    std::string id, nombre, descripcion, correo_admin_curso, ponentes, requisitos, fechainicio, fechafin;
    int max_participantes;
    float precio;
    time_t fecha_inicio, fecha_fin;
    std::cin.get();

    std::cout<<"Introduce el ID del curso: ";
    getline(std::cin, id);

    std::cout<<"Introduce el nombre del curso: ";
    getline(std::cin, nombre);    

    std::cout<<"Introduce una descripción para el curso: ";
    getline(std::cin, descripcion);

    std::cout<<"Introduce el correo del administrador del curso: ";
    getline(std::cin, correo_admin_curso);

    std::cout<<"Introduce el nombre de los ponentes del curso (separados por comas): ";
    getline(std::cin, ponentes);

    std::cout<<"Introduce los requisitos necesarios: ";
    getline(std::cin, requisitos);

    std::cout<<"Introduce la fecha de inicio con formato DD-MM-AAAA: ";
    getline(std::cin, fechainicio);
    fecha_inicio=crearFecha(fechainicio);

    std::cout<<"Introduce la fecha de finalizacion con formato DD-MM-AAAA: ";
    getline(std::cin, fechafin);
    fecha_fin=crearFecha(fechafin);

    std::cout<<"Introduce el aforo del curso: ";
    std::cin >> max_participantes;

    std::cout<<"Introduce el precio del curso: ";
    std::cin>>precio;
    std::cin.get();

    Curso c(id,nombre,descripcion, fecha_inicio, fecha_fin, correo_admin_curso, ponentes, requisitos, 0, max_participantes, precio);

    return c;

}

void addCursoSistema(Administrador_Cursos& admin_cursos){
    Curso C=insertarDatosCurso();

    if (admin_cursos.addCurso(C)) {
        std::cout << "Curso añadido correctamente" << std::endl;
    } else {
        std::cout << "Error: El curso que intenta añadir ya existe." << std::endl;
    }

}

void modificarCursoSistema(Administrador_Cursos& admin_cursos){
    std::string id_curso_viejo;

    std::cout<<"Introduzca el ID del curso que desea modificar: ";
    std::cin>>id_curso_viejo;

    std::cout<<"A continuacion, introduzca los nuevos datos para el curso que desea modificar."<<std::endl;
    
    Curso C=insertarDatosCurso();

    if (admin_cursos.modificarCurso(C, id_curso_viejo)) {
        std::cout << "El curso se ha modificado correctamente." << std::endl;
    } else {
        std::cout << "Error: El curso que intenta modificar no existe" << std::endl;
    }


}

void mostrarUsuario(Usuario u) {
    if (u.get_id_usuario() == "empty") {
        std::cout << "Error: el usuario no existe." << std::endl;
    } else {
        std::cout << "ID del usuario: " << u.get_id_usuario() << std::endl;
        std::cout << "Nombre: " << u.get_name() << std::endl;
        std::cout << "Contraseña: " << u.get_password() << std::endl;
        std::cout << "Correo: "<< u.get_correo() << std::endl;
    }
}


void hacerAdmin(Administrador_Aplicacion& admin_app, Administrador_Recursos& admin_recursos, Administrador_Cursos& admin_cursos, Lista_Usuarios& usuarios){
    std::string user;
    int admin;

    std::cout << "1. Modificar el usuario del administrador de cursos." << std::endl;
    std::cout << "2. Modificar el usuario del administrador de recursos." << std::endl;
    std::cout << "3. Modificar el usuario del administrador de la aplicacion." << std::endl;
    std::cout << "> ";
    std::cin >> admin;

    std::cout << "Introduce el id del usuario> ";
    std::cin >> user;

    Usuario u = usuarios.verUsuario(user);

    if (u.get_id_usuario() == "empty") {
        std::cout << "Error: El ususario no existe." << std::endl;
    } else {
        switch (admin) {
        case 1:
            admin_cursos.set_id_usuario(u.get_id_usuario());
            admin_cursos.set_name(u.get_name());
            admin_cursos.set_password(u.get_password());
            admin_cursos.set_correo(u.get_correo());
            usuarios.deleteUsuario(u.get_id_usuario());
            std::cout << "Establecido el usuario " << u.get_id_usuario() << " como administrador de cursos" << std::endl;
            admin_cursos.guardarAdministrador();
            break;
        case 2:
            admin_recursos.set_id_usuario(u.get_id_usuario());
            admin_recursos.set_name(u.get_name());
            admin_recursos.set_password(u.get_password());
            admin_recursos.set_correo(u.get_correo());
            usuarios.deleteUsuario(u.get_id_usuario());
            std::cout << "Establecido el usuario " << u.get_id_usuario() << " como administrador de recursos" << std::endl;
            admin_recursos.guardarAdministrador();
            break;
        case 3:
            admin_app.set_id_usuario(u.get_id_usuario());
            admin_app.set_name(u.get_name());
            admin_app.set_password(u.get_password());
            admin_app.set_correo(u.get_correo());
            usuarios.deleteUsuario(u.get_id_usuario());
            std::cout << "Establecido el usuario " << u.get_id_usuario() << " como administrador de la aplicacion" << std::endl;
            admin_app.guardarAdministrador();
            break;
        default:
            std::cout << "Error, el numero introducido es invalido." << std::endl;
            break;
        }
    }
}

Usuario insertarDatosUsuario(){
    std::string id, nombre, password, correo;

    std::cin.get();
    std::cout<<"Introduce el ID del usuario: ";
    getline(std::cin, id);

    std::cout<<"Introduce el nombre del usuario: ";
    getline(std::cin, nombre);

    std::cout<<"Introduce la contraseña del usuario: ";
    getline(std::cin, password);

    std::cout<<"Introduce el correo del usuario: ";
    getline(std::cin, correo);

    Usuario u(id,nombre,password,correo);

    return u;

}

void addUsuarioSistema(Lista_Usuarios& usuarios){
    Usuario u=insertarDatosUsuario();
    if (usuarios.addUsuario(u)) {
        std::cout << "Usuario añadido correctamente" << std::endl;
    } else {
        std::cout << "Error: el usuario ya existe." <<std::endl;
    }

}

void eliminarUsuario(Administrador_Aplicacion& admin_app, std::string id){
    
    if (admin_app.borrarUsuario(id)) {
        std::cout << "Usuario borrado correctamente" << std::endl;
    } else {
        std::cout << "Error: el usuario no existe." << std::endl;
    }
}

void modificarUsuario(Administrador_Aplicacion& admin_app){
    std::string id_usuario_viejo;

    std::cout<<"Introduzca el ID del usuairo que desea modificar: ";
    std::cin>>id_usuario_viejo;

    std::cout<<"A continuacion, introduzca los nuevos datos del usuario"<<std::endl;
    Usuario nuevo=insertarDatosUsuario();

    if (admin_app.modificarUsuario(id_usuario_viejo,nuevo)) {
        std::cout << "Usuario modificado correctamente" << std::endl;
    } else {
        std::cout << "Error: el usuario no existe." << std::endl;
    }
}

void quitarCurso(Lista_Cursos& cursos){
    std::string id;
    
    std::cout<<"Inserte el ID del curso: ";
    std::cin>>id;

    if(cursos.quitarCurso(id)) {
        std::cout << "Curso quitado correctamente" << std::endl;
    } else {
        std::cout << "Error: el curso no existe" << std::endl;
    }
}
