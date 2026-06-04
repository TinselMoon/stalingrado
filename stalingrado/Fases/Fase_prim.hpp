#pragma once
#include "fase.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace Stalingrado{
//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    class Chao;
    class Parede;
    namespace Personagens{
        class Jogador;
        class Inimigo;
    }
}

namespace Fases{
//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimFaceis; //IMPLEMENTAR VALOR MAXIMO
    Entidades::Chao *chao;
    Entidades::Parede *pEsquerda;
    Entidades::Parede *pDireita;
protected:
    void criarInimFaceis();
    void criarArame_farp();
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_prim(Entidades::Personagens::Jogador *pJogador1 = NULL, Entidades::Personagens::Jogador *pJogador2 = NULL);
    ~Fase_prim();
    void criarCenario();
    void executar();
};
}
}
