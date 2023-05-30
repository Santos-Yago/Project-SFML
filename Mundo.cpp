#include "Mundo.h"

Mundo::Mundo(sf::RenderWindow& janela) :m_janela{ janela },
m_visaoMundo{ janela.getDefaultView() },
m_texturas{}, m_cenaGraficos{}, m_rotCenas{},
m_mundoBordas{
	0.f,						// esquerda, posição X
	0.f,						// cima, posição Y
	m_visaoMundo.getSize().x,	// Largura;
	2000.f						// Altura;
}, m_posicaoSpawn{
	m_visaoMundo.getSize().x / 2.f,
	m_mundoBordas.height - m_visaoMundo.getSize().y/2.f
}, m_naveJogador{ nullptr }, m_velocidadeRolagem{}
{
	m_carregarTexturas();
	m_criarCena();

	m_visaoMundo.setCenter(m_posicaoSpawn);
}

void Mundo::m_carregarTexturas()
{
	m_texturas.carregar(Texturas::ID::Eagle, "E:/Texturas/Eagle.png");
	m_texturas.carregar(Texturas::ID::Raptor, "E:/Texturas/Raptor.png");
	m_texturas.carregar(Texturas::ID::Deserto, "E:/Texturas/Desert.png");
}

void Mundo::m_criarCena()
{
	for (std::size_t i{0}; i < RotTotais; ++i)
	{
		NoDeCena::Ptr rotulo{new NoDeCena()};
		m_rotCenas[i] = rotulo.get();

		m_cenaGraficos.alocarSecundario(std::move(rotulo));
	}

	//Configura a repetição do sprite de fundo. Cria uma textura retangular usando
	//a conversão recebida de 'm_mundoBordas'
	sf::Texture& textura{m_texturas.obter(Texturas::ID::Deserto)};
	sf::IntRect texRetangulo{m_mundoBordas};
	textura.setRepeated(true);

	//link para textura Desert. Garantir que o sprite cubra toda a cena
	std::unique_ptr<SpriteCena> spriteDeFundo{new SpriteCena(textura, texRetangulo)};
	spriteDeFundo->setPosition(m_mundoBordas.left, m_mundoBordas.top);
	m_rotCenas[Fundo]->alocarSecundario(std::move(spriteDeFundo));

	//Criar a aeronave lider, o jogador.
	std::unique_ptr<Aeronave> lider{new Aeronave(Aeronave::Tipo::Eagle, m_texturas)};
	m_naveJogador = lider.get();
	m_naveJogador->setPosition(m_posicaoSpawn);
	m_naveJogador->configVelocidade(50.f, m_velocidadeRolagem);
	m_rotCenas[Ar]->alocarSecundario(std::move(lider));

	//Escoltas do líder - Esquerda
	std::unique_ptr<Aeronave> escoltaEsquerda{new Aeronave(Aeronave::Tipo::Raptor, m_texturas)};
	escoltaEsquerda->setPosition(-80.f, 50.f);
	m_naveJogador->alocarSecundario(std::move(escoltaEsquerda));

	//Escolta do líder - Direita
	std::unique_ptr<Aeronave> escoltaDireita{new Aeronave(Aeronave::Tipo::Raptor, m_texturas)};
	escoltaDireita->setPosition(80.f, 50.f);
	m_naveJogador->alocarSecundario(std::move(escoltaDireita));
}

//Desenha as configurações na janela em tempo real e encarrega o trabalho para SceneGraph
void Mundo::desenhar()
{
	m_janela.setView(m_visaoMundo);
	m_janela.draw(m_cenaGraficos);
}

//A função abaixo controla a rolagem do mundo e sua movimentação
void Mundo::atualizar(sf::Time deltaTempo)
{
	//A visão é rolada de acordo com o tempo passado
	m_visaoMundo.move(0.f, m_velocidadeRolagem * deltaTempo.asSeconds());

	//Checamos a aproximação da borda
	sf::Vector2f posicionamento{m_naveJogador->obterPontoDoMundo()};
	sf::Vector2f velocidade{m_naveJogador->obterVelocidade()};
	if (posicionamento.x <= m_mundoBordas.left + 150.f ||
		posicionamento.x >= m_mundoBordas.left + m_mundoBordas.width - 150.f)
	{
		velocidade.x = -velocidade.x;
		m_naveJogador->configVelocidade(velocidade);
	}

	m_cenaGraficos.update(deltaTempo);
}