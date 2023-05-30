#include "Jogo.h"
#include <iostream>

int main()
{
	try {
		Jogo jogo;
		jogo.rodar();
	}
	catch (std::exception& exc)
	{
		std::cerr << "\nErro: " << exc.what() << std::endl;
	}
}