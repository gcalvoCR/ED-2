using System;
using System.Threading;

namespace Tarea6
{

    // Se realizarán varios ejercicios en clase con el tema de HILOS, esos se deben subir aquí en forma personal.

    // Realizar la ejecución de tres hilos en memoria
    // Realizar la simulación del contador adelante y atrás
    // Realizar la simulación de la carrera de la liebre y la tortuga (opcional)
    class Program
    {

        static void Main(string[] args)
        {
            // Comenzar programa
            Console.WriteLine("Aca comienza el hilo principal");

            // Creacion de hilos y un metodo detras de cada uno  
            Thread hilo1 = new Thread(new ThreadStart(Trabajar));
            Thread hilo2 = new Thread(new ThreadStart(Cantar));
            Thread hilo3 = new Thread(new ThreadStart(ContarPasos));
            
            // Iniciar hilos  
            hilo1.Start();
            hilo2.Start();
            hilo3.Start();

            // Terminar programa 
            Console.WriteLine("Aca termina el hilo principal");
            Console.ReadKey();
        }

        public static void Trabajar()
        {
            Console.WriteLine("Voy a comenzar a trabajar!");
            for (int i = 1; i < 4; i++) 
            {
                Thread.Sleep(1000);
                Console.WriteLine($"Trabajo {i+1} terminado");
                
            }
            Console.WriteLine("Trabajos terminados.");
        }
        public static void Cantar()
        {
            Console.WriteLine("Que empiece el karaoke!");
            for (int i = 0; i < 20; i++)
            {
                Thread.Sleep(500);
                Console.WriteLine("Hey!!Hoo!");
            }
            Console.WriteLine("Que buena cantada, gracias!");
        }

        public static void ContarPasos()
        {
            Console.WriteLine("Vamos a contar 10 pasos!");
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(800);
                Console.WriteLine($"Paso {i+1}");
            }
            Console.WriteLine("Listo, 10 pasos contados!");
        }

    }
}
