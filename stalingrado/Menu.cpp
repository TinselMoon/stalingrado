#include "Menu.hpp"
#include "Jogo.hpp"

namespace Stalingrado {

    Menu::Menu(Jogo* pJ) : Ente("Menu"), pJogo(pJ), inMenu(true) {
    }

    Menu::~Menu() {
    }

    void Menu::executar() {
        if (inMenu)
            desenhar();
    }

    void Menu::set_inMenu(bool noMenu) {
        inMenu = noMenu;
    }

    void Menu::processarEvento(const sf::Event& e) {
        if (e.type != sf::Event::KeyPressed)
            return;

        switch (e.key.code) {
            case sf::Keyboard::Num1:
            case sf::Keyboard::Numpad1:
                pJogo->iniciarFase1();
                break;

            case sf::Keyboard::Num2:
            case sf::Keyboard::Numpad2:
                pJogo->iniciarFase2();
                break;

            case sf::Keyboard::Escape:
                pJogo->fecharJogo();
                break;

            default:
                break;
        }
    }
}