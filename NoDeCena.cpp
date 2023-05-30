#include "NoDeCena.h"

//Remover na versão release
#include <cassert>
//-------------------------

NoDeCena::NoDeCena(): m_principal{nullptr}, m_secundario{}
{

}

void NoDeCena::alocarSecundario(Ptr secundario)
{
	secundario->m_principal = this;
	m_secundario.push_back(std::move(secundario));
}

NoDeCena::Ptr NoDeCena::desalocarSecundario(const NoDeCena& nos)
{
	auto encontrar{ std::find_if(m_secundario.begin(), m_secundario.end(),
		[&](Ptr& p) {return p.get() == &nos; }) };

	//O conteiner não pode estar vazio
	//Remover na versão 'release'.
	assert(encontrar != m_secundario.end());

	Ptr resultado{ std::move(*encontrar) };
	resultado->m_principal = nullptr;
	m_secundario.erase(encontrar);
	return resultado;
}

void NoDeCena::drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	//Não faz nada por padrão;
}

void NoDeCena::desenharSecundario(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	for (const Ptr& sec : m_secundario)
		sec->draw(alvo, estado);
}

void NoDeCena::draw(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	//Aplica a tranformação no estado atual
	estado.transform *= getTransform();

	//Desenha o 'estado' e o 'secundario' com tranformações alteradas
	drawCurrent(alvo, estado);
	desenharSecundario(alvo, estado);
}

void NoDeCena::update(sf::Time tempoDelta)
{
	updateCurrent(tempoDelta);

	for (const Ptr& x : m_secundario)
		x->update(tempoDelta);
}

void NoDeCena::updateCurrent(sf::Time tempoDelta)
{
	//Não faz nada por padrão;
}

void NoDeCena::atualizarSecundario(sf::Time tempoDelta)
{
	for (Ptr& sec : m_secundario)
		sec->update(tempoDelta);
}

//Função para obter referencia da posição absoluta do jogo;
sf::Transform NoDeCena::obterMundoTranformado() const
{
	sf::Transform transforme{ sf::Transform::Identity };
	for (const NoDeCena* no{ this }; no != nullptr; no = no->m_principal)
	{
		//				  VVVVVVV--- Função herdada de sf::Tranformable;
		transforme = no->getTransform() * transforme;
	}

	return transforme;
}

// Posição absoluta do mundo do jogo;
sf::Vector2f NoDeCena::obterPontoDoMundo() const
{
	return obterMundoTranformado() * sf::Vector2f();
}

/*void TransformadorCena::m_atualizarSecundario(sf::Time deltaTempo)
{
	for (const Ptr& x : m_secundario)
		x->update(deltaTempo);
}*/