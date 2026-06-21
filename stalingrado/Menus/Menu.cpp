#include "Menu.hpp"
#include "../Gerenciadores/Gerenciador_grafico.hpp"

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace Menus {

        Menu::Menu(const string& nomeText, States::Jogo* pJ) : Ente(nomeText), inMenu(true), pJogo(pJ) {
            setValuesBotoes();
        }

        Menu::~Menu() {

            Graficos::Botao* bt = nullptr;
            while (!botoes.empty()) {

                bt = botoes.back();
                if (bt != nullptr) delete bt;
                botoes.pop_back();
            }

            botoes.clear();
        }

        void Menu::selectUp() {

            if (inMenu) {
                botoes[selected]->select(false);
                selected--;
                if (selected < min)
                    selected = max;
                botoes[selected]->select(true);
            }
        }

        void Menu::selectDown() {
            if (inMenu) {
                botoes[selected]->select(false);
                selected++;
                if (selected > max)
                    selected = min;
                botoes[selected]->select(true);
            }
        }

        void Menu::setValuesBotoes () {
            selected = 0;
            min = 0;
            max = botoes.empty() ? 0 : static_cast<int>(botoes.size()) - 1;
        }

        bool Menu::getInMenu() {
            return inMenu;
        }

        void Menu::setInMenu(bool iM) {
            inMenu = iM;
        }

    }
}