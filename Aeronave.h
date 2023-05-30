#ifndef AERONAVE_H
#define AERONAVE_H
#include "Entidade.h"
#include "Unico/RecID.h"

class Aeronave : public Entidade
{
public: 
	enum class Tipo
	{
		Eagle,
		Raptor,
	};

	explicit Aeronave(Tipo tipo, const RecTex& texturas);

private:
	virtual void m_drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const;
	Tipo m_tipoAero{};
	sf::Sprite m_spriteNave{};

};

#endif