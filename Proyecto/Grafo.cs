using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Proyecto
{
    public class Grafo
    {
        //Atributos
        public Arco[][] matriz { get; set; }
        string[] referencia { get; set; }

        //Constructor
        public Grafo() 
        {
            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    var aux = new Arco();
                    matriz[i][j] = aux;
                }
            }
        }

        public bool insertarArco(int fila, int columna, Arco arco) 
        {
            matriz[fila][columna] = arco;
            return true;
        }

        public bool insertarVertice(int posicion, string ciudad)
        {
            if (buscarCiudad(ciudad) == -1)
            {
                referencia[posicion] = ciudad;
                return true;
            }
            return false;

        }

        public int buscarCiudad(string ciudad)
        {
            for (int i = 0; i < 25; i++)
            {
                if (referencia[i] == ciudad)
                {
                    return i;
                }
            }
            return -1;
        }

        public string buscarDatoArco(int fila, int columna)
        {
            return matriz[fila][columna].ToString();
        }

        public string mostrarCiudades()
        {
            var s = "";
            for (int i = 0; i < 25; i++)
            {
                s+= $"ciudad {i}: {referencia[i]}";
            }
            return s;
        }

        public string mostrarArcos()
        {
            var s = "";

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    s += $"{i} --> {matriz[i][j].ToString()}";

                }
            }
            return s;
        }


    }
}
