#include "Jogador.hpp"

namespace Stalingrado {

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
    mover();
}

void Jogador::salvar(){

}

void Jogador::mover(){
    //MUDAR AGORA QUE USAMOS SPRITE

}

void Jogador::desenhar(){
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
