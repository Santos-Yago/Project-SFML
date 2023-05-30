#ifndef TEXTOAUXILIAR_H
#define TEXTOAUXILIAR_H
#include <sstream>

template <typename T>
std::string paraString(const T& valor)
{
	std::stringstream stream;
	stream << valor;
	return stream.str();
}

#endif
