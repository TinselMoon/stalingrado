#pragma once
#include "../Stalingrad.hpp"
#include "../Gerenciadores/Gerenciadores.hpp"
#include "../Listas/listas.hpp"
using namespace Listas;
using namespace Gerenciadores;
using namespace Stalingrado;

//NAMEPSACE COM TODAS AS FASES
namespace Fases{
class Fase : public Ente{
protected:
    ListaEntidades lista_ents;
    Gerenciador_Colisoes GC;
public:
    Fases() : Ente(){

    }

};

//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimMedios; //IMPLEMENTAR VALOR MAXIMO
public:
    Fase_prim() : Fase(){}
};

//CLASSE FASE SEGUNDA
class Fase_seg : public Fase{
private:
    const int maxChefoes; //IMPLEMENTAR VALOR MAXIMO
public:
    Fase_seg() : Fase(){

    }
    ~Fase_seg()
};

}
