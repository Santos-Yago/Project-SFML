#ifndef JOGO_H
#define JOGO_H
#include <SFML/Graphics.hpp>

// Obs.: 27*05*2023
#include "Unico/Mundo.h"
// --------------------

class Jogo : private sf::NonCopyable
{
	void m_processarEvento();
	void m_update(sf::Time delta);
	void m_renderizar();
	void m_tratarEntradaDoJogador(sf::Keyboard::Key tecla, bool toque);
	void m_gerarEstatistica(sf::Time tempoPassado);

	bool m_moverCima{};
	bool m_moverBaixo{};
	bool m_moverEsquerda{};
	bool m_moverDireita{};

	//Objeto mundo criado;
	Mundo m_mundo;

	sf::RenderWindow m_janela{};
	//sf::Sprite m_jogador{};
	//sf::Texture m_textura{};

	//Strings de tela sobre taxa de atualização
	std::size_t m_estatisticaNumFrames{};
	sf::Font m_font{};
	sf::Text m_estatisticaTexto{};
	sf::Time m_estatisticaAtualizacaoTempo{};

	//static const float m_velocidadeDoJogador;

	//Para mudar a velocidade de movimentação do jogo, deve se ir na 
	//função 'm_atualiza' e modificar os valores de movimento de cada
	//direção.
	static const sf::Time m_framePorSegundo;


public:
	Jogo();
	void rodar();
};

#endif
