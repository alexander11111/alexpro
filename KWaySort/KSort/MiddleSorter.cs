using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KSort
{
    interface IMiddleSorter
    {
        void Add(KeyEntity data);
        KeyEntity Get();
        long Count { get; set; }
        
    }
    class MiddleListSorter : IMiddleSorter
    {
        private List<KeyEntity> dtSorter;
        private KeyEntityComp keyComp = new KeyEntityComp();
        public MiddleListSorter() 
        {
            dtSorter = new List<KeyEntity>();
        }
        public void Add(KeyEntity data)
        {
            dtSorter.Add(data);
        }
        public KeyEntity Get()
        {
            if (dtSorter.Count == 0) return null;
            //Sort
            dtSorter.Sort(keyComp);
            //Get
            KeyEntity item = dtSorter[0];
            //Delete
            dtSorter.Remove(item);
            return item;
        }
        public long Count
        {
            get { return dtSorter.Count; }
            set { Count = value; }
        }
    }
    
    class MiddleSetSorter : IMiddleSorter
    {
        private SortedSet<KeyEntity> dtSorter;
        private KeyEntityComp keyComp = new KeyEntityComp();
        public MiddleSetSorter() 
        {
            dtSorter = new SortedSet<KeyEntity>(keyComp);
        }
        public void Add(KeyEntity data)
        {
            if (dtSorter.Add(data) == false)
            {
                Console.WriteLine("({0})Value is Add Error!", GetType().Name);
            }
        }
        public KeyEntity Get()
        {
            if (dtSorter.Count == 0) return null;
            //Get
            KeyEntity item = dtSorter.Min;
            //Delete
            dtSorter.Remove(item);
            return item;
        }
        public long Count
        {
            get { return dtSorter.Count; }
            set { Count = value; }
        }
    }
    
    class MiddleDicSorter : IMiddleSorter
    {
        private SortedDictionary<MiddleKey, KeyEntity> dtSorter;
        private MiddKeyComp keyComp = new MiddKeyComp();
        public MiddleDicSorter()
        {
            dtSorter = new SortedDictionary<MiddleKey, KeyEntity>(keyComp);
        }
        public void Add(KeyEntity data)
        {
            dtSorter.Add(new MiddleKey(data), data);
        }
        public KeyEntity Get()
        {
            if (dtSorter.Count == 0) return null;
            ICollection<MiddleKey> keys = dtSorter.Keys;
            MiddleKey key = keys.First();
            KeyEntity item = dtSorter[key];
            dtSorter.Remove(key);
            return item;
        }
        public long Count
        {
            get { return dtSorter.Count; }
            set { Count = value; }
        }
    }
}
