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
//CLASSE FASE PRIMEIRA
class Fase_prim : public Fase{
private:
    const int maxInimFaceis; //IMPLEMENTAR VALOR MAXIMO
protected:
    void criarInimFaceis();
    void criarArame_farp();
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_prim();
    ~Fase_prim();
    void criarCenario();
    void executar();
};
}
}
