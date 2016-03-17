using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace KSort
{
    class KWDataSource
    {
        private int ID;
        private String srcFile;
        private StreamReader sr;
        public KWDataSource(int ID,String sFile)
        {
            this.ID = ID;
            this.srcFile = sFile;
        }
        public KeyEntity GetNext()
        {
            String str = String.Empty;
            if ((str = sr.ReadLine()) != null)
                return new KeyEntity(ID, new SortEntity(str));
            return null;
        }
        public void Open()
        {
            sr = new StreamReader(new FileStream(srcFile, FileMode.OpenOrCreate, FileAccess.Read, FileShare.Read, 8 * 1024, FileOptions.DeleteOnClose));
        }
       
        public void Close()
        {
            sr.Close();
        }
    }
}
