/*
 * usuario.h
 *
 *  Created on: 25 nov 2022
 *      Author: belenmaria
 */

#ifndef USUARIO_H
#define USUARIO_H


#include<string>
#include<list>

class Usuario{
	private:
		std::string id_usuario_,nombre_,password_,correo_, id_curso_;
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

		inline std::string get_id_curso(){return id_curso_;};
		inline void set_id_curso(std::string id_curso){id_curso_=id_curso;};

		bool inscribirseCurso(std::string id);
};



#endif /* USUARIO_H */
