#include "Texto.hpp"

#include "../Defines.hpp"

namespace Stalingrado {
    namespace Graficos {

        //Gerenciadores::Gerenciador_Grafico* Texto::pGG = Gerenciadores::Graphics::getInstance();

        Texto::Texto(sf::Vector2f position, std::string info, const char* path) : Ente(), info(info) {
            text.setString(info);

            text.setFont(pGG->getFont());

            text.setCharacterSize(TEXT_SIZE);

            text.setPosition(sf::Vector2f(position.x, position.y));

            text.setFillColor(sf::Color::White);
        }

        Texto::~Texto() { }

        void Texto::setTextInfo(std::string info) {
            this->info = info;
            text.setString(this->info);
        }

        void Texto::setPosition(sf::Vector2f position) {
            text.setPosition(sf::Vector2f(position.x, position.y));
        }

        void Texto::setTextColor(const unsigned int R, const unsigned int G, const unsigned int B) {
            text.setFillColor(sf::Color(R, G, B));
        }

        void Texto::setFontSize(const unsigned int size) {
            text.setCharacterSize(size);
        }

        sf::Vector2f Texto::getSize() const {
            sf::FloatRect textRect = text.getLocalBounds();
            return sf::Vector2f(textRect.width, textRect.height);
        }

        void Texto::executar() {
            getGG()->desenharTexto(text);
        }

        std::string Texto::getInfo() const {
            return info;
        }

        sf::Vector2f Texto::getPosition() const {
            return sf::Vector2f(text.getPosition().x, text.getPosition().y);
        }

    } // namespace GraphicalElements
}
