#include "Personagem.hpp"
#include "../../Jogo.hpp"

#define MAX_VIDAS 100

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Personagem::Personagem(int vida, int nMaldade, const std::string& nomeTextura) :
            num_vidas(vida), nivel_maldade (nMaldade), Entidades::Entidade(nomeTextura)
            {
                sf::FloatRect rectangle = personagem.getLocalBounds();
                personagem.setOrigin(rectangle.width/2.f, rectangle.height/2.f);
                vel_x = vel_y = 0.f;
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
                num_vidas + bonus <= MAX_VIDAS ? num_vidas+=bonus : num_vidas = MAX_VIDAS;
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
                return personagem.getPosition();
            }

            void Personagem::movePos(float x, float y){
                personagem.move(x, y);
            }

            void Personagem::setVelocidadeX(float vx){
                vel_x = vx;
            }
            void Personagem::setVelocidadeY(float vy){
                vel_y = vy;
            }

            void Personagem::mover(){
                float dx = 0, dy = 0, dt = 0;
                dt = Jogo::getDt();
                setVelocidadeY(getVelY() + 1200.f*dt);
                dx = getVelX()*dt;
                dy = getVelY()*dt;
                personagem.move(dx, dy);
            }

        }
    }
}
