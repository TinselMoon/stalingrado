#include "Stalingrad.hpp"
#include <SFML/Graphics.hpp>
using namespace Stalingrado;
using namespace Gerenciadores;

//INICIO ENTE 
Ente::Ente(const sf::Texture &texture) : id(contId++), pFig(NULL)//, personagem(texture),
//actual_shape()
{


}

Ente::Ente() : id(contId++), pFig(NULL)//, personagem()
{

}

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
    while (GG.getJanela()->isOpen()) { //loop 'infinito' para so fechar janela qnd apertar esc ou clicar no x
        sf::Event evento;
        while (GG.getJanela()->pollEvent(evento)) {
            if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                GG.getJanela()->close();
            }
        }
    }   //IMPLEMENTAR
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

