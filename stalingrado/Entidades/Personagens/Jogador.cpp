#include "Jogador.hpp"
#include "../../Jogo.hpp"
#include <SFML/Graphics/Rect.hpp>

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

void Jogador::lerMovimentacao(){
    //if(getVelY() == 0){
        bool A = false;
        bool D = false;
        float velAntiga = getVelX();
        float velAtual = 0;
        setVelocidadeX(0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setVelocidadeX(-400.f);
            A = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            setVelocidadeX(400.f);
            D = true;
        }
        if(A && D){
            setVelocidadeX(0.f);
            A = false;
            D = false;
        }
        if(getVelY() == 0){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !WisPressed)
            {
                //Negativo pq as coordenadas Y são invertidas
                setVelocidadeY(-800.f);
                WisPressed = true;
            }
            else{
                WisPressed = false;
            }
        }
        velAtual = getVelX();
        if(velAntiga != velAtual){
            //Atualizar lado que o personagem esta olhando
            int larguraTextura = personagem.getTexture()->getSize().x;
            int alturaTextura = personagem.getTexture()->getSize().y;
            if(velAtual > 0){
                personagem.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
            }
            if(velAtual < 0){
                personagem.setTextureRect(sf::IntRect(larguraTextura, 0,-larguraTextura, alturaTextura));
            }
        }
    //}
}
void Jogador::mover(){
    //MUDAR AGORA QUE USAMOS SPRITE
    lerMovimentacao();
    Personagem::mover();
}

void Jogador::executar(){
    mover();
}

void Jogador::salvar(){

}
}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
