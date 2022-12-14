#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <list>
#include "../recurso/recurso.h"

class Curso {
    private:
        std::list<std::string> id_participantes_;
        std::list<Recurso> recursos_;
        std::string id_, nombre_, descripcion_;
        time_t fecha_inicio_, fecha_fin_;
        std::string correo_admin_curso_, ponentes_, requisitos_;
        int participantes_, max_participantes_;
        float precio_;
        float exito_;
    public:
    
        Curso(std::string id, std::string nombre, std::string descripcion, time_t fecha_inicio, time_t fecha_fin, std::string correo_admin_curso,
              std::string ponentes, std::string requisitos, int participantes, int max_participantes, float precio);
    
        inline std::string get_id() { return id_; };
        inline void set_id(std::string id) { id_ = id; };
        inline std::string get_nombre() { return nombre_; };
        inline void set_nombre(std::string nombre) { nombre_ = nombre; };
        inline std::string get_descripcion() { return descripcion_; };
        inline void set_descripcion(std::string descripcion) { descripcion_ = descripcion; };
        inline const time_t get_fecha_inicio() const { return fecha_inicio_; };
        inline void set_fecha_inicio(time_t fecha_inicio) { fecha_inicio_ = fecha_inicio; };
        inline const time_t get_fecha_fin() const { return fecha_fin_; };
        inline void set_fecha_fin(time_t fecha_fin) { fecha_fin_ = fecha_fin; };
        inline std::string get_correo_admin_curso() { return correo_admin_curso_; };
        inline void set_correo_admin_curso(std::string correo_admin_curso) { correo_admin_curso_ = correo_admin_curso; };
        inline std::string get_ponentes() { return ponentes_; };
        inline void set_ponentes(std::string ponentes) { ponentes_ = ponentes; };
        inline std::string get_requisitos() { return requisitos_; };
        inline void set_requisitos(std::string requisitos) { requisitos_ = requisitos; };
        inline int get_participantes() { return participantes_; };
        inline int get_max_participantes() { return max_participantes_; };
        inline void set_max_participantes(int max_participantes) { max_participantes_ = max_participantes; };
        inline float get_exito() { return exito_; };
        inline void set_exito(float exito) { exito_ = exito; };
        inline float get_precio() { return precio_; };
        inline void set_precio(float precio) { precio_ = precio; };
        bool addInscripcion(std::string id_usuario);
        bool quitarInscripcion(std::string id_usuario);
        bool cargarListaParticipantes();
        bool guardarListaParticipantes();
        bool addRecurso(Recurso R);
        Recurso quitarRecurso(std::string id);
        inline std::list<Recurso> verRecursos() {return recursos_; };
        bool cargarListaRecursos();
        bool guardarListaRecursos();
};


#endif
