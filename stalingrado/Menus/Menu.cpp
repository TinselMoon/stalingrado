#include "Menu.hpp"
#include "../Gerenciadores/Gerenciador_grafico.hpp"

namespace Stalingrado {
    namespace Menus {

        Menu::Menu() : Ente(), inMenu(true) {
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
            max = 3;
        }

        bool Menu::getInMenu() {
            return inMenu;
        }

        void Menu::setInMenu(bool iM) {
            inMenu = iM;
        }

        void Menu::executar() {
            desenhar();
        }
    }
}