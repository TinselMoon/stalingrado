#include "fase.hpp"
#include "../../Entidades/Personagens/Inim_medio.hpp"
#include "../../Entidades/Obstaculos/Entulho.hpp"
#include <string>

#include "../../Defines.txt"

using namespace std;

namespace Stalingrado {

namespace Fases{

Fase::Fase(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2, const std::string& texturaFundo, const std::string& texturaChao) :
Ente(texturaFundo), chao(nullptr), GC(pJogador1, pJogador2), lista_ents(), maxInimMediosAleatorios(5), comprimentoFase(0), fase_concluida(false),
maxEntulhosAleatorios(8)
{
    pJog1 = pJogador1;
    pJog2 = pJogador2;
}

Fase::~Fase(){

}

void Fase::criarInimMedios(float x, float y){
    Entidades::Personagens::Inim_medio *pEntidade = new Entidades::Personagens::Inim_medio(VIDA_MEDIOS,MALDADE_MEDIOS);
    GC.incluirInimigo(pEntidade);
    pEntidade->movePos(x, y);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
}

void Fase::criarInimMedios(float x, float y, int vida){
    Entidades::Personagens::Inim_medio *pEntidade = new Entidades::Personagens::Inim_medio(vida,MALDADE_MEDIOS);
    GC.incluirInimigo(pEntidade);
    pEntidade->movePos(x, y);
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

void Fase::salvarFase(std::ofstream& arquivo){
    lista_ents.salvar(arquivo);
}

}

} // Fim do namespace Stalingrado
