using System;
using System.Collections.Generic;
using System.Text;

namespace ProyectoED2
{
    public class Grafo
    {
        public Arco[,] matrizAdyacencia { get; set; }
        string[] referenciaUbicacion { get; set; }

        public Grafo()
        {
            matrizAdyacencia = new Arco[Informacion.tam, Informacion.tam];
            referenciaUbicacion = new string[Informacion.tam];
            for (int i = 0; i < Informacion.tam; i++)
            {
                for (int j = 0; j < Informacion.tam; j++)
                {
                    var aux = new Arco();
                    matrizAdyacencia[i, j] = aux;
                }
            }
        }

        public bool InsertarArco(int fila, int columna, Arco arco)
        {
            matrizAdyacencia[fila, columna] = arco;
            return true;
        }

        public bool InsertarVertice(int pposicion, string pubicacion)
        {
            if (BuscarUbicacion(pubicacion) == -1)
            {
                referenciaUbicacion[pposicion] = pubicacion;
                return true;
            }
            return false;

        }

        public int BuscarUbicacion(string pubicacion)
        {
            for (int i = 0; i < Informacion.tam; i++)
            {
                if (referenciaUbicacion[i] == pubicacion)
                {
                    return i;
                }
            }
            return -1;
        }

        public string BuscarDatoArco(int fila, int columna)
        {
            return matrizAdyacencia[fila, columna].ToString;
        }

        public string MostrarUbicaciones()
        {
            var s = "";
            for (int i = 0; i < Informacion.tam; i++)
            {
                s += $"{i+1}- {referenciaUbicacion[i]} \n";
            }
            return s;
        }

        public string MostrarArcos()
        {
            var s = "";

            for (int i = 0; i < Informacion.tam; i++)
            {
                for (int j = 0; j < Informacion.tam; j++)
                {
                    if (matrizAdyacencia[i, j].distancia < Informacion.DISTANCIA_MAX) 
                    {
                        s += $"({i}) {referenciaUbicacion[i]} - ({j}) {referenciaUbicacion[j]}  \t({matrizAdyacencia[i, j].ToString})\n";
                    }
                }
            }
            return s;
        }


        public string MostrarUbicacionesAdyacentes(string pubicacion)
        {
            string ubicacion = "";

            for (int row = 0; row < Informacion.tam; row++)
            {
                for (int column = 0; column < Informacion.tam; column++)
                {
                    if ((referenciaUbicacion[row] == pubicacion
                            || referenciaUbicacion[column] == pubicacion)
                            && matrizAdyacencia[row, column].distancia != Informacion.DISTANCIA_MAX)
                    {
                        ubicacion += $"{referenciaUbicacion[row]} -> {referenciaUbicacion[column]}: {matrizAdyacencia[row, column].ToString}\n";
                    }
                }
            }

            if (ubicacion.Length == 0) 
            {
                ubicacion = "No hay ubicaciones adyacentes.";
            }

            return ubicacion;
        }

        public int CostoMinimo(int[] pCosto, bool[] pSptSet)
        {
            int min = Informacion.DISTANCIA_MAX, minIndex = -1;

            for (int value = 0; value < Informacion.tam; value++)
            {
                if (pSptSet[value] == false && pCosto[value] <= min)
                {
                    min = pCosto[value];
                    minIndex = value;
                }     
            }
               
            return minIndex;
        }

        public int DistanciaMinima(int[] pDistancia, bool[] pSptSet)
        {
            int min = Informacion.DISTANCIA_MAX, minIndex = -1;

            for (int value = 0; value < Informacion.tam; value++)
            {
                if (pSptSet[value] == false && pDistancia[value] <= min)
                {
                    min = pDistancia[value];
                    minIndex = value;
                }
            }

            return minIndex;
        }

        public string recorrido(int[] pPadre, int pIndex)
        {
            string text = "";
            if (pPadre[pIndex] == -1)
                return "";

            text += recorrido(pPadre, pPadre[pIndex]);
            text += "->" + referenciaUbicacion[pIndex];
            return text;
        }

        public string imprimirRecorrido(int[] pDistancia, int[] pCosto, int[] pPadre, int pinicio, int pfinal)
        {
            var text = "";

            text += "******* Informacion Origen -> Destino *******";
            for (int destinationIndex = 0; destinationIndex < Informacion.tam; destinationIndex++)
            {
                if (destinationIndex == pfinal)
                {
                    text += $"\n{referenciaUbicacion[pinicio]} -> {referenciaUbicacion[destinationIndex]}\n";
                    text += $"Distancia: {pDistancia[destinationIndex]}km\n";
                    text += $"Costo:     {pCosto[destinationIndex]}USD\n";
                    text += $"Camino:    {referenciaUbicacion[pinicio]} {recorrido(pPadre, destinationIndex)}\n";
                }

            }
            text += "*********************************************\n";
            return text;
        }

        public string caminoMinimoUsandoDijkstra(string pInicio, string pFin)
        {
            int inicio = ObtenerIndiceDeUbicacion(pInicio);
            int fin = ObtenerIndiceDeUbicacion(pFin);
            int[] costo = new int[Informacion.tam];
            int[] distancia = new int[Informacion.tam];
            bool[] sptSet = new bool[Informacion.tam];
            int[] parent = new int[Informacion.tam];

            for (int index = 0; index < Informacion.tam; index++)
            {
                parent[index] = -1;
                distancia[index] = Informacion.DISTANCIA_MAX;
                sptSet[index] = false;
            }

            costo[inicio] = 0;
            distancia[inicio] = 0;

            for (int count = 0; count < Informacion.tam - 1; count++)
            {
                int picked = DistanciaMinima(distancia, sptSet);

                sptSet[picked] = true;

                for (int other = 0; other < Informacion.tam; other++)
                    if (!sptSet[other] 
                        && matrizAdyacencia[picked, other].costo != Informacion.DISTANCIA_MAX
                        && (distancia[picked] + matrizAdyacencia[picked, other].distancia) < distancia[other])
                    {
                        parent[other] = picked;
                        distancia[other] = distancia[picked] + matrizAdyacencia[picked, other].distancia;
                        costo[other] = costo[picked] + matrizAdyacencia[picked, other].costo;
                    }
            }

            return imprimirRecorrido(distancia, costo, parent, inicio, fin);
        }

        public int ObtenerIndiceDeUbicacion(string pubicacion)
        {

            for (int row = 0; row < Informacion.tam; row++)
            {
                if (referenciaUbicacion[row] == pubicacion)
                {
                    
                    return row;
                }
            }
            return -1;
        }
    }
}
