#include "fase.hpp"
#include "../Entidades/Personagens/Inim_medio.hpp"
#include <string>
using namespace std;
namespace Stalingrado {

namespace Fases{

//INICIO CLASSE ABSTRATA FASE
Fase::Fase(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2, const std::string& nomeTextura) :
Ente(nomeTextura), GC(pJogador1, pJogador2), lista_ents(), maxInimMedios(5), comprimentoFase(0){
    pJog1 = pJogador1;
    pJog2 = pJogador2;
}

Fase::~Fase(){

}
/*
void Fase::carregarFase(const char* caminhoArquivo) {
    try{
        std::ifstream arquivo(caminhoArquivo);
        
        if(!arquivo.is_open()){
            string erro = "Não foi possível abrir o arquivo ";
            erro.append(caminhoArquivo);
            throw runtime_error(erro);
        }

        std::string tipo;
        float x;
        float y;

        // Personagem, pos x, pos y
        while (arquivo >> tipo >> x >> y) {
            if (tipo == "INIM_FACIL") {
                
            }
            else if (tipo == "INIM_MEDIO") {

            }
            else if (tipo == "OBS_ARAME") {

            }
        }

        arquivo.close();
    }
    catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
*/
void Fase::criarInimMedios(float x, float y){
    Entidades::Personagens::Inim_medio *pEntidade = new Entidades::Personagens::Inim_medio(10, 2);
    GC.incluirInimigo(pEntidade);
    pEntidade->movePos(x, y);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
}

void Fase::criarPlataformas(){

}

}

} // Fim do namespace Stalingrado
