#include "Menu.hpp"
#include "../Jogo.hpp"

namespace Stalingrado {
    namespace Menus {
        Menu::Menu(Jogo *pJ, const sf::Vector2f tamBotao, const unsigned short int tamTitulo, const string& nome) :
        Ente(), pJogo(pJ), tamanhoBotao(tamBotao), tamanhoTitulo(tamTitulo), mouseAbove(false), tamanhoJanela((pGG->getJanela()->getSize()))
        {
        }

        Menu::~Menu() {

        }

        const int Menu::getChosenButton_ID() {

        }

        const bool Menu::getMouseAbove() const {
            return mouseAbove;
        }

        void Menu::addBotao(const string info, const sf::Vector2f pos) {

        }

        void Menu::executar() {

        }

        void Menu::desenhar() {

        }

        void Menu::optAbove() {

        }

        void Menu::optBelow() {

        }

        void Menu::processarEvento(const sf::Event &e) {

        }

        void Menu::set_inMenu(bool noMenu) {
            //testeeeee
        }
    }
}