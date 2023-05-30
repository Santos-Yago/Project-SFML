#ifndef REC_ID_H
#define REC_ID_H
#include "C:/Users/YAGO/source/repos/projeto de jogo/Recursador.h"
#include <SFML/Graphics.hpp>

namespace Texturas
{
	enum class ID
	{
		Eagle,
		Raptor,
		Desert,
	};
}



typedef Recursador<sf::Texture, Texturas::ID> RecTex;

#endif 