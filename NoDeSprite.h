#ifndef NO_DE_SPRITE_H
#define NO_DE_SPRITE_H
#include <SFML/Graphics.hpp>
#include "NoDeCena.h"


class SpriteCena: public NoDeCena
{
	virtual void drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const;
	sf::Sprite m_spriteSpriteCena{};

public:
	explicit SpriteCena(const sf::Texture& textura);
				SpriteCena(const sf::Texture& textura, const sf::IntRect& retanguloVideo);
};

#endif