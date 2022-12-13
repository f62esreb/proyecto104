#include<iostream>



enum class Tipo{
    CAMARA,
    PROYECTOR,
    AULA
};

class Recurso{
    private:
    std::string id_;
    Tipo recurso_;
    int calidad_imagen_, brillo_, resolucion_,aforo_;
    public:
    Recurso(std::string id, Tipo recurso, int calidad_imagen=0, int brillo=0, int resolucion=0, int aforo=0){id_=id; recurso_=recurso;};

    inline Tipo get_recurso(){return recurso_;};
    inline void set_recurso(Tipo recurso){recurso_=recurso;};

    inline int get_calidad_imagen_(){return calidad_imagen_;};
    inline void set_calidad_imagen_(int calidad_imagen){calidad_imagen_=calidad_imagen;};

    inline int get_brillo(){return brillo_;};
    inline void set_brillo(int brillo){brillo_=brillo;};

    inline int get_resolucion(){return resolucion_;};
    inline void set_resolucion(int resolucion){resolucion_=resolucion;};

    inline int get_aforo(){return aforo_;};
    inline void set_aforo(int aforo){aforo_=aforo;};

};


int funcion(int a){
    if(a==0) throw Tipo::CAMARA;
    else if(a==1) throw Tipo::PROYECTOR;
    else if(a==2) throw Tipo::AULA;
    else return 1;
}
int main(){

    int i;
    std::cout<< "Tipo: ";
    std::cin>>i;

    try{funcion(i);}

    catch(Tipo a){

    Recurso T("1",a);

    switch (T.get_recurso())
    {   
    case Tipo::CAMARA:
        int c;
        std::cout<<"Camara"<<std::endl;
        std::cout<<"Añada calidad de imagen: ";
        std::cin>>c;
        T.set_calidad_imagen_(c);
        std::cout<<"Calidad: "<<T.get_calidad_imagen_()<<std::endl;
        break;
    
    case Tipo::PROYECTOR:
        int b,r;
        std::cout<<"Proyector"<<std::endl;
        std::cout<<"Añada brillo: ";
        std::cin>>b;
        T.set_brillo(b);
        std::cout<<"Añada resolucion: ";
        std::cin>>r;
        T.set_resolucion(r);
        std::cout<<"Brillo: "<<T.get_brillo()<<std::endl;
        std::cout<<"Resolucion: "<<T.get_resolucion()<<std::endl;

        break;
    
    case Tipo::AULA:
        int af;
        std::cout<<"Aula"<<std::endl;
        std::cout<<"Añada aforo: ";
        std::cin>>af;
        T.set_aforo(af);
        std::cout<<"Aforo: "<<T.get_aforo()<<std::endl;
        break;
    }
    }
    return (0);
}