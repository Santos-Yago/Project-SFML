#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <SFML/Graphics.hpp>
#include "Unico/NoDeCena.h"

class Entidade : public NoDeCena
{
	sf::Vector2f m_velocidade{};
	void updateCurrent(sf::Time tempoDelta) override;

public:
	void configVelocidade(sf::Vector2f velocidade);
	void configVelocidade(float vx, float vy);
	sf::Vector2f obterVelocidade() const;
};

#endif