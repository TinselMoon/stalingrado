#pragma once
#include <list>
#include "../Ente.hpp"

/*A implementação das classes no namespace 'Menus' foram inspiradas
naquelas dos ex-monitores Giovane Limas Salvi e Matheus Augusto Burda*/

namespace Stalingrado {
    class Jogo;
    namespace Menus {
        using namespace std;
        class Botao;

        class Menu : public Ente {
        private:
            Jogo* pJogo;
            int pos;
            bool inMenu;
            bool apertou;
            bool theselect;
            sf::Vector2i pos_mouse;
            sf::Vector2f mouse_coord;
            vector<const char*> opcoes;
            vector<sf::Vector2f> coords;
            vector<sf::Text> textos;
            vector<size_t> sizes;

        protected:
            list<Botao*> listaBotao;
            list<Botao*>::iterator it;
            const sf::Vector2f tamanhoBotao;
            const sf::Vector2f tamanhoJanela; //sera obtido a partir de getRenderWindow size
            sf::Text tituloJogo;
            const unsigned short int tamanhoTitulo;
            bool mouseAbove;

            
        public:
            Menu(Jogo* pJ, const sf::Vector2f tamBotao, const unsigned short int tamTitulo, const string& nome);
            virtual ~Menu();
            void addBotao(const string info, const sf::Vector2f pos);

            //----OBSERVER
            void optAbove();
            void optBelow();
            //------------
            const int getChosenButton_ID();
            const bool getMouseAbove() const;
            void executar();
            void set_inMenu(bool noMenu);
            void processarEvento(const sf::Event& e);
        };

    }
}