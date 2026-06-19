#include "Botao.hpp"

#define BUTTON_PATH_DEFAULT "./assets/Botao/Selected_light.png"
#define BUTTON_PATH_SELECTED "./assets/Botao/Selected.png"
#define BUTTON_HEIGHT 80
#define BUTTON_WIDTH 300
#define BUTTON_TEXT_COLOR 77.6, 68.2, 44.3 // R, G, B
#define FONT_SIZE 30

namespace Stalingrado {
    namespace Graficos {

        Botao::Botao(sf::Vector2f position, std::string info) : Ente("Botao"),
        textInfo(position, info),defaultTexture(nullptr), selectedTexture(nullptr)
        {
            defaultTexture = &(pGG->getTextura(BUTTON_PATH_DEFAULT));
            selectedTexture = &(pGG->getTextura(BUTTON_PATH_SELECTED));

            corpo.setOrigin(sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2));

            corpo.setPosition(sf::Vector2f(position.x, position.y));

            corpo.setTexture(*defaultTexture);

            textInfo.setFontSize(FONT_SIZE);

            textInfo.setTextColor(BUTTON_TEXT_COLOR);

            textInfo.setPosition(sf::Vector2f(position.x, position.y));
        }

        Botao::~Botao() { }

        void Botao::select(const bool isSelected) {
            if (isSelected)
                corpo.setTexture(*selectedTexture);
            else
                corpo.setTexture(*defaultTexture);
        }

        void Botao::executar() {
            desenhar();
        }

    }
}