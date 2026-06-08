#include "Jogo.hpp"
#include "Fases/Fase_prim.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Stalingrado{
Jogo::Jogo() : GG(), mJogo(this), fase_um(NULL), clock(), tempoDecorrido(){
    //AQUI NA CONSTRUTORA EU FAÇO O SET DA INSTANCIA DO GERENCIADOR GRAFICO PARA TODOS OS ENTES
    Ente::setGG(&GG);
    pJog1 = new Entidades::Personagens::Jogador(10);
    fase_um = new Fases::Fase_prim(pJog1);

    GG.setAlvoCamera(static_cast<Stalingrado::Ente*>(pJog1));
}

float Jogo::dt(0);

Jogo::~Jogo(){
    delete fase_um;
    delete pJog1;
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
        GG.atualizarCamera();
        GG.getJanela()->display();
    }   //IMPLEMENTAR
}
}
