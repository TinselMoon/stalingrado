#include "Jogador.hpp"

#include <iostream>

#include "../../Jogo.hpp"
#include <SFML/Graphics/Rect.hpp>

#define VEL_JOG 1.0f //Velocidade do Jogador
#define PODER_JOG1 4 //Quantidade de dano que o Jogador 1 pode infligir nos inimigos
#define PODER_JOG2 1 //Quantidade de dano que o Jogador 2 pode infligir nos inimigos

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace std;

            int Jogador::cont_jog(1);

            Jogador::Jogador(int vida) : Personagem(vida,cont_jog==1 ? PODER_JOG1 : PODER_JOG2, cont_jog==1 ? "Soldado" : "Cachorro"),
            WisPressed(false), multiplicador_vel(VEL_JOG), belicoso(false) {
                pontos = 0;
                id_jog = cont_jog;
                cont_jog++;
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

            void Jogador::lerMovimentacao(){

                sf::Keyboard::Key esquerda[2] = {sf::Keyboard::A , sf::Keyboard::Left};
                sf::Keyboard::Key pular[2] = {sf::Keyboard::W , sf::Keyboard::Up};
                sf::Keyboard::Key direita[2] = {sf::Keyboard::D , sf::Keyboard::Right};
                sf::Keyboard::Key atacar[2] = {sf::Keyboard::LShift , sf::Keyboard::RShift};

                    bool left = false;
                    bool right = false;
                    float velAntiga = getVelX();
                    float velAtual = 0;
                    setVelocidadeX(0.f);

                    if (sf::Keyboard::isKeyPressed(atacar[id_jog-1]))
                        belicoso = true;

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
                multiplicador_vel = 1.0f;
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

                if (pPers==NULL) {cerr << "Erro no Personagem(ponteiro nulo)" << endl; exit(1);}

                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 0.25f) {
                    pPers->operator-=(nivel_maldade);
                    dt_dano = 0;
                }

            }
        }
    }
}
