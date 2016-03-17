using Sinbadsoft.Lib.Collections;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KSort
{
    interface IFirstSorter
    {
        void Sort();
        void Add(SortEntity value);
        int Count { get; }
        void Clear();
        void Flush(StreamWriter sr);
        void FlushBuffered(String strName);
    }
    class FirstListSorter : IFirstSorter
    {
        private List<SortEntity> data;
        public int Count
        {
            get
            {
                return data.Count;
            }
        }
        public FirstListSorter()
        {
            data = new List<SortEntity>();
        }

        public void Sort()
        {
            data.Sort(new EntityComp());
        }
        public void Clear()
        {
            data.Clear();
        }
        public void Add(SortEntity value)
        {
            data.Add(value);
        }
        public void Flush(StreamWriter sr)
        {
            foreach (var item in data)
                sr.WriteLine(item.ToCSV());
        }
        public void FlushBuffered(String strName)
        {
            StringBuilder sb = new StringBuilder();
            long nLen = 0, nLen0 = 0;
            foreach (var item in data)
            {
                sb.Append(item.ToCSV() + "\n");
                nLen0++; nLen++;
                if ((nLen == 50000) || (nLen0 == data.Count))
                {
                    File.AppendAllText(strName, sb.ToString());
                    sb.Clear();
                    nLen = 0;
                }
            }
        }
    }
    class FirstSetSorter : IFirstSorter
    {
        private SortedSet<SortEntity> data;
        public int Count
        {
            get 
            { 
                return data.Count; 
            }
        }
        public FirstSetSorter() 
        {
            data = new SortedSet<SortEntity>(new EntityComp());
        }
       
        public void Sort()
        {
           
        }
        public void Clear()
        {
            data.Clear();
        }
        public void Add(SortEntity value)
        {
            data.Add(value);
        }
        public void Flush(StreamWriter sr)
        {
            foreach (var item in data)
                sr.WriteLine(item.ToCSV());
        }
        public void FlushBuffered(String strName)
        {
            StringBuilder sb = new StringBuilder();
            long nLen = 0, nLen0 = 0;
            foreach (var item in data)
            {
                sb.Append(item.ToCSV() + "\n");
                nLen0++; nLen++;
                if ((nLen == 50000) || (nLen0 == data.Count))
                {
                    File.AppendAllText(strName, sb.ToString());
                    sb.Clear();
                    nLen = 0;
                }
            }
        }
    }
    class FirstPQSorter : IFirstSorter
    {
        private PriorityQueue<SortEntity> data;
        public int Count
        {
            get
            {
                return data.Count;
            }
        }
        public FirstPQSorter()
        {
            data = new PriorityQueue<SortEntity>(new SortKeyComp());
        }
        public void Sort()
        {

        }
        public void Clear()
        {
            data.Clear();
        }
        public void Add(SortEntity value)
        {
            data.Enqueue(value);
        }
        public void Flush(StreamWriter sr)
        {
            while (data.Count != 0)
            {
                SortEntity item = data.Dequeue();
                sr.WriteLine(item.ToCSV());
            }
        }
        public void FlushBuffered(String strName)
        {
            StringBuilder sb = new StringBuilder();
            long nLen = 0;
            while (data.Count != 0)
            {
                SortEntity item = data.Dequeue();
                sb.Append(item.ToCSV() + "\n");
                if ((nLen++ == 50000) || (data.Count == 0))
                {
                    File.AppendAllText(strName, sb.ToString());
                    sb.Clear();
                    nLen = 0;
                }
            }
        }
    }
    class FirstPQKeySorter : IFirstSorter
    {
        private PriorityQueue<MiddleKey,SortEntity> data;
        public int Count
        {
            get
            {
                return data.Count;
            }
        }
        public FirstPQKeySorter()
        {
            data = new PriorityQueue<MiddleKey, SortEntity>(new PQKeyComp());
        }
        public void Sort()
        {

        }
        public void Clear()
        {
            data.Clear();
        }
        public void Add(SortEntity value)
        {
            data.Enqueue(new MiddleKey(value), value);
        }
        public void Flush(StreamWriter sr)
        {
            while (data.Count != 0)
            {
                KeyValuePair<MiddleKey, SortEntity> item = data.Dequeue();
                sr.WriteLine(item.Value.ToCSV());
            }
        }
        public void FlushBuffered(String strName)
        {
            StringBuilder sb = new StringBuilder();
            long nLen = 0;
            while (data.Count != 0)
            {
                KeyValuePair<MiddleKey, SortEntity> item = data.Dequeue();
                sb.Append(item.Value.ToCSV() + "\n");
                if ((nLen++ == 50000) || (data.Count == 0))
                {
                    File.AppendAllText(strName, sb.ToString());
                    sb.Clear();
                    nLen = 0;
                }
            }
        }
    }
}
