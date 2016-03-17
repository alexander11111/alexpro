using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace KSort
{
    public delegate void SortProcess(double proc);
    class KWSorter
    {
        private String srcFile;
        private String dstFile;
        private KWSeparator sSeparator;
        private KWChankPull pull;
        private IMiddleSorter iMidlSorter;
        private KeyEntity keyData;
        public SortProcess SProcess { get; set; }
        public KWSorter(String srcFile, String dstFile, int chank, IFirstSorter iFirstSorter, IMiddleSorter iMidlSorter)
        {
            sSeparator = new KWSeparator(srcFile, chank, iFirstSorter);
            this.iMidlSorter = iMidlSorter;
            this.dstFile = dstFile;
            this.srcFile = srcFile;
        }
        public void Sort()
        {
            Separation();
            ClearOutFile();
            SortFile();
            ClearTmpFiles();
        }
        private void SortFile()
        {
            long i = 0;
            using (StreamWriter sr = new StreamWriter(new FileStream(dstFile, FileMode.OpenOrCreate, FileAccess.Write, FileShare.Write, 8 * 1024)))
            {
                while ((keyData = GetSortedData()) != null)
                {
                    SendToFile(sr, keyData);
                    //Statistic
                    if ((SProcess != null) && ((i++ % 10000) == 0)) SProcess(100.0 * ((double)i / sSeparator.LineCount));
                }
                //Statistic
                if (SProcess != null) SProcess(100.0);
            }
        }
        private void Separation()
        {
            pull = sSeparator.Start();
        }
        private KeyEntity GetSortedData()
        {
            if (iMidlSorter.Count == 0)
                pull.LoadAll(iMidlSorter);
            else
                if (keyData != null)
                    pull.LoadByID(keyData.ID, iMidlSorter);
            return iMidlSorter.Get();
        }
        private void SendToFile(StreamWriter sr,KeyEntity data)
        {
            sr.WriteLine(data.data.ToCSV());
        } 
        private void ClearOutFile()
        {
            if (File.Exists(dstFile) == true) 
                 File.Delete(dstFile);
        }
        private void ClearTmpFiles()
        {
            pull.Close();
        }
    }
}
