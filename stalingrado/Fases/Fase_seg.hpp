#pragma once
#include "fase.hpp"

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
    void criarCenario();
    void executar();
};



}

}
