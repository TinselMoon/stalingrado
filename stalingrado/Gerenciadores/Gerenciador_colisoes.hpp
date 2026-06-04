#pragma once
#include <vector>
#include <list>
#include <set>
#include <cstdlib>

namespace Stalingrado {

namespace Entidades{
    class Projetil;
    class Entidade;
    class Chao;
    namespace Obstaculos{
        class Obstaculo;
    }
    namespace Personagens{
        class Personagem;
        class Inimigo;
        class Jogador;
    }
}

namespace Gerenciadores{

//CLASSE GERENCIADOR DE COLISOES, IMPLEMENTAR
class Gerenciador_Colisoes{
private:
    std::vector<Entidades::Personagens::Inimigo*>LIs;
    std::list<Entidades::Obstaculos::Obstaculo*>LOs;
    std::set<Entidades::Projetil*>LPs;
    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;
    Entidades::Chao *chao;
    
    void resolverColisaoCinematica(Entidades::Personagens::Jogador *pJ, Entidades::Entidade *pE);
    const bool verificarColisao(Entidades::Entidade *pe1, Entidades::Entidade *pe2) const;
    void tratarColisoesJogsObstaculos();
    void tratarColisoesJogsInimigos();
    void tratarColisoesJogsProjeteis();
    void colisoesChao(Entidades::Personagens::Personagem *pe); //Precisa verificar se o jogador e inimigo estão sobre o chão
    void colisaoBorda(Entidades::Personagens::Personagem *pP);

public:
    Gerenciador_Colisoes(Entidades::Personagens::Jogador *pJ1 = NULL, Entidades::Personagens::Jogador *pJ2 = NULL);
    ~Gerenciador_Colisoes();
    void setChao(Entidades::Chao *pC);
    void incluirInimigo(Entidades::Personagens::Inimigo *pi);
    void incluirObstaculo(Entidades::Obstaculos::Obstaculo *po);
    void incluirProjetil(Entidades::Projetil *pj);
    void executar();
};

}

} // Fim do namespace Stalingrado
