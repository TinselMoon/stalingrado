#include "Personagem.hpp"

Personagens::Personagem::Personagem() : Entidades::Entidade(){
    num_vidas = 0;
}

Personagens::Personagem::Personagem(int vida) : Entidades::Entidade(){
    num_vidas = vida;
}

void Personagens::Personagem::salvarDataBuffer(){

}
