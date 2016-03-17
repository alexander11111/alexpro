using KSort.Generator;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace KSort
{
    class Program
    {
        static DateTime dt;
        static void Main(string[] args)
        {
            String srcFile =  @"billing.dat";
            String dstFile = @"billing_out.dat";
            long lines = 5 * 1000000;
            //Generator
            EntityGen enGen = new EntityGen(srcFile, lines);
            enGen.Start();

            //Time
            dt = DateTime.Now;
            Console.WriteLine("(0 sec.)Start Sort of {0} lines ", lines);
            
            //Sorter
            //KWSorter sorter = new KWSorter(srcFile, dstFile, 100, new FirstListSorter(), new MiddleSetSorter()); //42 sec/1000000; 231 sec/5000000
            //KWSorter sorter = new KWSorter(srcFile, dstFile, 100, new FirstSetSorter(), new MiddleSetSorter()); //39 sec/1000000; 270 sec/5000000
            //KWSorter sorter = new KWSorter(srcFile, dstFile, 100, new FirstPQSorter(), new MiddleSetSorter()); //56 sec/1000000; 340 sec/5000000
            KWSorter sorter = new KWSorter(srcFile, dstFile, 100, new FirstPQKeySorter(), new MiddleSetSorter());//60 sec/1000000; 350 sec/5000000

            sorter.SProcess = Process;
            sorter.Sort();

            Console.WriteLine("End Of Sort");
            Console.ReadLine();
        }
        static void Process(double proc)
        {
            double dtNewTime = (DateTime.Now-dt).TotalSeconds;
            double dtEllaps = (100.0 - proc) * dtNewTime / proc;
            Console.WriteLine("({0:F1} sec.)Sorted ~{1:F3}% . Ellapsed Time: {2:F1} sec", dtNewTime, proc, dtEllaps);
        }

    }
}
