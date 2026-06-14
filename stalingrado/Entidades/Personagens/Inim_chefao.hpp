#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            class Inim_chefao : public Personagens::Inimigo {
                //
            public:
                Inim_chefao(int vida, int maldade);
                ~Inim_chefao();
                void danificar(Personagem *pPers);
                void executar();
                void salvar();
                void mover();
            };
        }
    }
}