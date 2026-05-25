#pragma once
#include "../Stalingrad.hpp"
#include "../Gerenciadores/Gerenciador_grafico.hpp"
#include "../Gerenciadores/Gerenciador_colisoes.hpp"
#include "../Listas/listas.hpp"

#define MAXINIMMED 5
#define MAXCHEFOES 3


//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    namespace Personagens{
        class Jogador;
        class Inimigo;
    }
}

//NAMEPSACE COM TODAS AS FASES
namespace Fases{
class Fase : public Stalingrado::Ente{
protected:
    Listas::ListaEntidades lista_ents;
    Gerenciadores::Gerenciador_Colisoes GC;
public:
    Fase();
    ~Fase();

};

//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimMedios; //IMPLEMENTAR VALOR MAXIMO
public:
    Fase_prim();
    ~Fase_prim();
};

//CLASSE FASE SEGUNDA
class Fase_seg : public Fase{
private:
    const int maxChefoes; //IMPLEMENTAR VALOR MAXIMO
public:
    Fase_seg();
    ~Fase_seg();
};

}
