#pragma once
#include "../Stalingrad.hpp"
#include "../Gerenciadores/Gerenciador_grafico.hpp"
#include "../Gerenciadores/Gerenciador_colisoes.hpp"
#include "../Listas/Lista_entidades.hpp"

#define MAXINIMMED 5
#define MAXCHEFOES 3

namespace Stalingrado {


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
    virtual void criarInimigos() = 0;
    virtual void criarObstaculos() = 0;
    void criarInimFaceis();
    void criarPlataformas(); // As plataformas são os entulhos
    void criarCenario();
public:
    Fase();
    ~Fase();
    virtual void executar();

};

//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimMedios; //IMPLEMENTAR VALOR MAXIMO
protected:
    void criarInimMedios();
    void criarArame_farp();
public:
    Fase_prim();
    ~Fase_prim();
    void criarInimigos();
    void criarObstaculos();
};

//CLASSE FASE SEGUNDA
class Fase_seg : public Fase{
private:
    const int maxChefoes; //IMPLEMENTAR VALOR MAXIMO
protected:
    void criarChefoes();
    void criarExplosivos();
    void criarProjeteis();
public:
    Fase_seg();
    ~Fase_seg();
    void criarInimigos();
    void criarObstaculos();
};

}

} // Fim do namespace Stalingrado
