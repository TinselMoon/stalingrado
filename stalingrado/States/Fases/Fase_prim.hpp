#pragma once
#include "fase.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace Stalingrado{
//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    class Chao;
    namespace Personagens{
        class Jogador;
        class Inimigo;
    }
}

namespace Fases{
//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimFaceisAleatorios; //IMPLEMENTAR VALOR MAXIMO
    const int maxEntulhosAleatorios;
    const int maxAramesAleatorios;
protected:
    void criarInimFaceis(float x, float y);
    void criarArame_farp(float x, float y);
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_prim(Entidades::Personagens::Jogador *pJogador1 = nullptr, Entidades::Personagens::Jogador *pJogador2 = nullptr);
    ~Fase_prim();
    void criarCenario();
    void executar();
};
}
}
