using System;
using System.Collections.Generic;
using System.Text;

namespace ProyectoED2
{
    public class HashTable
    {
        public string[] ubicaciones;

        public HashTable()
        {
            ubicaciones = new string[Informacion.tam];
            for (int index = 0; index < Informacion.tam; index++)
            {
                ubicaciones[index] = "NO_DATA";
            }
        }


        public bool InsertarUbicacionHashCerrado(int pIndex, string pUbicacion)
        {
            if (BuscarUbicacionPorNombre(pIndex, pUbicacion) != "")
            {
                return false;
            }
            else
            {
                if (ubicaciones[pIndex] == "NO_DATA")
                {
                    ubicaciones[pIndex] = pUbicacion;
                }
                else
                {
                    pIndex++;
                    if (pIndex == Informacion.tam)
                    {
                        pIndex = 0;
                    }
                    InsertarUbicacionHashCerrado(pIndex, pUbicacion);
                }
                return true;
            }
        }

        public string BuscarUbicacionPorNombre(int pIndex, string pUbicacion)
        {
            var ubicacion = "";
            string obtainedSpace = ubicaciones[pIndex];
            while (obtainedSpace != "NO_DATA")
            {
                if (obtainedSpace == pUbicacion)
                {
                    ubicacion = obtainedSpace;
                }
                else
                {
                    pIndex++;
                    if (pIndex == Informacion.tam)
                    {
                        pIndex = 0;
                    }
                    ubicacion = BuscarUbicacionPorNombre(pIndex, pUbicacion);
                }
                return ubicacion;
            }
            return ubicacion;
        }

    }
}
