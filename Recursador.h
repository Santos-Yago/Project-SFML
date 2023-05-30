#ifndef RECURSADOR_H
#define RECURSADOR_H

#include <map>
//#include "SFML/Graphics.hpp"

#include <exception>
#include <memory>
#include <string>

//Desabilitar na versão release
#include <cassert>

template <typename Rec, typename ID>
class Recursador
{
	std::map<ID, std::unique_ptr<Rec>> m_mapaDoRecurso{};

	void inserirRecursos(ID id, std::unique_ptr<Rec> recursos)
	{
		auto inserido{ m_mapaDoRecurso.insert(std::make_pair(id, std::move(recursos))) };
		assert(inserido.second);
	}

public:
	void carregar(ID id, const std::string& nomeArquivo)
	{
		std::unique_ptr<Rec> recurso{ new Rec() };
		if (!recurso->loadFromFile(nomeArquivo))
			throw std::runtime_error("Arquivo não carregado" + nomeArquivo);;

		//Desabilitar na versão release
		inserirRecursos(id, std::move(recurso));
	}

	//Função carregada destinada ao objetos Shaders
	template <typename Seg>
	void carregar(ID id, const std::string& nomeArquivo, const Seg& segPar)
	{
		std::unique_ptr<Rec> recurso{ new Rec() };
		if (!recurso->loadFromFile(nomeArquivo, segPar))
			throw std::runtime_error("Arquivo não carregado" + nomeArquivo);

		//Desabilitar na versão release
		inserirRecursos(id, std::move(recurso));
	}

	//Obter o objeto do mapa;
	Rec& obter(ID id)
	{
		auto encontrar{ m_mapaDoRecurso.find(id) };

		//Remover esse trecho do códio na versão release:
		assert(encontrar != m_mapaDoRecurso.end());

		return *encontrar->second;
	}

	const Rec& obter(ID id) const
	{
		auto encontrar{ m_mapaDoRecurso.find(id) };

		//Remover esse trecho do códio na versão release:
		assert(encontrar != m_mapaDoRecurso.end());

		return *encontrar->second;
	}
};



#endif