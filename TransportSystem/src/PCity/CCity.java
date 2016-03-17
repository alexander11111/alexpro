package PCity;

import PTypes.CCityMesage;


public class CCity {
	CCityMesage pCM;
    private CPort mPort;
    private CPoint mPoint;
    public CCity(CCityMesage nCM){
    	 //pCM    = new CCityMesage();
    	 pCM    = nCM;
    	 mPort  = new CPort(pCM.isAir,pCM.isAut,pCM.isTrain,pCM.isWath);
    	 mPoint = new CPoint(pCM.X,pCM.Y);
	 }
     public int getX(){return mPoint.getX();}
     public int getY(){return mPoint.getY();}
     public String getDepDate(){return pCM.depDate.toString();}
     public String getArrDate(){return pCM.arrDate.toString();}
     public CPoint getmPoint(){
    	 return mPoint;
     }
     public int getID(){
    	 return pCM.codeID;
     }
     public int getDistance(CCity nC){
    	 return (int) Math.sqrt(Math.pow(getX()-nC.getX(),2)+Math.pow(getY()-nC.getY(),2));
     }
     public boolean isTruePort(int nID){
    	    return mPort.getPort(nID); 
     }
     public boolean equals(CCity pC){
    	 return mPoint.equals(pC.getmPoint());
     }
     public boolean equals(CPoint pC){
    	 return mPoint.equals(pC);
     }
     public String getName(){
    	 return pCM.strName; 
     }
     public String getCityInfo(){
    	 return "("+pCM.ID+")CCity::>Name: '"+getName()+"' Point: '"+mPoint.getPointInfo()+"' Ports: "+mPort.getPortInfo()+"'"; 
     }
}
