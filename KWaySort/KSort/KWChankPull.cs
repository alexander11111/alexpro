using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace KSort
{
    class KWChankPull
    {
        private Dictionary<int, KWDataSource> pull;
        private String destDir{get;set;}
        public KWChankPull()
        {
            pull = new Dictionary<int, KWDataSource>();
            destDir = Directory.GetCurrentDirectory() + "\\Temp";
            CreateTmpDir();
            ClearTmpFiles();
        }
        public String GetFileName(int ID)
        {
            return String.Format("{0}\\chank_{1}.dat", destDir, ID);
        }
        public String AddChank(int ID)
        {
            pull.Add(ID, new KWDataSource(ID, GetFileName(ID)));
            return GetFileName(ID);
        }
        public void Open()
        {
            foreach (var item in pull)
                item.Value.Open();
        }
        public void Close()
        {
            foreach (var item in pull)
                item.Value.Close();
        }
        public void LoadAll(IMiddleSorter iMidlSorter)
        {
            foreach (var item in pull)
            {
                KeyEntity kE;
                if ((kE = item.Value.GetNext()) != null)
                    iMidlSorter.Add(kE);
            }
        }
        public void LoadByID(int ID, IMiddleSorter iMidlSorter)
        {
            KeyEntity kE;
            KWDataSource src = pull[ID];
            if ((kE = src.GetNext()) != null)
                iMidlSorter.Add(kE);
        }
        public void CreateTmpDir()
        {
            if (Directory.Exists(destDir) == false)
                Directory.CreateDirectory(destDir);
        }
        public void ClearTmpFiles()
        {
            String[] str = Directory.GetFiles(destDir);
            foreach (var item in str) File.Delete(item);
        }
        public void SaveLines(int ID, IFirstSorter iFSorter)
        {
            using (StreamWriter sr = new StreamWriter(new FileStream(GetFileName(ID), FileMode.OpenOrCreate, FileAccess.Write, FileShare.Write, 8 * 1024)))
            {
                iFSorter.Flush(sr);
            }
        }
        public void SaveBufferedLines(int ID, IFirstSorter iFSorter)
        {
            iFSorter.FlushBuffered(GetFileName(ID));
        }
       
    }
}
