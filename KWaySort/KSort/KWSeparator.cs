using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace KSort
{
    class KWSeparator
    {
        private String srcFile;
        private int nCount;
        private long idx=0;
        private IFirstSorter iFSorter;
        public long LineCount { get { return nCount*idx; } }
        public KWSeparator(String sFile,int nCount,IFirstSorter iFirstSorter)
        {
            this.srcFile = sFile;
            this.nCount = nCount;
            this.iFSorter = iFirstSorter;
        }
        public KWChankPull Start()
        {
            int ID = 0;
            String strFile = String.Empty;
            KWChankPull pull = new KWChankPull();
            idx = GetChankCount();
            using (StreamReader sr = new StreamReader(new FileStream(srcFile, FileMode.Open, FileAccess.Read, FileShare.Read, 8 * 1024)))
            {
                while (GetChank(sr, idx) == true)
                {
                    iFSorter.Sort();
                    pull.AddChank(ID);
                    //pull.SaveLines(ID,iFSorter);
                    pull.SaveBufferedLines(ID, iFSorter);
                    Console.WriteLine("({0})Created Chank {1} of {2}", GetType().Name, ID, nCount);
                    ID++;
                };
                pull.Open();
                return pull;
            }
        }
        private bool GetChank(StreamReader sr, long idx)
        {
            try
            {
                iFSorter.Clear();
                String line = String.Empty;
                for (int i = 0; i < idx; i++)
                {
                    if ((line = sr.ReadLine()) != null)
                        iFSorter.Add(new SortEntity(line));
                    else
                        break;
                }
                if (iFSorter.Count == 0) return false;
            }
            catch { return false; }
            return true;
        }
        
        private long GetChankCount()
        {
            using (StreamReader sr = new StreamReader(new FileStream(srcFile, FileMode.Open, FileAccess.Read, FileShare.Read, 8 * 1024)))
            {
                String line = sr.ReadLine();
                long len = sr.BaseStream.Length;
                double nLines = (double)len / (double)(line.Length);
                return (long)(nLines / nCount);
            }
        }
       
    }
}
