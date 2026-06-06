#include "Gerenciador_colisoes.hpp"
#include "../Entidades/Personagens/Inimigo.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Entidades/Obstaculos/Obstaculo.hpp"
#include "../Entidades/Projetil.hpp"
#include "../Entidades/Chao.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdio>
using namespace std;
using namespace Stalingrado;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Gerenciadores;


namespace Stalingrado {
    
namespace Gerenciadores{

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador *pJ1, Jogador *pJ2):
LIs(), LOs(), LPs(), pJog1(pJ1), pJog2(pJ2){

}

Gerenciador_Colisoes::~Gerenciador_Colisoes(){
    //Limpa os vetores, listas e aterra os ponteiros. A memoria deve ser desalocada na fase
    pJog1 = pJog2 = NULL;
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

void Gerenciador_Colisoes::setChao(Entidades::Chao* pC){
    chao = pC;
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade *pe1, Entidade *pe2) const {
    if (pe1 == NULL || pe2 == NULL) {
        return false;
    }
    return pe1->getRectangle().intersects(pe2->getRectangle());
}

void Gerenciador_Colisoes::resolverColisaoCinematica(Jogador *pJ, Entidade *pE){

    sf::FloatRect caixaJog = pJ->getRectangle();
    sf::FloatRect caixaObs = pE->getRectangle();

    //Calcula os centros de cada caixa
    // Utilizando o caixaJog.top pq o eixo y é invertido
    float centroJogX = caixaJog.left + caixaJog.width / 2.0f;
    float centroJogY = caixaJog.top + caixaJog.height / 2.0f;

    float centroObsX = caixaObs.left + caixaObs.width / 2.0f;
    float centroObsY = caixaObs.top + caixaObs.height / 2.0f;

    // Calcula as distâncias entre os centros
    float distX = centroJogX - centroObsX;
    float distY = centroJogY - centroObsY;

    //Calcula a distância mínima para não haver colisão
    float minX = (caixaJog.width / 2.0f) + (caixaObs.width / 2.0f);
    float minY = (caixaJog.height / 2.0f) + (caixaObs.height / 2.0f);

    //Calcula a sobreposição em cada eixo
    float overlapX = minX - std::abs(distX);
    float overlapY = minY - std::abs(distY);

    if (overlapX > 0.0f && overlapY > 0.0f) {
        if (overlapX < overlapY) {
            // Colisão Horizontal
            if (distX > 0) {
                // empurra para a direita
                pJ->movePos(overlapX, 0.0f); 
            } else {
                //empurra para a esquerda
                pJ->movePos(-overlapX, 0.0f); 
            }
        } else {
            // Colisão Vertical
            if (distY > 0) {
                // empurra para baixo
                pJ->movePos(0.0f, overlapY); 
                pJ->setVelocidadeY(0.0f); 
            } else {
                //empurra para cima
                pJ->movePos(0.0f, -overlapY); 

                //Zerar velocidade do jogador para ele não ficar caindo sobre o obstáculo
                pJ->setVelocidadeY(0.0f); 
            }
        }
    }
}


void Gerenciador_Colisoes::tratarColisoesJogsObstaculos(){
    //Chama a verificarColisao, se for true arruma a pos
    for(list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++){
        if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
            //Se colidir, arruma a posição do persongem e executa o obstáculo
            resolverColisaoCinematica(pJog1, *it);
            //
            //AQUI CHAMAR A FUNÇÃO EXECUTAR PRESENTE NO OBSTACULO
            //
        }
        if(pJog2){
            if(verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it))){
                //Se colidir, arruma a posição do persongem e executa o obstáculo
                resolverColisaoCinematica(pJog2, *it);
                //
                //AQUI CHAMAR A FUNÇÃO EXECUTAR PRESENTE NO OBSTACULO
                //
            }
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsInimigos(){
    //Chama a verificarColisao, se for true arruma a pos
    Personagem *jog1 = static_cast<Personagem*>(pJog1);
    Personagem *jog2 = static_cast<Personagem*>(pJog2);
    colisoesChao(jog1);
    colisaoBorda(jog1);
    if(pJog2){
        colisoesChao(jog2);
        colisaoBorda(jog2);
    }
    for(vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++){
        if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
            //Arrumar colisao
            resolverColisaoCinematica(pJog1, *it);
            //executar Inimigo
        }
        Personagem *inim = static_cast<Personagem*>(*it);
        colisoesChao(inim);
        colisaoBorda(inim);
        if(pJog2){
            if(verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it))){
                //Arrumar colisao
                resolverColisaoCinematica(pJog2, *it);
            }
        }
    }
}

void Gerenciador_Colisoes::colisaoBorda(Personagem *pP){
    sf::Vector2f posi = pP->getPos();
    float dist_centro = pP->getSprite()->getGlobalBounds().width / 2.f;
    if(posi.x - dist_centro < 0){
        float correcaoX = dist_centro - posi.x;
        pP->movePos(correcaoX, 0.f);
        pP->setVelocidadeX(0.f);
    }
    else if(posi.x + dist_centro > 10000 /* Largura do mapa */){
        float correcaoX = 10000 - dist_centro - posi.x;
        pP->movePos(correcaoX, 0.f);
        pP->setVelocidadeX(0.f);
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsProjeteis(){
    //Chama a verificarColisao, se for true arruma a pos
    for(set<Projetil*>::iterator it = LPs.begin(); it != LPs.end(); it++){
        if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
            //Se colidir, dá dano ao jogador e destroi o projetil
            resolverColisaoCinematica(pJog1, *it);
            //Precisa executar o projetil, dar dano ao jogador e destruir o projetil
        }
        if(pJog2){
            if(verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it))){
                //Se colidir, dá dano ao jogador e destroi o projetil
                resolverColisaoCinematica(pJog2, *it);
                //Precisa executar o projetil, dar dano ao jogador e destruir o projetil
            }
        }
    }
}

void Gerenciador_Colisoes::colisoesChao(Personagem *pe){
    //Inimigos primeiro
    Entidades::Entidade *pEntidade = static_cast<Entidades::Entidade*>(chao);
    if(verificarColisao(static_cast<Entidades::Entidade*>(pe), pEntidade)){

        sf::FloatRect caixaEnt = pe->getRectangle();
        sf::FloatRect caixaChao = pEntidade->getRectangle();

        float centroEntY = caixaEnt.top + caixaEnt.height / 2.0f;

        float centroChaoY = caixaChao.top + caixaChao.height / 2.0f;
        
        float distY = centroEntY - centroChaoY;

        float minY = (caixaEnt.height / 2.0f) + (caixaChao.height / 2.0f);

        float overlapY = minY - std::abs(distY);
        if(overlapY > 0){
            pe->movePos(0.0f, -overlapY);
            pe->setVelocidadeY(0.0f);
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
    tratarColisoesJogsInimigos();
    tratarColisoesJogsProjeteis();
    tratarColisoesJogsObstaculos();
}


} //Fim namespace Gerenciadores

} // Fim do namespace Stalingrado

