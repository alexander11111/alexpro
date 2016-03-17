package PTransport;

import java.util.Vector;

public class CAListener {
	protected Vector<IFListener> evListeners = new Vector<IFListener>(); 
	public void addEventListener(IFListener listener)
	   {
		evListeners.addElement(listener);
    }
    protected void riseSomeEvent(int ID,int nCode,String str)
	{
	    for(int i = 0; i < evListeners.size(); i++)
	    { 
	      ((IFListener)evListeners.elementAt(i)).eventHappens(ID,nCode,str);
	    }
	}
}
