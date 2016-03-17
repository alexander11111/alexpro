package PTransported;

import PTypes.CCargoMsg;

public class CCargo extends CCTransported {
	CCargoMsg pTbl;
    public CCargo(CCargoMsg pTbl){
    	this.pTbl   = pTbl;
        ID          = pTbl.ID; 
        cargoID     = pTbl.cargoID; 
        cargoTypeID = pTbl.cargoTypeID;
        Money       = pTbl.Money;
    }
    public double getTransParam(){
    	return getWeigt();
    }
    public double getWeigt(){
    	return (pTbl.volume*pTbl.dense);
    }
    @Override
    public String getCargoParam(){
    	return "("+cargoID+")Cargo::>Ownwer '"+pTbl.strOwnerName+"' Name:'"+pTbl.strName+"' Vol:"+pTbl.volume+" Dens:"+pTbl.dense+"Weigt:"+getWeigt()+" Money:"+pTbl.Money;
    }
}
