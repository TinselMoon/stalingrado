#pragma once
#include "Fases/Fase_prim.hpp"
#include "Fases/Fase_seg.hpp"
#include "Menu.hpp"

namespace Stalingrado{

namespace Entidades{

namespace Personagens{
//Forward declaration para usar ponteiro
class Jogador;
class Inim_facil;
        }
    }

class Jogo{
private:
    Gerenciadores::Gerenciador_Grafico GG;
    sf::Clock clock;
    sf::Time tempoDecorrido;
    static float dt;
    Menu mJogo;
    Entidades::Personagens::Jogador *pJog1;
    Fases::Fase_prim *fase_um; //Será que criar ponteiro e só alocar memória quando for jogar?
public:
    Jogo();
    ~Jogo();
    void executar();
    static float getDt();
};
}
