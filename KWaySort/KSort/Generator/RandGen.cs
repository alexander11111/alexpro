using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KSort
{
    class RandGen
    {
        private static Random rnd = new Random();
        public string GetRandName(string name)
        {
            return String.Format("{0}{1}{2}", Convert.ToChar(rnd.Next('A', 'Z')), Convert.ToChar(rnd.Next('A', 'Z')), name);
        }
        public string GetRandFio(string name)
        {
            return String.Format("{0}{1}{2}{3}{4} {5}.{6}", 
                Convert.ToChar(rnd.Next('A', 'Z')),
                Convert.ToChar(rnd.Next('a', 'z')),
                Convert.ToChar(rnd.Next('a', 'z')),
                Convert.ToChar(rnd.Next('a', 'z')),
                name, 
                Convert.ToChar(rnd.Next('A', 'Z')), 
                Convert.ToChar(rnd.Next('A', 'Z')));
        }
        public int GetRandInt(int v0, int v1)
        {
            return rnd.Next(v0, v1);
        }
        public char GetRandChar(char v0, char v1)
        {
            return Convert.ToChar(rnd.Next(v0, v1));
        }
        public string GetRandFixInt(int n, int v0, int v1)
        {
            return String.Format("{0:D" + n + "}", rnd.Next(v0, v1));
        }
        public string GetFixLongStr(long n, long v0)
        {
            return String.Format("{0:D" + n + "}", v0);
        }
    }
}
