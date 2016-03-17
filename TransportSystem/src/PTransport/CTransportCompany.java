package PTransport;


import java.util.Vector;

import PTypes.CTransCompanyMsg;

public class CTransportCompany {
	   private CTransCompanyMsg pTbl;
       private Vector<IFTransport> vTran;
       public CTransportCompany(CTransCompanyMsg pTbl){
    	   this.pTbl = pTbl;
    	   vTran = new Vector<IFTransport>();
       }
       public Vector<IFTransport> getCont(){
    	   return vTran;
       }
       public void clear(){
    	   vTran.clear(); 
       }
       public void addTransport(IFTransport ifTran){
    	   vTran.add(ifTran);
       }
       public String getCompanyInfo(){
		String strInfo;
		strInfo = "("+pTbl.nTransCoID+")"+" Trans Co Name:"+pTbl.strName+" LicNo:"+pTbl.strLicNo;
		for (IFTransport pT:vTran){
			strInfo = strInfo + "\n("+pTbl.nTransCoID+")"+pT.getTransInfo();	
		}
		return strInfo;
 	   }
}
