#include "Explosivo.hpp"
using namespace Obstaculos;

Explosivo::Explosivo() : Obstaculo(true, false){
}

Explosivo::Explosivo(int dano) : Obstaculo(true, false){
    danosidade = dano;
}

Explosivo::~Explosivo(){
}

void Explosivo::executar(){

}

void Explosivo::salvar(){
}

void Explosivo::obstaculizar(Personagens::Jogador* pJ){

}
