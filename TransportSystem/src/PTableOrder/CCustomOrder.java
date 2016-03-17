package PTableOrder;

import java.sql.Time;
import java.util.Date;

import CConstant.CConst;
import PTransport.IFListener;
import PTransport.IFTransport;
import PTransported.IFTransported;

public class CCustomOrder implements IFListener {
	   private String strNumber;
	   private String strDocName;
	   private String strTripsNameID;
	   private Date dtDateReg;
	   private IFTransported ifTransd;
	   private IFTransport ifTran;
	   private CRoute nRout;
	   
	   private double nDistance;
	   private double nCoast;
	   private double nSpeed;
	   private double dtTimeOfRoad;
	   private int    nState;
	   public CCustomOrder(String strNumber,
			               String strDocName,
			               String strTripsNameID,
			               IFTransported ifTransd,
			               IFTransport ifTran,
			               CRoute nRout,
			               int nState){
		   this.strNumber      = strNumber;
		   this.strDocName     = strDocName;
		   this.strTripsNameID = strTripsNameID;
		   this.dtDateReg      = new Date();
		   this.ifTransd       = ifTransd;
		   this.ifTran         = ifTran;
		   this.nRout          = nRout;
		   
		   this.nDistance   = nRout.getDistance();
		   this.nCoast      = nDistance*ifTran.getCost();
		   this.nSpeed      = ifTran.getSpeed();
		   this.dtTimeOfRoad= nDistance/nSpeed;
		   this.nState      = nState;		   
	   }
	public boolean checkMoney(){
		return (ifTransd.getMoney()>nCoast);
	}
    //@SuppressWarnings("deprecation")
	public String getInfo(){
    	return  getStateToString()+"Order ¹"+getDocID()+
    			"\n"+getStateToString()+"Name:"+strDocName+
    			"\n"+getStateToString()+"Trips Name:"+strTripsNameID+
    			"\n"+getStateToString()+"Date Reg:"+dtDateReg.toLocaleString()+
    			"\n"+getStateToString()+" Transport:"+ifTran.getTransInfo()+
    			"\n"+getStateToString()+"Transd:"+ifTransd.getCargoParam()+
    			"\n"+getStateToString()+"Rout:"+nRout.getRoutInfo()+
    			"\n"+getStateToString()+"Dep Time:"+nRout.getFirstPoin().getDepDate()+
    			"\n"+getStateToString()+"Arr Time:"+nRout.getEndPoin().getArrDate()+
    			"\n"+getStateToString()+"Distance:"+nRout.getDistance()+" km."+
    			"\n"+getStateToString()+"Speed:"+nSpeed+" km/h"+
    			"\n"+getStateToString()+"Coast:"+nCoast+
    			"\n"+getStateToString()+"Time Of Road:"+dtTimeOfRoad+" h";
    }
	public String getShortInfo(){
		if (checkMoney()==false)nState = CConst.COLOWMONEY;
    	return  
    			"\n"+getStateToString()+" Trips Name:"+strTripsNameID+
    			"\n"+getStateToString()+" Transport:"+ifTran.getTransInfo()+
    			"\n"+getStateToString()+" Transported:"+ifTransd.getCargoParam()+
    			"\n"+getStateToString()+" Rout:"+nRout.getRoutInfo()+
    			"\n"+getStateToString()+" Distance:"+nRout.getDistance()+" km."+
    			"\n"+getStateToString()+" Speed:"+nSpeed+" km/h"+
    			"\n"+getStateToString()+" Coast:"+nCoast+
    			"\n"+getStateToString()+" Time Of Road:"+dtTimeOfRoad+" h";
    }
    public void setState(int nState){
    	this.nState = nState;
    }
    public int getIntState(){
    	return nState;
    }
    public void getStringState(){
    	CConst.trace(getState());
    	CConst.trace(getInfo());
    }
    public String getState(){
    	return  getStateToString()+"Order ¹"+getDocID()+
   			 " Doc Name:"+strDocName+
   	         " Transd:"+ifTransd.getCargoParam();
    }
    private String getDocID(){
    	return strNumber+"/"+ifTransd.getCargoID()+"/"+ifTransd.getCargoTypeID();
    }
    public String getStateToString(){
		switch(nState){
	    case CConst.COFREE:
	    	 return  "("+getDocID()+")(FREE)";
		case CConst.COINDEPPOINT:
			 return  "("+getDocID()+")(DEPPOINT)";		
		case CConst.COINROAD:
			 return  "("+getDocID()+")(INROAD)";		
		case CConst.COINARRPOINT:
			 return  "("+getDocID()+")(ARRPOINT)";		
		case CConst.COLOWMONEY:
			 return  "("+getDocID()+")(ERR LOW MONEY)";	
		case CConst.CONOPLACE:
			 return  "("+getDocID()+")(ERR NO PLACE)";		
		case CConst.CODEPARTURES:
			 return  "("+getDocID()+")(DEPARTURES)";	
	}
		return "CCustomOrder::>UNKNOWN STATE!";
    }
    public void sendSignal(int nCode){
	      setState(nCode);
	      CConst.trace(getState());
	      CConst.trace(getInfo());
    }
	@Override
	public void eventHappens(int ID,int nCode,String str) {
		// TODO Auto-generated method stub
		switch(nCode)
		{
		case CConst.COINDEPPOINT:
		     //if (str.equals(getDocID()))
		     //{
		      setState(nCode);
		      CConst.trace(getState());
		      CConst.trace(getInfo());
		     //}
		break;
		case CConst.COINARRPOINT:
			  setState(nCode);
			  CConst.trace(getState());
		break;
		case CConst.CODEPARTURES:
			  setState(nCode);
			  CConst.trace(getState());
		break;
		}
	}
}
