#include "Stalingrad.hpp"
#include <SFML/Graphics.hpp>
using namespace Stalingrado;
using namespace Gerenciadores;

//INICIO ENTE 
Ente::Ente(const sf::Texture &texture) : id(contId++), pFig(NULL), personagem(texture)

{


}

Ente::Ente() : id(contId++), pFig(NULL), personagem(){

}

Gerenciador_Grafico* Ente::pGG(NULL);
int Ente::contId(0);


Ente::~Ente() {


}

void Ente::desenhar () {



}

void Ente::setGG (Gerenciador_Grafico* pG) {
    pGG = pG;
}
//FIM ENTE


//INICIO JOGO
//AQUI NA CONSTRUTORA EU FAÇO O SET DA INSTANCIA DO GERENCIADOR GRAFICO PARA TODOS OS ENTES
Jogo::Jogo() : GG(), mJogo(this){
    Ente::setGG(&GG);
}

Jogo::~Jogo(){

}

void Jogo::executar(){
    //IMPLEMENTAR
}
//FIM JOGO

//INICIO MENU
Menu::Menu(const Jogo *pJ) : Ente(), pJog(pJ){
}

Menu::~Menu(){

}

void Menu::executar(){

}
//FIM MENU

