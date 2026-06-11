#pragma once
#include "fase.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace Stalingrado{

//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    namespace Personagens{
        class Jogador;
        class Inimigo;
    }
}


namespace Fases{

//CLASSE FASE SEGUNDA
class Fase_seg : public Fase{
private:
    const int maxInimChefoes;
    const int maxExplosivos;
    const int maxEntulhos;
    Entidades::Chao* chao;
protected:
    void criarChefoes(float x, float y);
    void criarExplosivos(float x1, float x2);
    //void criarProjeteis(); implementar depois
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_seg(Entidades::Personagens::Jogador *pJogador1 = NULL, Entidades::Personagens::Jogador *pJogador2 = NULL);
    ~Fase_seg();
    void criarCenario();
    void executar();
};



}

}
