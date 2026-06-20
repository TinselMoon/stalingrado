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
    const int maxInimChefoesAleatorios;
    const int maxExplosivosAleatorios;
protected:
    void criarChefoes(float x, float y);
    void criarExplosivos(float x, float y);
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_seg(Entidades::Personagens::Jogador *pJogador1 = nullptr, Entidades::Personagens::Jogador *pJogador2 = nullptr);
    ~Fase_seg();
    void criarCenario();
    void executar();
};



}

}
