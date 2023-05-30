#include "NoDeSprite.h"

SpriteCena::SpriteCena(const sf::Texture& textura) : m_spriteSpriteCena{ textura }
{

}

SpriteCena::SpriteCena(const sf::Texture& textura, const sf::IntRect& retanguloVideo) :
	m_spriteSpriteCena{ textura, retanguloVideo }
{

}

void SpriteCena::drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	alvo.draw(m_spriteSpriteCena, estado);
}