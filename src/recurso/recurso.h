#ifndef RECURSO_H_
#define RECURSO_H_

#include<string>
#include<list>

enum class Tipo{
    CAMARA = 1,
    PROYECTOR = 2,
    AULA = 3
};

class Recurso{

    private:
    std::string id_;
    Tipo recurso_;
    int calidad_imagen_, brillo_,aforo_;

    public:
    Recurso(std::string id, Tipo recurso, int calidad_imagen=0, int brillo=0, int aforo=0){id_=id; recurso_=recurso;};

    inline Tipo get_recurso(){return recurso_;};
    inline void set_recurso(Tipo recurso){recurso_=recurso;};

    inline int get_calidad_imagen(){return calidad_imagen_;};
    inline void set_calidad_imagen(int calidad_imagen){calidad_imagen_=calidad_imagen;};

    inline int get_brillo(){return brillo_;};
    inline void set_brillo(int brillo){brillo_=brillo;};

    inline int get_aforo(){return aforo_;};
    inline void set_aforo(int aforo){aforo_=aforo;};

	inline std::string get_id_recurso(){return id_;};

};




#endif
