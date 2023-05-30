#ifndef NO_DE_CENA_H
#define NO_DE_CENA_H
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>

//Classe de gerenciamento das transformações dos objetos de imagem da cena;
//Herança: Renderedização na cena => Drawable; Escalonamento, translação e escala => Transformable
//Não fazer cópias => NonCopyable;
class NoDeCena: public sf::Transformable, public sf::Drawable,
	private sf::NonCopyable
{
public:
	typedef std::unique_ptr<NoDeCena> Ptr;

	NoDeCena();

	void alocarSecundario(Ptr secundario);
	Ptr desalocarSecundario(const NoDeCena& nos);

	void update(sf::Time TempoDelta);

	sf::Transform obterMundoTranformado() const;
	sf::Vector2f obterPontoDoMundo() const;

private:
	std::vector<Ptr> m_secundario{};
	NoDeCena* m_principal{};

	//Funções sem nome alterado por fazerem parte da biblioteca SFML e evitar erros.
	//Função virtual de sf::Drawable
	//final keyword para prevenir que classes derivada dessas sejam sobrecarregada.
	//Fazer reavaliação dessa função no final do projeto.
	//sf::RenderState é passado por valor
	virtual void draw(sf::RenderTarget& alvo, sf::RenderStates estado) const;
	virtual void drawCurrent(sf::RenderTarget& alvo, sf::RenderStates estado) const;
	void desenharSecundario(sf::RenderTarget& alvo, sf::RenderStates estado) const;
	
	virtual void updateCurrent(sf::Time TempoDelta);
	void atualizarSecundario(sf::Time TempoDelta);

	//Loop iterador for(T& x : x);
	//void m_atualizarSecundario(sf::Time tempoDelta);
};
#endif 
