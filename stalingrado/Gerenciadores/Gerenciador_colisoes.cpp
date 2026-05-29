#include "Gerenciador_colisoes.hpp"
#include "../Entidades/Personagens/Inimigo.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Entidades/Obstaculos/Obstaculo.hpp"
#include "../Entidades/Projetil.hpp"
#include <cstdio>
using namespace Stalingrado;
using namespace Entidades;
using namespace Personagens;


namespace Stalingrado {
    
namespace Gerenciadores{

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador *pJ1, Jogador *pJ2):
LIs(), LOs(), LPs(), pJog1(pJ1), pJog2(pJ2){

}

Gerenciador_Colisoes::~Gerenciador_Colisoes(){
    //Limpa os vetores, listas e aterra os ponteiros, não desaloca a memória
    pJog1 = pJog2 = NULL;
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade *pe1, Entidade *pe2) const {
}

void Gerenciador_Colisoes::tratarColisoesJogsObstaculos(){
    //Chama a verificarColisao, se for true arruma a pos

}
void Gerenciador_Colisoes::tratarColisoesJogsInimigos(){
    //Chama a verificarColisao, se for true arruma a pos
    for(vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++){
        if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
            //Arrumar colisao
        }
        if(pJog2){
            if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
                //Arrumar colisao
            }
        }
    }

}
void Gerenciador_Colisoes::tratarColisoesJogsProjeteis(){
    //Chama a verificarColisao, se for true arruma a pos
    for(vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++){
        if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
            //Se colidir, dá dano ao jogador e destroi o projetil
        }
        if(pJog2){
            if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
                //Se colidir, dá dano ao jogador e destroi o projetil
            }
        }
    }

}
void Gerenciador_Colisoes::incluirInimigo(Entidades::Personagens::Inimigo *pi){
    LIs.push_back(pi);
}
void Gerenciador_Colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo *po){
    LOs.push_back(po);
}
void Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil *pj){
    LPs.insert(pj);
}
void Gerenciador_Colisoes::executar(){
    //Chama todas as funções de tratarcolisoes
}


}

} // Fim do namespace Stalingrado
