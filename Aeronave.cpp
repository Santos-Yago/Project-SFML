#include "Aeronave.h"
#include "Recursador.h"

//Função sem assinatura declarada na interface da classe;
Texturas::ID idTextura(Aeronave::Tipo tipo)
{
	switch (tipo)
	{
	case Aeronave::Tipo::Eagle:
		return Texturas::ID::Eagle;
	case Aeronave::Tipo::Raptor:
		return Texturas::ID::Raptor;
	}
	return Texturas::ID::Eagle;
}

Aeronave::Aeronave(Tipo tipo, const RecTex& texturas):
	m_tipoAero{tipo}, m_spriteNave{texturas.obter(idTextura(tipo))}
{
	//Configurar a origem do objeto para suas tranformações na tela
	sf::FloatRect limites{ m_spriteNave.getLocalBounds() };
	m_spriteNave.setOrigin(limites.width / 2.f, limites.height / 2.f);
}

void Aeronave::m_drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	alvo.draw(m_spriteNave, estado);
}