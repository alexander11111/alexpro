package PTableOrder;

import java.util.Date;
import java.util.Vector;

import CConstant.CConst;
import PCity.CCity;
import PCity.CPoint;
import PDataBase.CDBDriver;
import PTransport.CAListener;
import PTransport.IFListener;
import PTransport.IFTransport;
import PTransported.CCargo;
import PTransported.CPassenger;
import PTransported.IFTransported;
import PTypes.CCityMesage;
import PTypes.CPassengerMsg;
import PTypes.CTripsMsg;

public class CTrips extends CAListener {
	  private CTripsMsg pTrips;
	  private IFTransport ifTran;
      private CRoute mRout;
      private boolean isRun;
      private Vector<IFTransported> ifCargo;
      private Vector<IFTransported> ifMan;
      public CTrips(CTripsMsg pTrips,IFTransport ifTran,CRoute pRout){
    	  this.pTrips    = pTrips;
    	  this.mRout     = new CRoute(pRout);
    	  this.ifTran    = ifTran;
    	  ifCargo        = new Vector<IFTransported>();
    	  ifMan          = new Vector<IFTransported>();
    	  isRun          = false;
    	  CConst.trace("("+pTrips.ID+")CTrips::>>Create");
      }
      //public 
      public int getDepCityID(){
    	  return pTrips.depCityID;
      }
      public int getArrCityID(){
    	  return pTrips.arrCityID;
      }
      public int getID(){
    	  return pTrips.ID;
      }
      public String getTripsNo(){
    	  return pTrips.strNumber;
      }
      public int getType(){
    	  return pTrips.TypeID;
      }
      public boolean checkColumn(IFTransported ifTrans){
    	  return (ifTrans.getTransParam()>ifTran.getCargoCapacity());
      }
      public int getTripsCount(IFTransported ifTrans){
    	  if(ifTrans.getTransParam()==ifTran.getCargoCapacity()) return 1; else
    	  return (int)(ifTrans.getTransParam()/ifTran.getCargoCapacity())+1;
      }
      public boolean chechCargosType(){
    	  return ((getType()==CConst.AUTOC)||
    			  (getType()==CConst.AIRC)||
    			  (getType()==CConst.TRAIC)||
    			  (getType()==CConst.WATC));
      }
      public boolean chechPassType(){
    	  return ((getType()==CConst.AUTOP)||
    			  (getType()==CConst.AIRP)||
    			  (getType()==CConst.TRAIP)||
    			  (getType()==CConst.WATP));
      }
      public boolean checkCatroType(int nID){
    	  if (nID==0) return chechCargosType();
    	  if (nID==1) return chechPassType();
    	  return false;
      }
      public String getTripsInfo(){
    	  return "("+pTrips.ID+")("+CConst.getCaroStrID(pTrips.TypeID)+")("+pTrips.strNumber+") Name:"+pTrips.strName+" Transport:"+ifTran.getTransInfo()+
    			 " Rout:"+mRout.getRoutInfo()+
    			 " depDate:"+pTrips.depDate.toString()+
    			 " arrDate:"+pTrips.arrDate.toString();
      }
      public CCustomOrder load(IFTransported ifTrans)
      {
    	  if ((ifTrans instanceof CCargo)==true)
    	  { 
    		  if (checkMoney(ifTrans)==false) return getPasDocument(ifTrans,CConst.COLOWMONEY);
    		  if (loadCargo(ifTrans)==true)
    		  {
      			 CCustomOrder pC = getPasDocument(ifTrans,CConst.COINDEPPOINT);
      			 addEventListener(pC);
      			 pC.sendSignal(CConst.COINDEPPOINT);
     			 return pC;
    		  }else return getPasDocument(ifTrans,CConst.CONOPLACE);
    	  }else
    	  if ((ifTrans instanceof CPassenger)==true)
    	  {
    		  if (checkMoney(ifTrans)==false) return getPasDocument(ifTrans,CConst.COLOWMONEY);
    		  if (loadMan(ifTrans)==true)
    		  {
      			 CCustomOrder pC = getPasDocument(ifTrans,CConst.COINDEPPOINT);
      			 addEventListener(pC);
      			 pC.sendSignal(CConst.COINDEPPOINT);
     			 return pC;
    		  }else return getPasDocument(ifTrans,CConst.CONOPLACE);
    	  }
    	  return null;
      }
      private boolean checkMoney(IFTransported ifTrans){
    	  return (ifTrans.getMoney()>ifTran.getCost()*mRout.getDistance());
      }
      private CCustomOrder getCargoDocument(IFTransported ifTrans){
    	  return (new CCustomOrder(pTrips.strNumber,
    			  "'Ticket Transfers'",
    			  pTrips.strName,
    			  ifTrans,
    			  ifTran,
    			  mRout,
    			  CConst.COINDEPPOINT
    			  ));
      }
      private CCustomOrder getPasDocument(IFTransported ifTrans,int nState){
    	  return (new CCustomOrder(pTrips.strNumber,
    			  "'Ticket Travel'",
    			  pTrips.strName,
    			  ifTrans,
    			  ifTran,
    			  mRout,
    			  nState
    			  ));
      }
      public CCustomOrder getCheckDocument(IFTransported ifTrans,IFTransport ifTr){
    	  return (new CCustomOrder(pTrips.strNumber,
    			  "'Check Notify'",
    			  pTrips.strName,
    			  ifTrans,
    			  ifTr,
    			  mRout,
    			  0
    			  ));
      }
      private boolean loadMan(IFTransported ifTrans){
    	  if (ifTran.loadMan(ifTrans)) {
    		  ifMan.add(ifTrans);
    		  return true;
    	  }
    	  return false;
      }
      private boolean loadCargo(IFTransported ifTrans){
    	  if (ifTran.loadCargo(ifTrans))    	  {
    		  ifCargo.add(ifTrans);
    		  return true;
    	  }
    	  return false;
      }
      public void arrival(){
    	  if(isRun==true){
    	  isRun = false; 
    	  ifTran.arrival();	  
    	  riseSomeEvent(CConst.CUNLOAD,CConst.COINARRPOINT,"");
    	  evListeners.clear();
    	  ifCargo.clear();
    	  ifMan.clear();
    	  }
      }
      public void departures(){
    	  if(isRun==false){
    	   isRun = true; 
    	   riseSomeEvent(CConst.CUNLOAD,CConst.CODEPARTURES,"");
    	  }
      }
      //Get From GPS system
      public void run(CPoint pC){
    	  if (isRun==true)
    	  if (mRout.getEndPoin().equals(pC))
    	  {
    		  arrival();
    		  ifCargo.clear();
    		  ifMan.clear();
    		  isRun = false;
    	  }
      }
}
