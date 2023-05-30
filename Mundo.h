#ifndef MUNDO_H
#define MUNDO_H

#include <SFML/Graphics.hpp>
#include "C:/Users/YAGO/source/repos/projeto de jogo/Recursador.h"
#include "C:/Users/YAGO/source/repos/projeto de jogo/Unico/NoDeSprite.h"
#include "NoDeCena.h"
#include "C:/Users/YAGO/source/repos/projeto de jogo/Aeronave.h"
#include "IdRecursos.h"

#include <array>

class Mundo : private sf::NonCopyable
{
public:

	//Definição de um tipo de recursador para lidar com as texturas da classe Mundo;
	typedef Recursador <sf::Texture, Texturas::ID> RecTex;

	explicit Mundo(sf::RenderWindow& janela);
	void atualizar(sf::Time deltaTempo);
	void desenhar();

private:
	enum Rotulo
	{
			Fundo,
			Ar,
			RotTotais //Rótulos Totais
	};

	//Lógica de renderização;
	sf::RenderWindow& m_janela;
	sf::View m_visaoMundo{};
	RecTex m_texturas{};
	NoDeCena m_cenaGraficos{};
	std::array<NoDeCena*, RotTotais> m_rotCenas{};

	//Lógica do mundo e ponteiro para o jogador;
	sf::FloatRect m_mundoBordas{};
	sf::Vector2f m_posicaoSpawn{};
	float m_velocidadeRolagem{};
	Aeronave* m_naveJogador{};

	//Carregar recursos;
	void m_carregarTexturas();
	void m_criarCena();
};

#endif // !MUNDO_H*/
