using System;

namespace ProyectoED2
{
    class Program
    {

        public static Controller controller;
        static void Main(string[] args)
        {
            controller = new Controller();
            int opt;
            insertarUbicacion();
            insertarInformacionArcos();
            do
            {
                mostrarMenu();
                opt = leerOpcion();
                Console.Clear();
                ejecutarAccion(opt);

            } while (opt != 0);


        }

        public static void insertarUbicacion()
        {

            for (int i = 0; i<Informacion.lugares.Length; i++)
            {
                controller.InsertarUbicacion(i, Informacion.lugares[i]);
                controller.InsertarUbicacionHashCerrado(Informacion.lugares[i]);
            }
        }


        public static void mostrarMenu()
        {
            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("Menu de Ubicaciones de Italia");
            Console.WriteLine("----------------------------------------------");
            Console.WriteLine(" ");
            Console.WriteLine("Favor digite una opcion:");
            Console.WriteLine("1. Mostrar ubicaciones");
            Console.WriteLine("2. Mostrar caminos (arcos)");
            Console.WriteLine("3. Mostrar ubicaciones adyacentes");
            Console.WriteLine("4. Buscar una ubicacion (busqueda con Hash)");
            Console.WriteLine("5. Buscar camino minimo entre ubicaciones(Dijkstra)");
            Console.WriteLine("0. Salir");
            Console.WriteLine("----------------------------------------------");

        }

        public static int leerOpcion()
        {
            int option = 0;

            try
            {
                option = int.Parse(Console.ReadLine()); 
            }
            catch (Exception) {
                Console.WriteLine("Opcion invalida, ingrese un numero");
                Console.WriteLine();
            }

            return option;

        }

        public static void ejecutarAccion(int pOption)
        {
            switch (pOption)
            {
                case 1:
                    mostrarUbicaciones();
                    break;
                case 2:
                    mostrarArcos();
                    break;
                case 3:
                    mostrarUbicacionesAdyacentes();
                    break;
                case 4:
                    buscarUbicacionPorNombre();
                    break;
                case 5:
                    mostrarRecorridoMinimo();
                    break;
                case 0:
                    Console.WriteLine("Gracias por usar el sistema.");
                    Console.WriteLine();
                    break;
                default:
                    Console.WriteLine("Opcion invalida");
                    Console.WriteLine();
                    break;
            }
            Console.WriteLine();
            Console.WriteLine("¡Presione una tecla para continuar!");
            Console.ReadKey();
            Console.Clear();

        }

        public static void mostrarUbicaciones()
        {
            Console.WriteLine(controller.MostrarUbicaciones());
        }

        public static void insertarInformacionArcos()
        {

            for(var i = 0; i < Informacion.arcos.GetLength(0); i++) {
                controller.InsertarEnMatriz(Informacion.arcos[i,0], Informacion.arcos[i, 1], Informacion.arcos[i, 2], Informacion.arcos[i, 3], Informacion.arcos[i, 4]);
            }
             
        }

        public static void mostrarArcos()
        {
            Console.WriteLine(controller.MostrarArcos());
        }

        public static void mostrarUbicacionesAdyacentes()
        {
            Console.WriteLine("Digite el nombre de una ubicacion: ");
            var ubicacion = Console.ReadLine();
            Console.WriteLine("-------------------------------------");
            Console.WriteLine("Destinos posibles (adyacentes)");
            Console.WriteLine("-------------------------------------");
            Console.WriteLine(controller.mostrarUbicacionesAdyacentes(ubicacion));
        }

        public static void buscarUbicacionPorNombre()
        {
            Console.WriteLine("Nombre de la ubicacion a buscar: ");
            var ubicacion = Console.ReadLine();
            Console.WriteLine("-------------------------------------");
            Console.WriteLine(controller.buscarUbicacionPorNombre(ubicacion));
            Console.WriteLine("-------------------------------------");
        }

        public static void mostrarRecorridoMinimo()
        {
            Console.WriteLine("Ingrese el nombre de la ubicación inicio: ");
            var ubicacionInicial = Console.ReadLine();
            Console.WriteLine("Ingrese el nombre de la ubicación destino: ");
            var ubicacionFinal = Console.ReadLine();
            Console.WriteLine(controller.showMinimumPath(ubicacionInicial, ubicacionFinal));
        }

    }
}
