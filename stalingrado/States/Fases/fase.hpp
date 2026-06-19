#pragma once
#include "../../Ente.hpp"
#include "../../Gerenciadores/Gerenciador_grafico.hpp"
#include "../../Gerenciadores/Gerenciador_colisoes.hpp"
#include "../../Listas/Lista_entidades.hpp"
#include "../../Entidades/Chao.hpp"

namespace Stalingrado {
    //AQUI VAMOS FAZER UMA DECLARAÇÃO ANTECIPADA DAS CLASSES USADAS NAS FASES
    namespace Entidades{
        namespace Personagens{
            class Jogador;
            class Inimigo;
        }
    }

    namespace Fases {

        class Fase : public Ente {
        protected:
            const int maxInimMediosAleatorios;
            int comprimentoFase;

            bool fase_concluida;
            Entidades::Chao* chao;
            Listas::ListaEntidades lista_ents;
            Gerenciadores::Gerenciador_Colisoes GC;
            Entidades::Personagens::Jogador *pJog1;
            Entidades::Personagens::Jogador *pJog2;

            //void carregarFase(const char* caminhoArquivo);
            virtual void criarInimigos() = 0;
            virtual void criarObstaculos() = 0;
            virtual void criarCenario() = 0;
            void criarInimMedios(float x, float y);
            void criarPlataformas(float x, float y); // As plataformas são os entulhos
        public:
            Fase(Entidades::Personagens::Jogador *pJogador1 = nullptr, Entidades::Personagens::Jogador *pJogador2 = nullptr, const std::string& texturaFundo = nullptr, const std::string& texturaChao = nullptr);
            ~Fase();
            virtual void executar() = 0;
            const bool inimigosMortos() const;
            const bool faseConcluida() const;
        };

    }
}
