#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {
    namespace Entidades {
    class Projetil;
        namespace Personagens {

            class Inim_chefao : public Personagens::Inimigo {
            private: 
                //
                static int cont_chef;
                int id_chef;
                Projetil* proj_chefao;
            public:
                Inim_chefao(int vida, int maldade);
                ~Inim_chefao();
                void danificar(Personagem *pPers);
                void executar();
                void salvar();
                void mover();
                void setProjetil(Projetil* pP);
                int getIdChef();
            };
        }
    }
}
