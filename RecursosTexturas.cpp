#include "RecursosTexturas.h"

//REMOVER DO C�DIGO, NA VERS�O RELEASE;
#include <cassert>


//Criamos uma fun��o para carregar o arquivo de texturas e checagem de sucesso.
void TexturaRecursos::carregar(Texturas::ID id, const std::string& nomeArquivo)
{
	//Propriedade �nica;
	std::unique_ptr<sf::Texture> textura{ new sf::Texture()};
	if (!textura->loadFromFile(nomeArquivo))
	{
		throw std::runtime_error("Falha ao carregar arquivo" + nomeArquivo);
	}

	//	  \/\/\/ :: Remover na vers�o release 'inserido';
	auto inserido = m_texturaMapa.insert(std::make_pair(id, std::move(textura)));

	//REMOVER ESSE TRECHO DO C�DIGO NA VERS�O RELEASE;
	assert(inserido.second);
}

//Criamos uma fun��o que retorna a Textura desejada;
sf::Texture& TexturaRecursos::obter(Texturas::ID id)
{
	auto encontrar{ m_texturaMapa.find(id) };

	//Remover esse trecho do c�dio na vers�o release:
	assert(encontrar != m_texturaMapa.end());

	return *encontrar->second;
}

//Criamos uma fun��o que retorna a Textura desejada;
const sf::Texture& TexturaRecursos::obter(Texturas::ID id) const
{
	auto encontrar{ m_texturaMapa.find(id) };

	//Remover esse trecho do c�dio na vers�o release:
	assert(encontrar != m_texturaMapa.end());

	return *encontrar->second;
}