#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {
    namespace Entidades {
    class Projetil;
        namespace Personagens {

            class Inim_chefao : public Personagens::Inimigo {
            private:
                static int cont_chef;
                int id_chef;
                Projetil* proj_chefao;
            public:
                Inim_chefao(int vida = 20, int maldade = 3);
                ~Inim_chefao();
                void danificar(Personagem *pPers);
                void executar();
                void salvar(std::ofstream& arquivo);
                void aplicarVelocidadeSalva(float vx);
                void setProjetil(Projetil* pP);
                void restaurarProjetil(bool ativo, float x, float y, float vx, float vy, float dtExist);
                int getIdChef();
                void mover();
            };
        }
    }
}
