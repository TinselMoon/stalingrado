#include "Inimigo.hpp"
using namespace Personagens;

Inimigo::Inimigo(int vida, int maldade) : Personagens::Personagem(vida){
    nivel_maldade = maldade;
}

Inimigo::Inimigo() : Personagens::Personagem(){
}

Inimigo::~Inimigo(){
    nivel_maldade = -1;
}

void salvarDataBuffer(){

}

