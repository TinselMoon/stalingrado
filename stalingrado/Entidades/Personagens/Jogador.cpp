#include "Jogador.hpp"
#include "../../Jogo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Jogador::Jogador(int vida) : Personagem(vida, "Soldado"), WisPressed(false){
    pontos = 0;
}
Jogador::~Jogador(){
    pontos = -1;
}

void Jogador::colidir(Inimigo* pIn){

}

void Jogador::verificarTeclas(){
    if(getVelY() == 0){
        setVelocidadeX(0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setVelocidadeX(-200.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            setVelocidadeX(200.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !WisPressed)
        {
            //Negativo pq as coordenadas Y são invertidas
            setVelocidadeY(-600.f);
            WisPressed = true;
        }
        else{
            WisPressed = false;
        }
    }
}
void Jogador::mover(){
    //MUDAR AGORA QUE USAMOS SPRITE
    verificarTeclas();
    float dx = 0, dy = 0, dt = 0;
    dt = Jogo::getDt();
    setVelocidadeY(getVelY() + 980.f*dt);
    dx = getVelX()*dt;
    dy = getVelY()*dt;

    personagem.move(dx, dy);

    sf::Vector2f posi = personagem.getPosition();
    if(posi.y >= 600.f) {
        posi.y = 600.f;
        personagem.setPosition(posi);
        setVelocidadeY(0.f); // Zerar a velocidade Y ao tocar no chão é o que permite pular de novo!
    }
}

void Jogador::executar(){
    mover();
}

void Jogador::salvar(){

}

/*
void Jogador::desenhar(){
}
*/
}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
