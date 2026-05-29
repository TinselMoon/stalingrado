#pragma once
#include <vector>
#include <list>
#include <set>
#include <cstdlib>
using namespace std;

namespace Stalingrado {

namespace Entidades{
    class Projetil;
    class Entidade;
    namespace Obstaculos{
        class Obstaculo;
    }
    namespace Personagens{
        class Inimigo;
        class Jogador;
    }
}

namespace Gerenciadores{

//CLASSE GERENCIADOR DE COLISOES, IMPLEMENTAR
class Gerenciador_Colisoes{
private:
    vector<Entidades::Personagens::Inimigo*>LIs;
    list<Entidades::Obstaculos::Obstaculo*>LOs;
    set<Entidades::Projetil*>LPs;
    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;
public:
    Gerenciador_Colisoes(Entidades::Personagens::Jogador *pJ1 = NULL, Entidades::Personagens::Jogador *pJ2 = NULL);
    ~Gerenciador_Colisoes();
    const bool verificarColisao(Entidades::Entidade *pe1, Entidades::Entidade *pe2) const;
    void tratarColisoesJogsObstaculos();
    void tratarColisoesJogsInimigos();
    void tratarColisoesJogsProjeteis();
    void incluirInimigo(Entidades::Personagens::Inimigo *pi);
    void incluirObstaculo(Entidades::Obstaculos::Obstaculo *po);
    void incluirProjetil(Entidades::Projetil *pj);
    void executar();
};

}

} // Fim do namespace Stalingrado
