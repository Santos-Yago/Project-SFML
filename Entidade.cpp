#include "Entidade.h"

void Entidade::configVelocidade(sf::Vector2f velocidade)
{
	m_velocidade = velocidade;
}

void Entidade::configVelocidade(float vx, float vy)
{
	m_velocidade.x = vx;
	m_velocidade.y = vy;
}

sf::Vector2f Entidade::obterVelocidade() const
{
	return m_velocidade;
}

void Entidade::updateCurrent(sf::Time tempoDelta)
{
	//Função 'move' da classe 'sf::Transformable' indiretamente herdada por 'TranformadorCena';
	move(m_velocidade * tempoDelta.asSeconds());
}