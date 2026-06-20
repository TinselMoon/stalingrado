#include "Botao.hpp"

#define BUTTON_TEXTURE_IDLE "BotaoIdle"
#define BUTTON_TEXTURE_HOVER "BotaoHover"
#define BUTTON_TEXT_COLOR 230, 200, 130 // R, G, B
#define FONT_SIZE 30
#define BUTTON_SCALE 0.55f

namespace Stalingrado {
    namespace Graficos {

        Botao::Botao(sf::Vector2f position, std::string info) : Ente(BUTTON_TEXTURE_IDLE),
        textInfo(position, info), defaultTexture(nullptr), selectedTexture(nullptr)
        {
            defaultTexture = &(pGG->getTextura(BUTTON_TEXTURE_IDLE));
            selectedTexture = &(pGG->getTextura(BUTTON_TEXTURE_HOVER));

            sf::Vector2u tamanhoTextura = corpo.getTexture()->getSize();
            corpo.setOrigin(tamanhoTextura.x / 2.f, tamanhoTextura.y / 2.f);

            corpo.setPosition(sf::Vector2f(position.x, position.y));
            corpo.scale(BUTTON_SCALE, BUTTON_SCALE);

            textInfo.setFontSize(FONT_SIZE);

            textInfo.setTextColor(BUTTON_TEXT_COLOR);

            sf::Vector2f textSize = textInfo.getSize();
            textInfo.setPosition(sf::Vector2f(position.x - textSize.x / 2.f, position.y - textSize.y / 2.f));
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
            textInfo.executar();
        }

    }
}