package src;
import java.util.Vector;
import com.siemens.icm.misc.Watchdog;
public class CAlarmThread extends Thread  {
	private long  lTime; 
	private Vector alObj;
	private ISomeEventListener ifObj;
	private boolean blStart;
	private long lCount=0;
	CAlarmThread(int lTime){
		this.lTime = lTime;
		alObj   = new Vector();
		setPriority(NORM_PRIORITY);
		Watchdog.start(2*60);
		MySuspend();
	}
	synchronized public void MySuspend(){
		blStart = true; 
	}
	synchronized public long getCount(){
		return lCount;
	}
	synchronized public void MyRessume(){
		blStart = false; 
	}
	public void addObj(Object obj){
		alObj.addElement(obj);
	}
	public void clearObj(Object obj){
		alObj.removeAllElements();
	}
	public Vector getObjects(){
		return alObj;
	}

	public void run() {
        // compute primes larger than minPrime
		try
		{
			//Watchdog
	         //Watchdog.start(3600);
			 while(true)
			 {
			  //while(blStart) wait();
			  for(int i=0;i<alObj.size();i++)
			  ((ISomeEventListener)alObj.elementAt(i)).RunProc();
			  sleep(lTime);
			  Watchdog.kick();
			  lCount++;
			}
		}catch(InterruptedException e){
			System.out.println("CAlarmThread::>InterruptedException:"+e.getMessage());
		}
		
    }
}
