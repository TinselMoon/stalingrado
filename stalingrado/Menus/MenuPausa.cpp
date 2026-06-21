#include "MenuPausa.hpp"
#include "../States/Jogo.hpp"

#include "../Defines.hpp"

namespace Stalingrado {
    namespace Menus {
        using namespace Graficos;

        MenuPausa::MenuPausa(States::Jogo* pJ) : Menu("Menu"), pJogo(pJ) {
            resetMenu();
        }

        MenuPausa::~MenuPausa() { }

        bool MenuPausa::getTwoPlayers() const {
            return false;
        }

        void MenuPausa::executar() {

            desenhar();

            for (it = botoes.begin(); it != botoes.end(); ++it)
                (*it)->executar();
        }

        void MenuPausa::confirmar() {

            if (getInMenu()) {

                switch (selected) {

                    case 0:
                        setInMenu(false);
                        pJogo->retomarJogo();
                        break;

                    case 1:
                        setInMenu(false);
                        pJogo->sairFaseAtual();
                        break;

                    default:
                        break;

                }
            }
        }

        void MenuPausa::carregarBotoes() {

            Botao* bt = nullptr;

            while (!botoes.empty()) {
                bt = botoes.back();
                if (bt != nullptr) delete bt;
                botoes.pop_back();
            }

            //BOTAO 0: CONTINUAR
            bt = new Botao(POS_BOTAO_PAUSA_0, "CONTINUAR"); bt->select(true);
            botoes.push_back(bt);

            //BOTAO 1: SAIR PARA O MENU
            bt = new Botao(POS_BOTAO_PAUSA_1, "SAIR  PARA  O  MENU");
            botoes.push_back(bt);
        }

        void MenuPausa::resetMenu() {
            carregarBotoes();
            setValuesBotoes();
            setInMenu(true);
        }

    }
}
