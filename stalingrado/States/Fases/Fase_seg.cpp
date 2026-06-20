#include "Fase_seg.hpp"
#include "../../Entidades/Entidade.hpp"
#include "../../Entidades/Personagens/Inim_medio.hpp"
#include "../../Entidades/Personagens/Inim_chefao.hpp"
#include "../../Entidades/Personagens/Jogador.hpp"
#include "../../Entidades/Chao.hpp"
#include "../../Entidades/Projetil.hpp"
#include "../../Entidades/Obstaculos/Explosivo.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

#include "../../Defines.txt"

using namespace std;

namespace Stalingrado {
    namespace Fases {

        Fase_seg::Fase_seg(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) :
        Fase(pJogador1, pJogador2, "Cenario_fase_dois", "Chao_fase_dois"), maxInimChefoesAleatorios(3), maxExplosivosAleatorios(5)
        {
            //Aqui eu devo criar a fase, configurar a posição de cada inimigo, jogador e obstáculo
            comprimentoFase = 10000;
            criarCenario();
            criarInimigos();
            //Inclui os jogadores na fase
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador1));
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador2));
            if (pJogador1) pJogador1->movePos(300.0f, 500.0f);
            if (pJogador2) pJogador2->movePos(350.0f, 500.0f);
        }

        Fase_seg::~Fase_seg(){
            if (pJog1 != nullptr) {
                lista_ents.remover(static_cast<Entidades::Entidade*>(pJog1));
            }
            if (pJog2 != nullptr) {
                lista_ents.remover(static_cast<Entidades::Entidade*>(pJog2));
            }
        }

        void Fase_seg::criarExplosivos(float x, float y){

            Entidades::Obstaculos::Explosivo *pEntidade = new Entidades::Obstaculos::Explosivo();
            GC.incluirObstaculo(pEntidade);
            pEntidade->movePos(x, y);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
        }

        void Fase_seg::criarChefoes(float x, float y) {

            Entidades::Personagens::Inim_chefao *pEntidade = new Entidades::Personagens::Inim_chefao(VIDA_CHEFAO, MALDADE_CHEFAO);
            GC.incluirInimigo(pEntidade);
            pEntidade->movePos(x, y);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));

            Entidades::Projetil *pProjetil = new Entidades::Projetil();
            GC.incluirProjetil(pProjetil);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pProjetil));
            pEntidade->setProjetil(pProjetil);
        }
        
        void Fase_seg::criarInimigos(){
            const char* caminhoArquivo = "../stalingrado/assets/fase2/Inimigos.txt";
            try{
                std::ifstream arquivo(caminhoArquivo);

                if(!arquivo.is_open()){
                    string erro = "Não foi possível abrir o arquivo";
                    erro.append(caminhoArquivo);
                    throw runtime_error(erro);
                }
                int cont_inim_medios = 0;
                int cont_inim_chefoes = 0;
                std::string classe;
                int tipo;
                float x;
                float y;

                // Personagem, pos x, pos y
                // A posição x que será passada será a borda esquerda limite para geração de posição aleatoria do personagem
                while (arquivo >> tipo >> classe >> x >> y) {
                    if (classe == "INIM_MEDIO") {
                        if(tipo == 1){
                            criarInimMedios(x, y);
                        }
                        else{
                            if(cont_inim_medios == maxInimMediosAleatorios)
                                cout << "Máximo de inimigos médios atingido, ignorando os próximos" << endl;
                            else if(rand() % 2){
                                criarInimMedios(x, y);
                                cont_inim_medios++;
                            }
                        }
                    }
                    else if (classe == "INIM_CHEFAO") {
                        if(tipo == 1){
                            criarChefoes(x, y);
                        }
                        else{
                            if (cont_inim_chefoes == maxInimChefoesAleatorios)
                                cout << "Máximo de inimigos do classe chefão atingido, ignorando os próximos" << endl;
                            else if(rand() % 2){
                                criarChefoes(x, y);
                                cont_inim_chefoes++;
                            }
                        }
                    }
                }
                arquivo.close();
            }
            catch(const std::exception& erro){
                std::cerr << "Erro: " << erro.what() << std::endl;
            }
        }
        void Fase_seg::criarObstaculos(){
            const char* caminhoArquivo = "../stalingrado/assets/fase2/Obstaculos.txt";
            try{
                std::ifstream arquivo(caminhoArquivo);

                if(!arquivo.is_open()){
                    string erro = "Não foi possível abrir o arquivo ";
                    erro.append(caminhoArquivo);
                    throw runtime_error(erro);
                }
                int cont_entulhos = 0;
                int cont_explosivos = 0;
                int tipo;
                std::string classe;
                float x;
                float y;

                // Obstaculo, pos x min, pos x maxima
                // As posições x min e x maxima delimitam o espaço em que será gerado aleatoriamente o entulho
                while (arquivo >> tipo >> classe >> x >> y) {
                    if (classe == "ENTULHO") {
                        if(tipo == 1){
                            criarPlataformas(x, y);
                        }
                        else if(rand() % 2){
                            if(cont_entulhos == maxEntulhosAleatorios){
                                cout << "Máximo de entulhos atingido, ignorando os próximos" << endl;
                            }
                            else{
                                criarPlataformas(x, y);
                                cont_entulhos++;
                            }
                        }
                    }
                    else if (classe == "EXPLOSIVO") {
                        if(tipo == 1){
                            criarExplosivos(x, y);
                        }
                        else if(rand() % 2){
                            if (cont_explosivos == maxExplosivosAleatorios)
                                cout << "Maximo de explosivos atingido, ignorando os proximos" << endl;
                            else {
                                criarExplosivos(x, y);
                                cont_explosivos++;
                            }
                        }
                    }
                }
                arquivo.close();
            }
            catch(const std::exception& erro){
                std::cerr << "Erro: " << erro.what() << std::endl;
            }

        }

        void Fase_seg::criarCenario(){
            //aqui cria o chao e posiciona ele
            chao = new Entidades::Chao(comprimentoFase, "Chao_fase_dois");
            chao->setPosicao(0.f, 750.f);
            GC.setChao(chao);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));

            //aqui configura o fundo
            corpo.setPosition(0.f, 0.f);
            corpo.setTextureRect(sf::IntRect(0, 0, comprimentoFase, 882));
            criarObstaculos();
            GC.tratarColisoesObsObs();
        }

        void Fase_seg::executar(){
            lista_ents.percorrer();
            GC.executar();
            desenhar();
            lista_ents.desenhar();
            pGG->desenharTextoCoordAbs("Fase 2:\t Rattenkrieg\t", 50, 100.f, 100.f);
            std::stringstream vida1, vida2;
            vida1 << "Vida \tJogador \t1:\t " << pJog1->getVida() << "\t PONTOS:\t" << pJog1->getPontos();
            pGG->desenharTextoCamera(vida1.str(), 20, 50.f, 10.f);
            if(pJog2 != nullptr){
                vida2 << "Vida \tJogador \t2:\t " << pJog2->getVida() << "\t PONTOS:\t" << pJog2->getPontos();
                pGG->desenharTextoCamera(vida2.str(), 20, 50.f, 50.f);
            }
        }

    }
}
