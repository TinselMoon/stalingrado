#include "Jogador.hpp"

Personagens::Jogador::Jogador(int vida) : Personagens::Personagem(vida){
    pontos = 0;
}
Personagens::Jogador::~Jogador(){
    pontos = -1;
}

void Personagens::Jogador::colidir(Inimigo* pIn){

}

void Personagens::Jogador::executar(){

}

void Personagens::Jogador::salvar(){

}

void Personagens::Jogador::mover(){
//TEM Q MUDAR A POSIÇÃO DO SPRITE, DEFINIDO NA CLASSE ENTE
}

