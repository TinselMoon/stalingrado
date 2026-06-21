#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../Gerenciadores/Gerenciador_grafico.hpp"
#include "../Ente.hpp"

#include "../Defines.hpp"

namespace Stalingrado {
    namespace Graficos {

        class Texto : public Ente {
        private:
            std::string info;
            sf::Text text;

        public:
            Texto(sf::Vector2f position = sf::Vector2f(0, 0), std::string info = "", const char* path = FONT_PATH);
            ~Texto();
            void setTextInfo(std::string info);
            void setPosition(sf::Vector2f position);
            void setTextColor(const unsigned int R, const unsigned int G, const unsigned int B);
            void setFontSize(const unsigned int size);
            sf::Vector2f getSize() const;
            void executar();
            std::string getInfo() const;
            sf::Vector2f getPosition() const;
        };

    }
}
