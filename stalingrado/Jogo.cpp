#include "Jogo.hpp"
#include "Fases/Fase_prim.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include <cstdlib>
#include <ctime>

#define VIDA_JOG1 10
#define VIDA_JOG2 5

namespace Stalingrado{
Jogo::Jogo() : GG(), mJogo(NULL), pJog1(NULL), pJog2(NULL), fase_um(NULL), fase_seg(NULL), clock(), tempoDecorrido(){

    std::srand(static_cast<unsigned int>(std::time(0)));
    //AQUI NA CONSTRUTORA EU FAÇO O SET DA INSTANCIA DO GERENCIADOR GRAFICO PARA TODOS OS ENTES
    Ente::setGG(&GG);
    mJogo = Menu::getInstancia(this);
    pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1);
    pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2);
    fase_seg = new Fases::Fase_seg(pJog1, pJog2);
    fase_um = new Fases::Fase_prim(pJog1, pJog2);
    // if (FASE 2 ACIONADA) fase_dois = new Fases::Fase_prim(pJog1, pJog2);

    GG.setAlvoCamera(static_cast<Stalingrado::Ente*>(pJog1));
}

float Jogo::dt(0);

Jogo::~Jogo(){
    if (fase_um!=NULL) delete fase_um;
    if (pJog1!=NULL) delete pJog1;
    if (pJog2!=NULL) delete pJog2;
}

float Jogo::getDt(){
    return dt;
}

void Jogo::executar(){
    clock.restart();
    while (GG.getJanela()->isOpen()) { //loop 'infinito' para so fechar janela qnd apertar esc ou clicar no x
        sf::Event evento;
        while (GG.getJanela()->pollEvent(evento)) {
            if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                GG.getJanela()->close();
            }
        }
        tempoDecorrido = clock.restart();
        dt = tempoDecorrido.asSeconds();

        GG.getJanela()->clear();

        fase_um->executar();
        //fase_seg->executar();
        GG.atualizarCamera();
        GG.getJanela()->display();
    }   //IMPLEMENTAR
}
}
