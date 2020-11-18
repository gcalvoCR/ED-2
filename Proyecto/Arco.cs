using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Proyecto
{
    public class Arco
    {
        public int distancia { get; set; }
        public int tiempo { get; set; }
        public int costo { get; set; }

        public Arco()
        {
            distancia = 0;
            tiempo = 0;
            costo = 0;
        }
    }
}
