#include "Jogador.hpp"
#include "../../Jogo.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            int Jogador::cont_jog(1);

            Jogador::Jogador(int vida) : Personagem(vida, cont_jog==1 ? "Soldado" : "Cachorro"), WisPressed(false), multiplicador_vel(1.0f){
                pontos = 0;
                id_jog = cont_jog;
                cont_jog++;
            }

            Jogador::~Jogador(){
                pontos = -1;
            }

            void Jogador::colidir(Inimigo* pIn){

            }

            void Jogador::setMultiplicadorVel(float mult) {
                multiplicador_vel = mult;
            }

            void Jogador::lerMovimentacao(){

                sf::Keyboard::Key esquerda[2] = {sf::Keyboard::A , sf::Keyboard::Left};
                sf::Keyboard::Key pular[2] = {sf::Keyboard::W , sf::Keyboard::Up};
                sf::Keyboard::Key direita[2] = {sf::Keyboard::D , sf::Keyboard::Right};

                //if(getVelY() == 0){
                    bool left = false;
                    bool right = false;
                    float velAntiga = getVelX();
                    float velAtual = 0;
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

            }
        }
    }
}
