#include "Inim_facil.hpp"

namespace Entidades {
namespace Personagens {

Inim_facil::Inim_facil(int vida, int maldade) : Personagens::Inimigo(vida, maldade){
    x = 600;
    y = 300;
    raio = 25.0f;
    corpo.setSize(sf::Vector2f(100.f, 100.f));
    corpo.setPosition((float)x, (float)y);

    if (!textura.loadFromFile("inimigo_facil.png")) {
        corpo.setFillColor(sf::Color::Red);
    } else {
        corpo.setTexture(&textura);
    }
}

Inim_facil::Inim_facil() : Personagens::Inimigo(){

}

Inim_facil::~Inim_facil(){

}


void Inim_facil::danificar(Jogador *pJ){

}
void Inim_facil::executar(){

}
void Inim_facil::salvar(){

}
void Inim_facil::mover(){

}

void Inim_facil::desenhar(){
    if (pGG != NULL) {
        pGG->desenhar(&corpo);
    }
}

}
} // Fim dos namespaces
