#ifndef RECURSOS_TEXTURA_H
#define RECURSOS_TEXTURA_H
#include <SFML/Graphics.hpp>
#include <map>

namespace Texturas
{
	enum class ID
	{
		paisagem,
		aviao,
		missil
	};
}

class TexturaRecursos
{
	std::map<Texturas::ID, std::unique_ptr<sf::Texture>> m_texturaMapa{};

public:
	void carregar(Texturas::ID id, const std::string& nomeArquivo);
	sf::Texture& obter(Texturas::ID id);
	const sf::Texture& obter(Texturas::ID id) const;
};

#endif