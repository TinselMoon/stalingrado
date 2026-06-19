#include "Personagem.hpp"
#include "../../States/Jogo.hpp"
#include "Jogador.hpp"

#define MAX_VIDAS 100

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Personagem::Personagem(int vida, const std::string& nomeTextura) :
            Entidade(nomeTextura), num_vidas(vida)
            {
                sf::FloatRect rectangle = corpo.getLocalBounds();
                corpo.setOrigin(rectangle.width/2.f, rectangle.height/2.f);
                vel_x = vel_y = 0.f;
                ativo = true;
            }

            void Personagem::setMorto(){
                ativo = false;
            }
            Personagem::~Personagem(){
                num_vidas = -1;
            }
            void Personagem::salvarDataBuffer(){

            }

            void Personagem::operator-=(int dano) {
                num_vidas - dano >= 0 ? num_vidas-=dano : num_vidas=0;
            }

            void Personagem::operator+=(int bonus) {
                num_vidas+=bonus;
            }

            float Personagem::getVelX(){
                return vel_x;
            }
            float Personagem::getVelY(){
                return vel_y;
            }

            int Personagem::getVida(){
                return num_vidas;
            }

            sf::Vector2f Personagem::getPos(){
                return corpo.getPosition();
            }

            void Personagem::movePos(float x, float y){
                corpo.move(x, y);
            }

            void Personagem::setVelocidadeX(float vx){
                vel_x = vx;
            }
            void Personagem::setVelocidadeY(float vy){
                vel_y = vy;
            }

            void Personagem::eliminar(Jogador *pJ){
                if(pJ != NULL){
                    int checkpointsAntigos = pJ->getUltimoCheckpoint() / 100;
                    int checkpointsNovos = pJ->getPontos() / 100;

                    if(checkpointsNovos > checkpointsAntigos){
                        *pJ += checkpointsNovos;
                        pJ->setUltimoCheckpoint(pJ->getPontos());
                    }
                }
                ativo = false;
                corpo.setPosition(-1000.f, -1000.f);
            }
            void Personagem::mover(){
                float dx = 0, dy = 0, dt = 0;
                dt = States::Jogo::getDt();
                setVelocidadeY(getVelY() + 1200.f*dt);
                dx = getVelX()*dt;
                dy = getVelY()*dt;
                corpo.move(dx, dy);
            }

        }
    }
}
