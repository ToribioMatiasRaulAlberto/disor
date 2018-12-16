using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cifrado_cesar
{
    class Cesar
    {
        static string abc = "abcdefghijklmñnopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
        public string Cifrar(string mensaje, int desplazamiento)
        {

            String cifrado = "";
            if (desplazamiento >= 0 && desplazamiento < abc.Length)
            {
                for (int i = 0; i < mensaje.Length; i++)
                {
                    int posCaracter = getPos(mensaje[i]);
                    if (posCaracter != -1) 
                    {
                        int pos = posCaracter + desplazamiento;
                        while (pos >= abc.Length)
                        {
                            pos = pos - abc.Length;
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

        public string descifrar(string mensaje, int desplazamiento)
         {
             String cifrado = "";
             if (desplazamiento >= 0 && desplazamiento<abc.Length)
             {                
                 for (int i = 0; i<mensaje.Length; i++)
                 {
                     int posCaracter = getPos(mensaje[i]);
                     if (posCaracter != -1) 
                     {
                         int pos = posCaracter - desplazamiento;
                         while ( pos< 0 )
                         {
                             pos = pos + abc.Length;                            
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

        int getPos(char caracter)
        {
            for (int i = 0; i < abc.Length; i++)
            {
                if (caracter == abc[i])
                {
                    return i;
                }
            }
            return -1;
        }
    }
}
