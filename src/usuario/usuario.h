#ifndef USUARIO_H
#define USUARIO_H


#include<string>
#include<list>
#include<fstream>
#include<iostream>

class Usuario{
	private:
		std::string id_usuario_,nombre_,password_,correo_;
		std::list<std::string>  lista_cursos_;
	public:
		Usuario(std::string id_usuario, std::string nombre, std::string password, std::string correo);

		inline std::string get_id_usuario(){return id_usuario_;};
		inline void set_id_usuario(std::string id_usuario){id_usuario_=id_usuario;};

		inline std::string get_name(){return nombre_;};
		inline void set_name(std::string nombre){nombre_=nombre;};

		inline std::string get_password(){return password_;};
		inline void set_password(std::string password){password_=password;};

		inline std::string get_correo(){return correo_;};
		inline void set_correo(std::string correo){correo_=correo;};

		inline std::list<std::string> get_cursos() { return lista_cursos_; };

		bool inscribirseCurso(std::string id);

		bool cargarCursos();
		bool guardarCursos();
};



#endif 
