using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KSort
{
    class MiddleKey
    {
        public String ID;
        public String RegionNo;
        public String CollTimeSec;
        public MiddleKey(KeyEntity data)
        {
            ID = data.data.ID;
            RegionNo = data.data.RegionNo;
            CollTimeSec = data.data.CollTimeSec;
        }
        public MiddleKey(SortEntity data)
        {
            ID = data.ID;
            RegionNo = data.RegionNo;
            CollTimeSec = data.CollTimeSec;
        }
    }
    public class MiddKeyComp : IComparer<MiddleKey>
    {
        int IComparer<MiddleKey>.Compare(MiddleKey x, MiddleKey y)
        {
            int IDX = Convert.ToInt32(x.ID);
            int IDY = Convert.ToInt32(y.ID);
            int RegNoX = Convert.ToInt32(x.RegionNo);
            int RegNoY = Convert.ToInt32(y.RegionNo);
            int CollX = Convert.ToInt32(x.CollTimeSec);
            int CollY = Convert.ToInt32(y.CollTimeSec);
            if ((RegNoX > RegNoY)) return 1;
            if ((RegNoX == RegNoY))
            {
                if ((CollX > CollY)) return 1;
                if ((CollX == CollY))
                {
                    if ((IDX > IDY)) return 1;
                    if ((IDX == IDY)) return 0;
                    if ((IDX < IDY)) return -1;
                }
                if ((CollX < CollY)) return -1;
            }
            if ((RegNoX < RegNoY)) return -1;
            return 0;
        }
    }
    public class SortKeyComp : IComparer<SortEntity>
    {
        int IComparer<SortEntity>.Compare(SortEntity x, SortEntity y)
        {
            int IDX = Convert.ToInt32(x.ID);
            int IDY = Convert.ToInt32(y.ID);
            int RegNoX = Convert.ToInt32(x.RegionNo);
            int RegNoY = Convert.ToInt32(y.RegionNo);
            int CollX = Convert.ToInt32(x.CollTimeSec);
            int CollY = Convert.ToInt32(y.CollTimeSec);
            if ((RegNoX > RegNoY)) return -1;
            if ((RegNoX == RegNoY))
            {
                if ((CollX > CollY)) return -1;
                if ((CollX == CollY))
                {
                    if ((IDX > IDY)) return -1;
                    if ((IDX == IDY)) return 0;
                    if ((IDX < IDY)) return 1;
                }
                if ((CollX < CollY)) return 1;
            }
            if ((RegNoX < RegNoY)) return 1;
            return 0;
        }
    }
    public class PQKeyComp : IComparer<MiddleKey>
    {
        int IComparer<MiddleKey>.Compare(MiddleKey x, MiddleKey y)
        {
            int IDX = Convert.ToInt32(x.ID);
            int IDY = Convert.ToInt32(y.ID);
            int RegNoX = Convert.ToInt32(x.RegionNo);
            int RegNoY = Convert.ToInt32(y.RegionNo);
            int CollX = Convert.ToInt32(x.CollTimeSec);
            int CollY = Convert.ToInt32(y.CollTimeSec);
            if ((RegNoX > RegNoY)) return -1;
            if ((RegNoX == RegNoY))
            {
                if ((CollX > CollY)) return -1;
                if ((CollX == CollY))
                {
                    if ((IDX > IDY)) return -1;
                    if ((IDX == IDY)) return 0;
                    if ((IDX < IDY)) return 1;
                }
                if ((CollX < CollY)) return 1;
            }
            if ((RegNoX < RegNoY)) return 1;
            return 0;
        }
    }
    public class KeyEntityComp : IComparer<KeyEntity>
    {
        int IComparer<KeyEntity>.Compare(KeyEntity x, KeyEntity y)
        {
            int IDX = Convert.ToInt32(x.ID);
            int IDY = Convert.ToInt32(y.ID);
            int RegNoX = Convert.ToInt32(x.data.RegionNo);
            int RegNoY = Convert.ToInt32(y.data.RegionNo);
            int CollX = Convert.ToInt32(x.data.CollTimeSec);
            int CollY = Convert.ToInt32(y.data.CollTimeSec);
            if ((RegNoX > RegNoY)) return 1;
            if ((RegNoX == RegNoY))
            {
                if ((CollX > CollY)) return 1;
                if ((CollX == CollY))
                {
                    if ((IDX > IDY)) return 1;
                    if ((IDX == IDY)) return 0;
                    if ((IDX < IDY)) return -1;
                }
                if ((CollX < CollY)) return -1;
            }
            if ((RegNoX < RegNoY)) return -1;
            return 0;
        }
    }
    class KeyEntity 
    {
        public int ID {get;set;}
        public SortEntity data { get; set; }
        public KeyEntity(int ID, SortEntity data)
        {
            this.ID = ID;
            this.data = data;
        }
    }
    public class EntityComp : IComparer<SortEntity>
    {
        int IComparer<SortEntity>.Compare(SortEntity x, SortEntity y)
        {
            int IDX = Convert.ToInt32(x.ID);
            int IDY = Convert.ToInt32(y.ID);
            int RegNoX = Convert.ToInt32(x.RegionNo);
            int RegNoY = Convert.ToInt32(y.RegionNo);
            int CollX = Convert.ToInt32(x.CollTimeSec);
            int CollY = Convert.ToInt32(y.CollTimeSec);
            if ((RegNoX > RegNoY)) return 1;
            if ((RegNoX == RegNoY))
            {
                if ((CollX > CollY)) return 1;
                if ((CollX == CollY))
                {
                    if ((IDX > IDY)) return 1;
                    if ((IDX == IDY)) return 0;
                    if ((IDX < IDY)) return -1;
                }
                if ((CollX < CollY)) return -1;
            }
            if ((RegNoX < RegNoY)) return -1;
            return 0;
        }
    }
    class SortEntity
    {
        public String ID;
        public String Account;
        public String SrcNumber;
        public String RegionNo;
        public String CollTimeSec;
        public String DscNumber;
        public String Action;
        public SortEntity()
        {
          ID = "";
          Account = "";
          SrcNumber = "";
          RegionNo = "";
          CollTimeSec = "";
          DscNumber = "";
          Action = "";
        }
        public SortEntity(String line)
        {
             ToEntity(line);
        }
        public String ToCSV()
        {
            return String.Format("{0};{1};{2};{3};{4};{5};{6}", ID,Account, SrcNumber, RegionNo, CollTimeSec, DscNumber, Action);
        }
        public SortEntity ToEntity(String strCSV)
        {
            String[] str = strCSV.Split(';');
            for (int i = 0; i < str.Length; i++)
            {
                switch (i)
                {
                    case 0: this.ID = str[i]; break;
                    case 1: this.Account = str[i]; break;
                    case 2: this.SrcNumber = str[i]; break;
                    case 3: this.RegionNo = str[i]; break;
                    case 4: this.CollTimeSec = str[i]; break;
                    case 5: this.DscNumber = str[i]; break;
                    case 6: this.Action = str[i]; break;
                }
            }
            return this;
        }
    }
}
