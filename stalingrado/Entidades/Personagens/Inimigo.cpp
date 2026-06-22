#include "Inimigo.hpp"

#include "Personagem.hpp"
#include "Jogador.hpp"
#include "../../States/Jogo.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace States;

            Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagem(vida, nomeTextura),
            pontos_por_kill(10*maldade), nivel_maldade(maldade), max_speed(250.f), dt_movimento(0), dt_mudar_direcao(0)
            {
            }

            Inimigo::~Inimigo(){
                nivel_maldade = -1;
            }
            
            void Inimigo::executar(){
            }
            const bool Inimigo::getChefao() const{
                return isChefao;
            }
            void Inimigo::mover(){
                float velAntiga = getVelX();
                float velAtual = 0;
                dt_movimento += Jogo::getDt();
                if(dt_movimento > dt_mudar_direcao){
                    int new_direction = (rand() % 3) - 1;
                    velAtual = max_speed*new_direction;
                    setVelocidadeX(velAtual);
                    if(rand() % 100 < 10 && getVelY() == 0)
                        setVelocidadeY(-400.f);
                    dt_movimento = 0;
                    if(velAtual != 0 && velAntiga != velAtual){
                        //Atualizar lado que o personagem esta olhando
                        int larguraTextura = corpo.getTexture()->getSize().x;
                        int alturaTextura = corpo.getTexture()->getSize().y;
                        if(velAtual > 0){
                            corpo.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
                        }
                        if(velAtual < 0){
                            corpo.setTextureRect(sf::IntRect(larguraTextura, 0,-larguraTextura, alturaTextura));
                        }
                    }
                }
                Personagem::mover();
            }
            const int Inimigo::getPontos() const{
                return pontos_por_kill;
            }
            void Inimigo::salvar(std::ofstream& arquivo){

            }
            void Inimigo::aplicarVelocidadeSalva(float vx){

                setVelocidadeX(vx);
                if(vx != 0){
                    int larguraTextura = corpo.getTexture()->getSize().x;
                    int alturaTextura = corpo.getTexture()->getSize().y;
                    if(vx > 0){
                        corpo.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
                    }
                    else{
                        corpo.setTextureRect(sf::IntRect(larguraTextura, 0, -larguraTextura, alturaTextura));
                    }
                }
            }

        }
    }
}
