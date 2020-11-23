using System;
using System.Collections.Generic;
using System.Text;

namespace ProyectoED2
{
    public class Arco
    {
        public int distancia { get; set; }
        public int tiempo { get; set; }
        public int costo { get; set; }

        public Arco()
        {
            distancia = 1000000;
            tiempo = 1000000;
            costo = 1000000;
        }

        public string ToString => $"dist: {distancia}, tiempo: {tiempo}h, costo: {costo}USD";

    }
}
