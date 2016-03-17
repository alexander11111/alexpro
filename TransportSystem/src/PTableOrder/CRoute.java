package PTableOrder;

import java.util.Vector;

import PCity.CCity;
import PTypes.CCityMesage;

public class CRoute {
	private Vector<CCity> mRout;
	private String strName;
	public CRoute(){
		mRout = new Vector<CCity>();
	}
	public CRoute(CRoute pR){
		mRout = new Vector<CCity>();
		load(pR);
	}
	public CRoute(Vector<CCity> pR){
		mRout = new Vector<CCity>(pR);
	}
	public CRoute(CCityMesage mDC,CCityMesage mAC){
		mRout = new Vector<CCity>();
		mRout.add(new CCity(mDC));
		mRout.add(new CCity(mAC));
	}
	public Vector<CCity> getContainer(){
		return mRout;
	}
	public void load(CRoute pR){
		mRout  = (Vector<CCity>)pR.getContainer();
	}
	public void addPoint(CCity pC){
		mRout.add(pC);
	}
	public void clearRout(){
		mRout.clear();
	}
	public CCity getFirstPoin(){
		return mRout.firstElement();
	}
	public CCity getEndPoin(){
		return mRout.lastElement();
	}
	public double getDistance(){
		try{
		return getFirstPoin().getDistance(getEndPoin());
		}catch(Exception e){
		 return 0;	
		}
	}
	public double getTimeOfRoad(double Speed){
		if(Speed==0)return 0;
		if(Speed>0)return getDistance()/Speed;
		return 0;
	}
	public String getRoutInfo(){
		String str = new String();
		for(int i=0;i<mRout.size();i++){
			str = str +"("+i+")"+ mRout.elementAt(i).getCityInfo();
		}
		return str;
	}
}
