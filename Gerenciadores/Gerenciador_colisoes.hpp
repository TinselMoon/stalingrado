#pragma once
#include <vector>
#include <list>
#include <set>
using namespace std;

namespace Entidades{
    class Projetil;
    namespace Obstaculos{
        class Obstaculo;
    }
    namespace Personagens{
        class Inimigo;
    }
    class Jogador;
}

namespace Gerenciadores{

//CLASSE GERENCIADOR DE COLISOES, IMPLEMENTAR
class Gerenciador_Colisoes{
private:
    vector<Entidades::Personagens::Inimigo*>LIs;
    list<Entidades::Obstaculos::Obstaculo*>LOs;
    set<Entidades::Projetil*>LPs;
    Entidades::Jogador* pJog1;
    Entidades::Jogador* pJog2;
public:
    
};

}
