using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace cifrado_cesar
{
    public partial class Form1 : Form
    {
        Cesar cs = new Cesar();
        public Form1()
        {
            InitializeComponent();
        }

        private void cifrar_TextChanged(object sender, EventArgs e)
        {
            cifrarCesar();
            inversa();
            transposicion_inversa_desplazamiento();
        }

        public void transposicion_inversa_desplazamiento()
        {
            string ms = cifrar.Text;
            string desplaza = numericUpDown1.Value.ToString();
            int despw = Int32.Parse(desplaza);
            string x = "";
            string cifraTID= invertir_en_grupos(ms, despw, x);
            richTextBox2.Text = cifraTID;
        }

        private void inversa()
        {
            string  s=cifrar.Text;
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            richTextBox1.Text=new string(charArray);;
        }


        public string invertir_en_grupos(string mensaje, int elementos_en_elgrupo, string nuevo_mensaje)
        {
            int inicio_grupo = 0;

            if (elementos_en_elgrupo < 1)
                return mensaje;

            for (int i = 0; i < mensaje.Length; i++)
            {
                if ((i + 1) % elementos_en_elgrupo == 0)
                {
                    nuevo_mensaje = nuevo_mensaje.Substring(0, inicio_grupo);
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

        private string reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
        private string mover(string mensaje, int inicio, int fin, string mensajenuevo)
        {
            for (int i = inicio; i < fin; i++)
            {
                mensajenuevo += mensaje[i];
            }
             string msj=reverse(mensajenuevo);
            return msj;
        }

        private void cifrarCesar()
        {
            string desplazamient = num.Value.ToString();
            int desp = Int32.Parse(desplazamient);
            string msj = cifrar.Text;
            string x = cs.Cifrar(msj, desp);
            richTextBox.Text = x;
        }
        private void descifrarCesar()
        {
            string desplazamient = num.Value.ToString();
            int desp = Int32.Parse(desplazamient);
            string msj = richTextBox.Text;
            string x = cs.descifrar(msj, desp);
            cifrar.Text = x;
        }
        private void despl_KeyDown(object sender, KeyEventArgs e)
        {
        }

        private void cifrado_TextChanged(object sender, EventArgs e)
        {
            descifrarCesar();
        }
        private void num_ValueChanged(object sender, EventArgs e)
        {
            cifrarCesar();
        }
        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            transposicion_inversa_desplazamiento();
        }
    }
}
