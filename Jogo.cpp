#include "Jogo.h"
#include "TextoAuxiliar.h"
#include <exception>

//const float Jogo::m_velocidadeDoJogador{200.f};
const sf::Time Jogo::m_framePorSegundo{ sf::seconds(1.f / 60.f) };

//Colocando o 'm_mundo' no inicializador de lista;
//Construtor mundo presente na inicialização de lista//-------VVVVVV
Jogo::Jogo() :m_janela{ sf::VideoMode(640, 320), "Navinha"}, m_mundo{m_janela},
m_font{}, m_estatisticaTexto{}, m_estatisticaAtualizacaoTempo{},
m_estatisticaNumFrames{0}
{
	//Carrega a imagem de uma nave com um tamanho de 48 x 64 pixels;
	/*if (!m_textura.loadFromFile("E:/Texturas/Eagle.png"))
	{
		throw std::runtime_error("Falha ao carregar textura");
	}*/

	//m_jogador.setTexture(m_textura);
	//m_jogador.setPosition(320.f, 160.f);

	//Carrega um arquivo do tipo fonte(texto);
	m_font.loadFromFile("E:/SFML-Gbook/01_Intro/Media/sansation.ttf");
	m_estatisticaTexto.setFont(m_font);
	m_estatisticaTexto.setPosition(5.f, 5.f);
	m_estatisticaTexto.setCharacterSize(10);
}

void Jogo::rodar()
{
	sf::Clock relogio;
	//Guarda o tempo passado por quadro renderizado pela função update
	sf::Time tempoPassadoPorUpdate{ sf::Time::Zero };

	while (m_janela.isOpen())
	{
		sf::Time tempoPassado{ relogio.restart() };
		tempoPassadoPorUpdate += tempoPassado;
		while (tempoPassadoPorUpdate > m_framePorSegundo)
		{
			tempoPassadoPorUpdate -= m_framePorSegundo;
			m_processarEvento();
			m_update(m_framePorSegundo);
		}
		m_gerarEstatistica(tempoPassado);
		m_renderizar();
	}
}

void Jogo::m_tratarEntradaDoJogador(sf::Keyboard::Key tecla, bool toque)
{/*
	if (tecla == sf::Keyboard::W)
		m_moverCima = toque;
	else if (tecla == sf::Keyboard::A)
		m_moverDireita = toque;
	else if (tecla == sf::Keyboard::S)
		m_moverBaixo = toque;
	else if (tecla == sf::Keyboard::D)
		m_moverEsquerda = toque;*/
}

//Captura de input da janela;
void Jogo::m_processarEvento()
{
	sf::Event evento;
	while (m_janela.pollEvent(evento))
	{
		switch (evento.type)
		{
		case sf::Event::KeyPressed:
			m_tratarEntradaDoJogador(evento.key.code, true);
			break;

		case sf::Event::KeyReleased:
			m_tratarEntradaDoJogador(evento.key.code, false);
			break;

		case sf::Event::Closed:
			m_janela.close();
			break;
		}
	}
}

void Jogo::m_update(sf::Time delta)
{
	//Mundo chamando função;
	m_mundo.atualizar(delta);

	//O objeto responsável pela movimentação do elemento;
	/*sf::Vector2f movimento(0.f, 0.f);
	if (m_moverCima)
		movimento.y -= m_velocidadeDoJogador;
	if (m_moverBaixo)
		movimento.y += m_velocidadeDoJogador;
	if (m_moverDireita)
		movimento.x -= m_velocidadeDoJogador;
	if (m_moverEsquerda)
		movimento.x += m_velocidadeDoJogador;*/

	//Mundo chamando função;
	//m_mundo.atualizar(delta);

	//m_jogador.move(movimento * delta.asSeconds());
}

//Contador de frame e estatísticas de desempenho;
void Jogo::m_gerarEstatistica(sf::Time tempoPassado)
{
	m_estatisticaAtualizacaoTempo += tempoPassado;
	m_estatisticaNumFrames += 1;

	if (m_estatisticaAtualizacaoTempo >= sf::seconds(1.0f))
	{
		m_estatisticaTexto.setString(
			"Quadros por segundo : " + paraString(m_estatisticaNumFrames) + '\n' +
			"Latência : " + paraString(m_estatisticaAtualizacaoTempo.asMicroseconds() / m_estatisticaNumFrames) + " mcs");
		m_estatisticaAtualizacaoTempo -= sf::seconds(1.0f);
		m_estatisticaNumFrames = 0;
	}
}

//Desenhar na janela o que se quer mostrar na tela;
void Jogo::m_renderizar()
{
	//Garante a tela limpa antes de desenhar na tela
	m_janela.clear();

	//Desenhando o mundo;***Não esta desenhando***
	m_mundo.desenhar();

	//Desenha o jogador
	//m_janela.draw(m_jogador);

	m_janela.setView(m_janela.getDefaultView());
	m_janela.draw(m_estatisticaTexto);

	//Indica que terminamos de desenhar e que deve ser renderizado imediatamente;
	m_janela.display();
}