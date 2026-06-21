//==============================
//==============================
//---TODAS AS MACROS DO JOGO----
//==============================
//==============================

#pragma once

// ============================================================
// Jogador.cpp
// ============================================================
#define VEL_JOG 1.0f //Velocidade do Jogador
#define PODER_JOG1 4 //Quantidade de dano que o Jogador 1 pode infligir nos inimigos
#define PODER_JOG2 2 //Quantidade de dano que o Jogador 2 pode infligir nos inimigos

#define TEXTURA_ATAQUE_JOG1 "SoldadoAtaca"
#define TEXTURA_ATAQUE_JOG2 "CachorroAtaca"

// ============================================================
// Texto.hpp
// ============================================================
#define FONT_PATH "./assets/font.ttf"

// ============================================================
// Jogo.cpp
// ============================================================
#define VIDA_JOG1 10
#define VIDA_JOG2 5

// ============================================================
// fase.cpp
// ============================================================

#define VIDA_MEDIOS 10
#define MALDADE_MEDIOS 2

// ============================================================
// Fase_prim.cpp
// ============================================================

#define VIDA_FACEIS 5
#define MALDADE_FACEIS 1

// ============================================================
// Fase_prim.cpp
// ============================================================

#define VIDA_CHEFAO 40
#define MALDADE_CHEFAO 5

// ============================================================
// Inim_chefao.cpp
// ============================================================
// Offset do bico do canhao em relacao ao centro do sprite do tanque, calculado a
// partir do pixel da ponta do cano em tanque.png e da escala registrada em texturas.txt.

#define GUN_OFFSET_X -369.3f
#define GUN_OFFSET_Y -77.6f

// ============================================================
// Personagem.cpp
// ============================================================
#define MAX_VIDAS 100
#define DURACAO_FLASH_DANO 0.15f

// ============================================================
// MenuInicial.cpp
// ============================================================
#define POS_BOTAO_0 sf::Vector2f(310, 90)
#define POS_BOTAO_1 sf::Vector2f(310, 240)
#define POS_BOTAO_2 sf::Vector2f(310, 390)
#define POS_BOTAO_3 sf::Vector2f(310, 540)
#define POS_BOTAO_4 sf::Vector2f(310, 690)
#define POS_BOTAO_5 sf::Vector2f(310, 840)
#define POS_BOTAO_6 sf::Vector2f(310, 990)

// ============================================================
// Gerenciador_colisoes.cpp
// ============================================================
#define MARGEM_ATAQUE 180.0f

// ============================================================
// Texto.cpp
// ============================================================
#define TEXT_SIZE 24

// ============================================================
// Botao.cpp
// ============================================================
#define BUTTON_TEXTURE_IDLE "BotaoIdle"
#define BUTTON_TEXTURE_HOVER "BotaoHover"
#define BUTTON_TEXT_COLOR 230, 200, 130 // R, G, B
#define FONT_SIZE 20
#define BUTTON_SCALE_X 0.45f
#define BUTTON_SCALE_Y 0.30f

// ============================================================
// MenuPausa.cpp
// ============================================================
#define POS_BOTAO_PAUSA_0 sf::Vector2f(960, 400)
#define POS_BOTAO_PAUSA_1 sf::Vector2f(960, 600)

// ============================================================
// MenuGameOver.cpp
// ============================================================
#define MAX_TAM_NOME 14

// ============================================================
// MenuRanking.cpp
// ============================================================
#define POS_BOTAO_RANKING_VOLTAR sf::Vector2f(960, 950)
#define POS_TEXTO_RANKING_TITULO sf::Vector2f(800.f, 80.f)
#define POS_TEXTO_RANKING_INICIAL sf::Vector2f(700.f, 220.f)
#define ESPACAMENTO_RANKING 60.f
#define MAX_ENTRADAS_RANKING 10

// ============================================================
// Jogo.cpp / fase.cpp (preservacao de arquivos)
// ============================================================
#define SAVE_PATH "../stalingrado/Saves/save.txt"
#define RANKING_PATH "../stalingrado/Saves/ranking.txt"
