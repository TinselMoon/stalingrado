#include "Jogador.hpp"
#include <iostream>
#include "../../States/Jogo.hpp"
#include <SFML/Graphics/Rect.hpp>

using namespace std;

#define VEL_JOG 1.0f //Velocidade do Jogador
#define PODER_JOG1 4 //Quantidade de dano que o Jogador 1 pode infligir nos inimigos
#define PODER_JOG2 2 //Quantidade de dano que o Jogador 2 pode infligir nos inimigos

#define TEXTURA_ATAQUE_JOG1 "SoldadoAtaca"
#define TEXTURA_ATAQUE_JOG2 "CachorroAtaca"

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace States;

            int Jogador::cont_jog(1);

            Jogador::Jogador(int vida) : Personagem(vida, cont_jog == 1 ? "Soldado" : "Cachorro"),
            WisPressed(false), multiplicador_vel(1.f), belicoso(false), cooldown_mov(0), dt_dano(0),
            olhandoEsquerda(false)
            {
                pontos = 0;
                id_jog = cont_jog;
                cont_jog++;
                dano = (cont_jog == 1 ? 4 : 2);

                texturaIdle = corpo.getTexture();
                tamanhoIdle = pGG->getTamanhoTextura(id_jog == 1 ? "Soldado" : "Cachorro");
                texturaAtaque = &(pGG->getTextura(id_jog == 1 ? TEXTURA_ATAQUE_JOG1 : TEXTURA_ATAQUE_JOG2));
                tamanhoAtaque = pGG->getTamanhoTextura(id_jog == 1 ? TEXTURA_ATAQUE_JOG1 : TEXTURA_ATAQUE_JOG2);
            }

            Jogador::~Jogador(){
                pontos = -1;
            }

            void Jogador::setMultiplicadorVel(float mult) {
                multiplicador_vel = mult;
            }

            bool Jogador::getBelicoso() const {
                return belicoso;
            }

            void Jogador::setBelicoso(bool belico) {
                belicoso = belico;
            }
            
            void Jogador::setCooldown(float cd){
                cooldown_mov = cd;
            }

            void Jogador::impulso(float mult){
                cooldown_mov = 0.5f;
                vel_x = -vel_x*mult;
                vel_y = -300.f;
            }
            void Jogador::lerMovimentacao(){

                sf::Keyboard::Key esquerda[2] = {sf::Keyboard::A , sf::Keyboard::Left};
                sf::Keyboard::Key pular[2] = {sf::Keyboard::W , sf::Keyboard::Up};
                sf::Keyboard::Key direita[2] = {sf::Keyboard::D , sf::Keyboard::Right};
                sf::Keyboard::Key atacar[2] = {sf::Keyboard::LShift , sf::Keyboard::RShift};

                    bool left = false;
                    bool right = false;
                    float velAntiga = getVelX();
                    float velAtual = 0;

                    if (sf::Keyboard::isKeyPressed(atacar[id_jog-1]))
                        belicoso = true;
                    else
                        belicoso = false;
                    if(cooldown_mov > 0){
                        cooldown_mov -= Jogo::getDt();
                    }
                    else{
                        setVelocidadeX(0.f);
                        if (sf::Keyboard::isKeyPressed(esquerda[id_jog-1]))
                        {
                            setVelocidadeX(-400.f*multiplicador_vel);
                            left = true;
                        }
                        if (sf::Keyboard::isKeyPressed(direita[id_jog-1]))
                        {
                            setVelocidadeX(400.f*multiplicador_vel);
                            right = true;
                        }
                        if(left && right){
                            setVelocidadeX(0.f);
                        }
                        if(getVelY() == 0){
                            if (sf::Keyboard::isKeyPressed(pular[id_jog-1]) && !WisPressed)
                            {
                                //Negativo pq as coordenadas Y são invertidas na SFML
                                setVelocidadeY(-900.f);
                                WisPressed = true;
                            }
                            else{
                                WisPressed = false;
                            }
                        }
                    }
                    velAtual = getVelX();
                    if(velAntiga != velAtual){
                        //Atualizar lado que o personagem esta olhando
                        int larguraTextura = corpo.getTexture()->getSize().x;
                        int alturaTextura = corpo.getTexture()->getSize().y;
                        if(velAtual > 0){
                            corpo.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
                            olhandoEsquerda = false;
                        }
                        if(velAtual < 0){
                            corpo.setTextureRect(sf::IntRect(larguraTextura, 0,-larguraTextura, alturaTextura));
                            olhandoEsquerda = true;
                        }
                    }
                multiplicador_vel = 1.0f;

                aplicarTexturaAtaque();
            }

            void Jogador::aplicarTexturaAtaque(){
                const sf::Texture* texturaAlvo = belicoso ? texturaAtaque : texturaIdle;

                if (corpo.getTexture() == texturaAlvo) return;

                sf::Vector2f tamanhoAlvo = belicoso ? tamanhoAtaque : tamanhoIdle;
                sf::Vector2u tamanhoOriginal = texturaAlvo->getSize();

                corpo.setTexture(*texturaAlvo, true);
                corpo.setOrigin(tamanhoOriginal.x / 2.f, tamanhoOriginal.y / 2.f);
                corpo.setScale(tamanhoAlvo.x / tamanhoOriginal.x, tamanhoAlvo.y / tamanhoOriginal.y);

                if (olhandoEsquerda)
                    corpo.setTextureRect(sf::IntRect(tamanhoOriginal.x, 0, -(int)tamanhoOriginal.x, tamanhoOriginal.y));
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

            void Jogador::danificar(Personagem *pPers) {

                if (pPers==nullptr) {cerr << "Erro no Personagem(ponteiro nulo)" << endl; return;}

                dt_dano += States::Jogo::getDt(); //tempo de contato para dar dano
                if (dt_dano > 0.25f) {
                    pPers->operator-=(dano);
                    if(pPers->getVida() == 0){
                        pontos += pPers->getPontos();
                        pPers->eliminar(this);
                    }
                    dt_dano = 0;
                    belicoso=false; //volta ao modo nao belicoso
                }

            }
        }
    }
}
