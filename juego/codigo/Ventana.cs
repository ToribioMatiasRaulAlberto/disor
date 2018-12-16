using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace JuegoVida
{
    public partial class frmPrincipal : Form
    {
        private int margenH = 10;
        private int margenV = 10;
        
        private int filas = 210;
        private int columnas = 210;

        private int anchoCelda = 2;

        private bool[,] estado;

        delegate bool CalcularNuevoEstadoCelula(int fila, int columna);
        CalcularNuevoEstadoCelula calcularNuevoEstado;

        public frmPrincipal()
        {
            InitializeComponent();

            this.SetStyle(
            ControlStyles.DoubleBuffer |
            ControlStyles.UserPaint |
            ControlStyles.AllPaintingInWmPaint |
            ControlStyles.ResizeRedraw,
            true);

            this.UpdateStyles();

      
            SetClientSizeCore((2 * margenH) + (columnas * anchoCelda),(2 * margenV) + (filas * anchoCelda)+50);

            estado = new bool[filas, columnas];
            
            calcularNuevoEstado = calcularEstado23_3;
        }

        private bool calcularEstado23_3(int fila, int columna)
        {
            bool res = false;

            //Número de vecinos vivos
            int numVecinosVivos = contarVecinosVivos(fila, columna);

            //Copiamos el estado anterior
            res = estado[fila, columna];

            //Aplicamos reglas:

            //Una célula muerta pasa a viva si tiene 3 vecinas vivas
            if (numVecinosVivos == 3)
                res = true;

            //Si una célula no tiene 2 ó 3 vecinas muere o permanece muerta
            if (numVecinosVivos != 2 &&  numVecinosVivos != 3)
                res = false;

            return res;
        }

        private bool calcularEstado34_34(int fila, int columna)
        {
            bool res = false;

            //Número de vecinos vivos
            int numVecinosVivos = contarVecinosVivos(fila, columna);

            //Copiamos el estado anterior
            res = estado[fila, columna];

            //Aplicamos reglas:

            //Una célula muerta pasa a viva si tiene 3 o 4 vecinas vivas
            if (numVecinosVivos == 3 ||  numVecinosVivos == 4)
                res = true;


            if (numVecinosVivos != 3 &&  numVecinosVivos != 4)
                res = false;

            return res;
        }

        private bool calcularEstado1358_357(int fila, int columna)
        {
            bool res = false;

         
            int numVecinosVivos = contarVecinosVivos(fila, columna);

            res = estado[fila, columna];

            if (numVecinosVivos == 3 ||  numVecinosVivos == 5 ||  numVecinosVivos == 7)
                res = true;

            if (numVecinosVivos != 1 && numVecinosVivos != 3 &&   numVecinosVivos != 5 &&   numVecinosVivos != 8)
                res = false;

            return res;
        }

        private int contarVecinosVivos(int fila, int columna)
        {
            int res = 0;
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                    if (i != 0 || j != 0)
                        if (estado[(filas + fila + i)%filas, (columnas + columna + j)%columnas] == true)
                            res++;

            return res;
        }

        private void inicializarAleatorio()
        {
            Random rand = new Random((int)DateTime.Now.Ticks);

            for (int i = 0; i < filas; i++)
                for (int j = 0; j < columnas; j++)
                    estado[i, j] = (rand.Next(0, 100) >= 90);
        }

        private void frmPrincipal_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    Rectangle rect = 
                        new Rectangle(margenH + (anchoCelda * j),
                                      margenV + 10 + (anchoCelda * i),
                                      anchoCelda,
                                      anchoCelda);

                    g.DrawRectangle(Pens.Gray, rect);

                    if (estado[i, j])
                    {
                        g.FillRectangle(Brushes.Black, rect);
                    }
                }
            }
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            bool[,] estadoAux = new bool[filas, columnas];

            backgroundWorker1.ReportProgress(0);

            Thread.Sleep(1000);

            while (true)
            {
                for (int i = 0; i < filas; i++)
                {
                    for (int j = 0; j < columnas; j++)
                    {
                        estadoAux[i, j] = calcularNuevoEstado(i, j);
                    }
                }

                estado = (bool[,])estadoAux.Clone();

                backgroundWorker1.ReportProgress(0);

                Thread.Sleep(50);
            }
        }

        private void backgroundWorker1_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            Refresh();
        }

        private void acercaDeToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FrmAcerca frm = new FrmAcerca();
            frm.ShowDialog();
        }

     

        private void button1_Click(object sender, EventArgs e)
        {
            inicializarAleatorio();
            backgroundWorker1.RunWorkerAsync();
        }
    }
}
