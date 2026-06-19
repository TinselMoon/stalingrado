#include "MenuInicial.hpp"
#include "../States/Jogo.hpp"

#define POS_BOTAO_0 sf::Vector2f(100, 600)
#define POS_BOTAO_1 sf::Vector2f(100, 500)
#define POS_BOTAO_2 sf::Vector2f(100, 400)
#define POS_BOTAO_3 sf::Vector2f(100, 300)


namespace Stalingrado {
    namespace Menus {
        using namespace States;
        using namespace Graficos;

        MenuInicial::MenuInicial(Jogo* pJ) : Menu(), pJogo(pJ), State(static_cast<StateMachine*>(pJ), stateID::menuInicial) {

            Botao* bt = nullptr;

            //BOTAO 0: JOGAR FASE 1
            bt = new Botao(POS_BOTAO_0, "JOGAR FASE 1"); bt->select(true);
            botoes.push_back(bt);

            //BOTAO 1: JOGAR FASE 2
            bt = new Botao(POS_BOTAO_1, "JOGAR FASE 2");
            botoes.push_back(bt);

            //BOTAO 2: VER RANKING
            bt = new Botao(POS_BOTAO_2, "VER RANKING");
            botoes.push_back(bt);

            //BOTAO 3: SAIR DO JOGO
            bt = new Botao(POS_BOTAO_3, "SAIR DO JOGO");
            botoes.push_back(bt);
        }

        MenuInicial::~MenuInicial() {
            //deletar td
        }

        void MenuInicial::executar() {

            for (it = botoes.begin(); it != botoes.end(); ++it)
                (*it)->executar();

            if (getInMenu()) {

                switch (selected) {

                    case 0:
                        setInMenu(false);
                        changeState(faseUm);
                        break;

                    case 1:
                        setInMenu(false);
                        changeState(faseDois);
                        break;

                    case 2:
                        changeState(ranking);
                        break;

                    case 3:
                        setInMenu(false);
                        pJogo->fecharJogo();
                        break;

                    default:
                        break;

                }
            }
        }

        void MenuInicial::resetState() {
            botoes[selected]->select(false);
            selected = 0;
            botoes[selected]->select(true);
        }

    }
}