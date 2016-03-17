package PTransport;

import CConstant.CConst;
import PTransported.IFTransported;
import PTypes.CTransportMsg;

public abstract class CTransport extends CAListener implements IFTransport {
	   private CTransportMsg pTbl;
	   private double currCargo = 0;
	   private int currPasgr = 0;
	   public CTransport(CTransportMsg pTbl){
		   this.pTbl = pTbl;
	   }
	   @Override
	   public String getName(){return pTbl.strName;}
	   @Override
	   public double getCost()
	   {
		   if(CConst.chechCgType(pTbl.Type)) 
			   return pTbl.costKilogKm; else
			   return pTbl.costKilo;
	   }
	   @Override
	   public double getSpeed()
	   {
		 if(pTbl.speed!=0)return pTbl.speed;
		 if(pTbl.speed==0)return 1;
		 return 1;
	   }
	   @Override
	   public double getCargoCapacity(){return pTbl.cargoCapacity;}
	   @Override
	   public int getPasgrCapacity(){return pTbl.pasgrCapacity;}
       @Override
       public void departures(){
    	   riseSomeEvent(0,0,"("+pTbl.strName+")CTransport:>>departures"); 
       }
       @Override
       public String getTransInfo(){
    	   return "("+pTbl.nTransID+") Name: "+pTbl.strName+
    			  " Kilo/Km: "+pTbl.costKilo+
    			  " Kilog/Km: "+pTbl.costKilogKm+
    			  " speed: "+pTbl.speed+
    			  " cargoCap: "+pTbl.cargoCapacity+
    			  " pasgrCap: "+pTbl.pasgrCapacity+
    	          " Type:"+pTbl.Type;
       }
       @Override
       public void arrival(){
    	   currCargo = 0;
    	   currPasgr = 0;
       }
   	   @Override
   	   public boolean loadMan(IFTransported ifTd) {
   		   // TODO Auto-generated method stub
   		   if (pTbl.pasgrCapacity>currPasgr){
   			currPasgr++;
   			CConst.trace("("+pTbl.nTransID+")CTransport::> Name ("+pTbl.strName+") loading:Man:"+currPasgr+" of "+pTbl.pasgrCapacity+" : "+ifTd.getCargoParam());
   			return true;
   		   } else
   			CConst.trace("("+pTbl.strName+")CTransport:>>Error!!! loading:Man:"+ifTd.getCargoParam());
   		return false;
   	   }
   	   @Override
   	   public boolean loadCargo(IFTransported ifTd) {
   		   // TODO Auto-generated method stub
   		   if (ifTd.getTransParam()>=pTbl.cargoCapacity){
   			currCargo = pTbl.cargoCapacity;
   			CConst.trace("("+pTbl.nTransID+")CTransport::> Name ("+pTbl.strName+")Full loading:Cargo:"+currCargo+" kg. of MAX: "+pTbl.cargoCapacity+" kg. : "+pTbl.cargoCapacity);
   		    currCargo = 0;
   			return true;
   		   }
   		   
   		   if (pTbl.cargoCapacity>=currCargo){
   			currCargo = currCargo + ifTd.getTransParam();
   			CConst.trace("("+pTbl.nTransID+")CTransport::> Name ("+pTbl.strName+") loading:Cargo:"+currCargo+" kg. of MAX: "+pTbl.cargoCapacity+" kg. : "+ifTd.getCargoParam());
   			return true;
   		   }
   		return false;
   	   }
       @Override
       public int getTransUnits(IFTransported ifTd){
    	   double dbParam = ifTd.getTransParam();
    	   if (dbParam==-1)return 1; else
    	   if (dbParam==0) return 0; else
    	   if (pTbl.cargoCapacity>=dbParam) return 1; else
    	   return (int)(pTbl.cargoCapacity/dbParam);
       }
       
}
