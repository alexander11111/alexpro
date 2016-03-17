package PCity;

import CConstant.CConst;

public class CPort {
    private boolean isPort[];
    public CPort(boolean isAirport,boolean isAutoPort,boolean isTrainPort,boolean isWaterPort){
    	isPort = new boolean[4];
    	isPort[CConst.AIRPORT]  = isAirport; 
    	isPort[CConst.AUTOPORT] = isAutoPort; 
    	isPort[CConst.TRAINPORT]= isTrainPort; 
    	isPort[CConst.WATERRPORT]= isWaterPort; 
    }
    public boolean getPort(int pID){
    	return isPort[pID];
    }
    public String getPortInfo(){
    	return "AIRPORT: "+isPort[CConst.AIRPORT]+
    		   " AUTOPORT: "+isPort[CConst.AUTOPORT]+
    		   " TRAINPORT "+isPort[CConst.TRAINPORT]+
    		   " WATERRPORT: "+isPort[CConst.WATERRPORT];
    }
}
