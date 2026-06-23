#pragma once

//Inicialmente deveria ter implementado o Padrão de Projeto State completo, mas não deu tempo. Ainda assim, usei algumas ideias --Gustavo
//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace States {

        //os principais 'estados' q o jogo pode estar
        enum stateID {
            menuInicial=0,
            faseUm=1,
            faseDois=2,
            ranking=3,
            indefinido=-1
        };


        class State {

        protected:
            stateID id;

        public:
            State(stateID id=indefinido);
            virtual ~State();
            stateID getID() const;
            virtual void update(const float dt) = 0;
            virtual void resetState() = 0;
            virtual void desenharState() = 0;
        };

    }
}
