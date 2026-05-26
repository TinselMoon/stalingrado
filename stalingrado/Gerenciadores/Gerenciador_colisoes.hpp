#pragma once
#include <vector>
#include <list>
#include <set>

namespace Stalingrado {
using namespace std;

namespace Entidades{
    class Projetil;
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
    
};

}

} // Fim do namespace Stalingrado
