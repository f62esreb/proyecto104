#include "administrador_recursos.h"
#include <fstream>

bool Administrador_Recursos::cargarAdministrador() {
    std::ifstream input("admin_recursos.txt");

    if (!input.is_open()) {      
        std::ofstream input("admin_recursos.txt");
        std::cout << "Error: no se ha encontrado ningun usuario administrador de recursos, usando por defecto el inicio de sesión con usuario: admin_recursos y contraseña: admin_recursos. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
        input.close();
        return false;
    }

    else if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: no se ha encontrado ningun usuario administrador de recursos, usando por defecto el inicio de sesión con usuario: admin_recursos y contraseña: admin_recursos. Por favor se recomienda que este sea cambiado inmediatamente para evitar problemas de seguridad." << std::endl;
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

    bool Administrador_Recursos:: addRecurso(std::string id, Recurso R )
    {
        Curso &c = cursos_.verCurso(id);

        if(c.get_id() == "empty"){return false;}

        this->quitarRecurso_Sistema(R.get_id_recurso());

        this->guardarRecursos();

        return c.addRecurso(R);
    
    }
    bool Administrador_Recursos:: quitarRecurso(std::string id, std::string id_recurso)
    {
        Curso &c = cursos_.verCurso(id);

        if(c.get_id() == "empty"){return false;}

        Recurso R = c.quitarRecurso(id_recurso);

        if(R.get_id_recurso() == "empty"){return false;}
        this -> addRecurso_Sistema(R);
        this->guardarRecursos();
        return true;
    }

    bool Administrador_Recursos:: addRecurso_Sistema(Recurso R)
    {
        for ( Recurso c : recursos_ ) {
        if ( c.get_id_recurso() == R.get_id_recurso() ) { 
            return false;
        }
    }
    
        recursos_.push_back(R);
        this->guardarRecursos();
        return true;
    }

    bool Administrador_Recursos:: quitarRecurso_Sistema(std::string id)
    {
        for ( auto it = recursos_.begin(); it != recursos_.end(); it++ ) {
           
            if ( it->get_id_recurso() == id) { 

                it = recursos_.erase(it);
                this->guardarRecursos();
            
                return true;
        }
    }

        return false;
    }

bool Administrador_Recursos::cargarRecursos()
{
    std::ifstream input("recursos.txt");
    std::string numero;

    if (!input.is_open()) {
        std::ofstream input("recursos.txt");
		input.close();
        this->guardarRecursos();
		return false;
	}

    if (input.peek() == 0) {
		input.close();
        this->guardarRecursos();
        return false;
    }

    getline(input, numero);

	for (int i = 0; i < std::stoi(numero); i++) {

        std::string id;
        std::string tipo;
        std::string aux;
        Tipo t;

        getline(input, id);
        getline(input, tipo);
        getline(input, aux);

        if(stoi(tipo)==1)
        {
            Recurso R(id , Tipo::CAMARA);
            R.set_calidad_imagen(stoi(aux));
            recursos_.push_back(R);
        }
        else if(stoi(tipo)==2)
        {
            Recurso R(id , Tipo::PROYECTOR);
            R.set_brillo(stoi(aux));
            recursos_.push_back(R);
        }
        else if(stoi(tipo)==3)
        {
            Recurso R(id, Tipo::AULA);
            R.set_aforo(stoi(aux));
            recursos_.push_back(R);
        }
        else
        {
            std::cout<<"Error"<<std::endl;
            return false;
        }

	}


	input.close();

	return true;
}

bool Administrador_Recursos::guardarRecursos()
{
    std::ofstream input("recursos.txt");
    input << recursos_.size() << std::endl;


    for(Recurso R : recursos_)
    {
        
        input << R.get_id_recurso() << "\n";
        Tipo tipo = R.get_recurso();
        switch (tipo)
        {
        case Tipo:: CAMARA:
            input << 1 << std::endl;
            input << R.get_calidad_imagen()<< std::endl;
            break;
        case Tipo:: PROYECTOR:
            input << 2 << std::endl;
            input << R.get_brillo()<< std::endl;
            break;
        case Tipo:: AULA:
            input << 3 << std::endl;
            input << R.get_aforo() << std::endl;
        }
        
    }
    
    input.close();

    return true;
}