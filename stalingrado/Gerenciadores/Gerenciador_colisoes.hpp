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

    //Estrutura retornada pelo metodo que calcula sobreposicao
    //apenas usada internamente por outro métodos
    struct sobreposicao{
        float distX;
        float distY;
        float overlapX;
        float overlapY;
    };
    
    void resolverColisaoCinematica(Entidades::Entidade *pJ, Entidades::Entidade *pE);
    struct sobreposicao calcularSobreposicao(Entidades::Entidade *pJ, Entidades::Entidade *pE);
    void resolverColisaoJogInim(Entidades::Entidade *pJ, Entidades::Entidade *pE);
    const bool verificarColisao(Entidades::Entidade *pe1, Entidades::Entidade *pe2) const;
    const bool verificarColisao(Entidades::Entidade *pe1, Entidades::Entidade *pe2, float margemExtra) const;
    void tratarColisoesJogsObstaculos();
    void tratarColisoesJogsInimigos();
    void tratarColisoesJogsProjeteis();
    void colisoesChao(Entidades::Entidade *pe); //Precisa verificar se o jogador e inimigo estão sobre o chão
    void colisaoBorda(Entidades::Personagens::Personagem *pP);

public:
    Gerenciador_Colisoes(Entidades::Personagens::Jogador *pJ1 = nullptr, Entidades::Personagens::Jogador *pJ2 = nullptr);
    ~Gerenciador_Colisoes();
    void setChao(Entidades::Chao *pC);
    void incluirInimigo(Entidades::Personagens::Inimigo *pi);
    void incluirObstaculo(Entidades::Obstaculos::Obstaculo *po);
    void incluirProjetil(Entidades::Projetil *pj);
    void tratarColisoesObsObs();
    void executar();
    Entidades::Projetil* getProjetil(int id_chefao) const;
    const bool inimigosMortos() const;
};

}

} // Fim do namespace Stalingrado
