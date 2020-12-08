namespace ProyectoED2
{
    public class Controller
    {
        private Grafo grafo { get; set; }

        private HashTable hashTable { get; set; }

        public Controller()
        {
            grafo = new Grafo();
            hashTable = new HashTable();
        }
        public bool InsertarUbicacion(int pPosition, string pubicacion)
        {
            return grafo.InsertarVertice(pPosition, pubicacion);

        }

        public string InsertarEnMatriz(int pRow, int pColumn, int pDistancia, int pTiempo, int pCosto)
        {
            var arco = new Arco
            {
                distancia = pDistancia,
                tiempo = pTiempo,
                costo = pCosto
            };
            grafo.InsertarArco(pRow, pColumn, arco);
            return "Datos guardados";
        }


        public int BuscarUbicacion(string pUbicacion)
        {
            return grafo.BuscarUbicacion(pUbicacion);
        }

        public string BuscarArco(int pRow, int pColumn)
        {
            return grafo.BuscarDatoArco(pRow, pColumn);
        }

        public string MostrarUbicaciones()
        {
            return grafo.MostrarUbicaciones();
        }

        public string MostrarArcos()
        {
            return grafo.MostrarArcos();
        }

        public string mostrarUbicacionesAdyacentes(string pubicacion)
        {
            return grafo.MostrarUbicacionesAdyacentes(pubicacion);
        }

        public string InsertarUbicacionHashCerrado(string pubicacion)
        {
            if (hashTable.InsertarUbicacionHashCerrado(hashingString(pubicacion), pubicacion) == true)
            {
                return "¡Ubicacion registrada exitosamente!";
            }
            return "No se pudo ingresar la ubicacion.";
           
        }

        public string buscarUbicacionPorNombre(string pubicacion)
        {
            string found = hashTable.BuscarUbicacionPorNombre(hashingString(pubicacion), pubicacion);
            if (found != "")
            {
                return found;
            }
            return "No existe hay ninguna ubicacion con dicho nombre";
        }

        public int hashingString(string word)
        {
            int seed = 1;
            int hash = 0;
            for (int i = 0; i < word.Length; i++)
            {
                hash = (hash * seed) + word[i];
            }
            return hash % 23;
        }

        public string showMinimumPath(string pStartingPoint, string pEndingPoint)
        {
            return grafo.caminoMinimoUsandoDijkstra(pStartingPoint, pEndingPoint);
        }
    }
}
