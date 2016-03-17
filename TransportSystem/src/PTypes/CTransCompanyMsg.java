package PTypes;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import PTransported.CCargo;

public class CTransCompanyMsg {
	public CTransCompanyMsg(){
		pTrans = new HashMap<Integer,CTransportMsg>();
	}
	public CTransportMsg getTrans(int nID){
		return pTrans.get(nID);
	}
	public int ID;
	public int nTransCoID;
	public String strName;
	public String strLicNo;
	public HashMap<Integer,CTransportMsg> pTrans;
}
