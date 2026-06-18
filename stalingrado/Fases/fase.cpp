#include "fase.hpp"
#include "../Entidades/Personagens/Inim_medio.hpp"
#include "../Entidades/Obstaculos/Entulho.hpp"
#include <string>
using namespace std;

namespace Stalingrado {

namespace Fases{

Fase::Fase(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2, const std::string& texturaFundo, const std::string& texturaChao) :
Ente(texturaFundo), chao(NULL), GC(pJogador1, pJogador2), lista_ents(), maxInimMedios(10), comprimentoFase(0), fase_concluida(false){
    pJog1 = pJogador1;
    pJog2 = pJogador2;
}

Fase::~Fase(){

}

void Fase::criarInimMedios(float x, float y){
    Entidades::Personagens::Inim_medio *pEntidade = new Entidades::Personagens::Inim_medio(10, 2);
    GC.incluirInimigo(pEntidade);
    float pos_aleatoria = (rand() % (comprimentoFase - (int)x)) + x;
    pEntidade->movePos(pos_aleatoria, y);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
}

void Fase::criarPlataformas(float x, float y){
    Entidades::Obstaculos::Entulho *pEntidade = new Entidades::Obstaculos::Entulho();
    GC.incluirObstaculo(pEntidade);
    pEntidade->movePos(x, y);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
}

const bool Fase::inimigosMortos() const{
    return GC.inimigosMortos();
}
const bool Fase::faseConcluida() const{
    return fase_concluida;
}
}

} // Fim do namespace Stalingrado
