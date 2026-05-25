#include "Obstaculo.hpp"
using namespace Obstaculos;

Obstaculo::Obstaculo() : Entidades::Entidade(){
    danoso = false;
    lentidao = false;
}


Obstaculo::Obstaculo(bool dano, bool lento) : Entidades::Entidade(){
    danoso = dano;
    lentidao = lento;
}

Obstaculo::~Obstaculo(){
    danoso = false;
}

void Obstaculo::salvarDataBuffer(){

}
