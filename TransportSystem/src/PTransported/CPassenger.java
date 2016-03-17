package PTransported;

import PTypes.CPassengerMsg;

public class CPassenger extends CCTransported {
	  CPassengerMsg pTbl;
      public CPassenger(CPassengerMsg pTbl){
    	 this.pTbl   = pTbl;
         ID          = pTbl.ID; 
         cargoID     = pTbl.cargoID; 
         cargoTypeID = pTbl.cargoTypeID;
         Money       = pTbl.Money;
      }
      public double getTransParam(){
      	return Money;
      }
      public String setFIO(){
    	  return pTbl.sFam+" "+pTbl.sImya+" "+pTbl.sOtch;
      }
      @Override
      public String getCargoParam(){
      	return "("+cargoID+")CPassenger::>"+setFIO()+" Money:"+Money;
      }

}
