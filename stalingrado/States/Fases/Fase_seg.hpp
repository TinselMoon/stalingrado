#pragma once
#include "fase.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace Stalingrado{

//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    namespace Personagens{
        class Jogador;
        class Inimigo;
        class Inim_chefao;
    }
}


namespace Fases{

//CLASSE FASE SEGUNDA
class Fase_seg : public Fase{
private:
    const int maxInimChefoesAleatorios;
    const int maxExplosivosAleatorios;
protected:
    void criarCenarioBase();
    void carregarSalvo(const char* caminhoArquivo);
    void criarChefoes(float x, float y);
    Entidades::Personagens::Inim_chefao* criarChefoes(float x, float y, int vida);
    void criarExplosivos(float x, float y);
    void criarInimigos();
    void criarObstaculos();
public:
    Fase_seg(Entidades::Personagens::Jogador *pJogador1 = nullptr, Entidades::Personagens::Jogador *pJogador2 = nullptr, bool carregarSave = false);
    ~Fase_seg();
    void criarCenario();
    void executar();
};



}

}
