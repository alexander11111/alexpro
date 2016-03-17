using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace KSort.Generator
{
    class EntityGen:RandGen
    {
        private String strFile;
        private long Len;
        public EntityGen(String strFile, long Len)
        {
            this.strFile = strFile;
            this.Len = Len;
        }
        public void Start()
        {
            using (StreamWriter sr = new StreamWriter(strFile))
            {
                SortEntity data = new SortEntity();
                String srcNo = "";
                String accNo = "";
                for (int i = 0; i < Len; i++)
                {
                    if ((i % GetRandInt(1,3) == 0))
                    {
                        srcNo = "+375" + GetRandInt(44, 99) + GetRandInt(1000000, 9000000);
                        accNo = GetRandFio("acc") + "_" + srcNo.Substring(7);
                    }
                    data.ID = GetFixLongStr(8,i);
                    data.Account = accNo;
                    data.SrcNumber = srcNo;
                    data.RegionNo = GetRandFixInt(5,0, 99999);
                    data.CollTimeSec = GetRandFixInt(5,10, 4 * 60 * 60);
                    data.DscNumber = "+375" + GetRandInt(44, 99) + GetRandInt(1000000, 9000000);
                    data.Action = Convert.ToString(GetRandInt(0, 5));
                    sr.WriteLine(data.ToCSV());    
                    if ((i%100000)==0)
                        Console.WriteLine("({0})Created {1}% of {2} lines ", GetType().Name, ((double)i / (double)Len)*100.0,Len);
                }
                
            }
        }
    }
}
