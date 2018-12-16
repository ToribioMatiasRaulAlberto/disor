#pragma once
#include <iostream>
using namespace std;

static string abc = "abcdefghijklmñnopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

int getPos(char caracter)
{

	for (int i = 0; i < abc.length(); i++)
	{
		if (caracter == abc[i])
		{
			return i;
		}
	}
	return -1;
}

string Cifrar(string mensaje, int desplazamiento)
{

	string cifrado = "";
	if ((desplazamiento >= 0) && (desplazamiento < abc.length()))
	{
		for (int i = 0; i < mensaje.length(); i++)
		{
			int posCaracter = getPos(mensaje[i]);//mensaje[i]);//getPos(mensaje[i]);
			if (posCaracter != -1)
			{
				int pos = posCaracter + desplazamiento;
				while (pos >= abc.length())
				{
					pos = pos - abc.length();
				}
				cifrado += abc[pos];
			}
			else
			{
				cifrado += mensaje[i];
			}
		}

	}
	return cifrado;
}

 string descifrar(string mensaje, int desplazamiento)
{
	string cifrado = "";
	if (desplazamiento >= 0 && desplazamiento<abc.length())
	{
		for (int i = 0; i<mensaje.length(); i++)
		{
			int posCaracter = getPos(mensaje[i]);
			if (posCaracter != -1)
			{
				int pos = posCaracter - desplazamiento;
				while (pos< 0)
				{
					pos = pos + abc.length();
				}
				cifrado += abc[pos];
			}
			else
			{
				cifrado += mensaje[i];
			}
		}

	}
	return cifrado;
}

