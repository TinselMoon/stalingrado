#include "Jogador.hpp"

namespace Entidades {
namespace Personagens {

Jogador::Jogador(int vida) : Personagem(vida){
    pontos = 0;
}
Jogador::~Jogador(){
    pontos = -1;
}

void Jogador::colidir(Inimigo* pIn){

}

void Jogador::executar(){

}

void Jogador::salvar(){

}

void Jogador::mover(){
//TEM Q MUDAR A POSIÇÃO DO SPRITE, DEFINIDO NA CLASSE ENTE
}


}
} // Fim dos namespaces
