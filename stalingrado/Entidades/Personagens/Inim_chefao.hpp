#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {
    namespace Entidades {
    class Projetil;
        namespace Personagens {

            class Inim_chefao : public Inimigo {
            private: 
                //
                static int cont_chef;
                int id_chef;
                Projetil* proj_chefao;
            public:
                Inim_chefao(int vida = 20, int maldade = 5);
                ~Inim_chefao();
                void danificar(Personagem *pPers);
                void executar();
                void salvar(std::ofstream& arquivo);
                void setProjetil(Projetil* pP);
                int getIdChef();
                void mover();
            };
        }
    }
}
