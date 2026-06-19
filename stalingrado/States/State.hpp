#pragma once
#include <cstddef>

namespace Stalingrado {
    namespace States {

        class StateMachine;

        enum stateID {
            menuInicial=0,
            faseUm=1,
            faseDois=2,
            ranking=3,
            indefinido=-1
        };

        class State {

        protected:
            StateMachine* pSM;
            stateID id;

        public:
            State(StateMachine* pSM = nullptr, stateID id=indefinido);
            virtual ~State();
            void setStateMachine(StateMachine* pSM);
            void changeState(stateID id);
            stateID getID() const;
            virtual void update(const float dt) = 0;
            virtual void resetState() = 0;
            virtual void desenharState() = 0;
        };

    }
}
