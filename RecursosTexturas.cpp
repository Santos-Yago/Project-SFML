#include "RecursosTexturas.h"

//REMOVER DO CÓDIGO, NA VERSÃO RELEASE;
#include <cassert>


//Criamos uma função para carregar o arquivo de texturas e checagem de sucesso.
void TexturaRecursos::carregar(Texturas::ID id, const std::string& nomeArquivo)
{
	//Propriedade única;
	std::unique_ptr<sf::Texture> textura{ new sf::Texture()};
	if (!textura->loadFromFile(nomeArquivo))
	{
		throw std::runtime_error("Falha ao carregar arquivo" + nomeArquivo);
	}

	//	  \/\/\/ :: Remover na versão release 'inserido';
	auto inserido = m_texturaMapa.insert(std::make_pair(id, std::move(textura)));

	//REMOVER ESSE TRECHO DO CÓDIGO NA VERSÃO RELEASE;
	assert(inserido.second);
}

//Criamos uma função que retorna a Textura desejada;
sf::Texture& TexturaRecursos::obter(Texturas::ID id)
{
	auto encontrar{ m_texturaMapa.find(id) };

	//Remover esse trecho do códio na versão release:
	assert(encontrar != m_texturaMapa.end());

	return *encontrar->second;
}

//Criamos uma função que retorna a Textura desejada;
const sf::Texture& TexturaRecursos::obter(Texturas::ID id) const
{
	auto encontrar{ m_texturaMapa.find(id) };

	//Remover esse trecho do códio na versão release:
	assert(encontrar != m_texturaMapa.end());

	return *encontrar->second;
}