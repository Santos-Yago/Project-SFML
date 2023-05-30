#include "NoDeCena.h"

//Remover na vers�o release
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

	//O conteiner n�o pode estar vazio
	//Remover na vers�o 'release'.
	assert(encontrar != m_secundario.end());

	Ptr resultado{ std::move(*encontrar) };
	resultado->m_principal = nullptr;
	m_secundario.erase(encontrar);
	return resultado;
}

void NoDeCena::drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	//N�o faz nada por padr�o;
}

void NoDeCena::desenharSecundario(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	for (const Ptr& sec : m_secundario)
		sec->draw(alvo, estado);
}

void NoDeCena::draw(sf::RenderTarget& alvo, sf::RenderStates estado) const
{
	//Aplica a tranforma��o no estado atual
	estado.transform *= getTransform();

	//Desenha o 'estado' e o 'secundario' com tranforma��es alteradas
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
	//N�o faz nada por padr�o;
}

void NoDeCena::atualizarSecundario(sf::Time tempoDelta)
{
	for (Ptr& sec : m_secundario)
		sec->update(tempoDelta);
}

//Fun��o para obter referencia da posi��o absoluta do jogo;
sf::Transform NoDeCena::obterMundoTranformado() const
{
	sf::Transform transforme{ sf::Transform::Identity };
	for (const NoDeCena* no{ this }; no != nullptr; no = no->m_principal)
	{
		//				  VVVVVVV--- Fun��o herdada de sf::Tranformable;
		transforme = no->getTransform() * transforme;
	}

	return transforme;
}

// Posi��o absoluta do mundo do jogo;
sf::Vector2f NoDeCena::obterPontoDoMundo() const
{
	return obterMundoTranformado() * sf::Vector2f();
}

/*void TransformadorCena::m_atualizarSecundario(sf::Time deltaTempo)
{
	for (const Ptr& x : m_secundario)
		x->update(deltaTempo);
}*/