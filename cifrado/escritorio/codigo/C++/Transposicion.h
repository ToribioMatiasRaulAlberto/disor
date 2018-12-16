#pragma once
#include <iostream>
using namespace std;

string invertir(string cadena)
{
	string aux_cadena = "";

	for (int i = cadena.length()-1; i >= 0; i--)
	{
		aux_cadena += cadena[i];
	}
		

	return aux_cadena;
}

string mover(string mensaje, int inicio, int fin, string mensajenuevo)
{
	for (int i = inicio; i < fin; i++)
	{
		mensajenuevo += mensaje[i];
	}
	string msj = invertir(mensajenuevo);
	return msj;
}

string invertir_en_grupos(string mensaje, int elementos_en_elgrupo, string nuevo_mensaje)
{
	int inicio_grupo = 0;

	if (elementos_en_elgrupo < 1)
		return mensaje;

	for (int i = 0; i < mensaje.length(); i++)
	{
		if ((i + 1) % elementos_en_elgrupo == 0)
		{
			nuevo_mensaje = nuevo_mensaje.substr(0, inicio_grupo);
			nuevo_mensaje += mover(mensaje, inicio_grupo, i + 1, "");
			inicio_grupo += elementos_en_elgrupo;
		}
		else
		{
			nuevo_mensaje += mensaje[i];
		}
	}
	return nuevo_mensaje;
}


