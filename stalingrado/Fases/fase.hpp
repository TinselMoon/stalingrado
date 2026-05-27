#pragma once
#include "../Ente.hpp"
#include "../Gerenciadores/Gerenciador_grafico.hpp"
#include "../Gerenciadores/Gerenciador_colisoes.hpp"
#include "../Listas/Lista_entidades.hpp"

namespace Stalingrado {


//AQUI VAMOS FAZER UMA PRÉ DEFINIÇÃO DAS CLASSES USADAS NAS FASES
namespace Entidades{
    namespace Personagens{
        class Jogador;
        class Inimigo;
    }
}

//NAMEPSACE COM TODAS AS FASES
namespace Fases{
class Fase : public Stalingrado::Ente{
protected:
    const int maxInimMedios;
    Listas::ListaEntidades lista_ents;
    Gerenciadores::Gerenciador_Colisoes GC;
    sf::RectangleShape chao;
    virtual void criarInimigos() = 0;
    virtual void criarObstaculos() = 0;
    virtual void criarCenario() = 0;
    void criarInimMedios();
    void criarPlataformas(); // As plataformas são os entulhos
public:
    Fase();
    ~Fase();
    virtual void executar() = 0;

};

}

} // Fim do namespace Stalingrado
